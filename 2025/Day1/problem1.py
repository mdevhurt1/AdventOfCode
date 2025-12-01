def main():
    # Start with the dial pointing at 50
    dial = 50
    # Counter for how many times the dial points at 0 after a rotation
    count_zero = 0
    # Read the input file containing the sequence of rotations
    with open("puzzle_input.txt") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue  # Skip empty lines
            direction = line[0]  # 'L' or 'R'
            value = int(line[1:])  # Number of clicks to rotate
            # Rotate the dial left or right
            if direction == 'L':
                dial = (dial - value) % 100
            elif direction == 'R':
                dial = (dial + value) % 100
            else:
                raise ValueError(f"Unknown direction: {direction}")
            # Check if the dial points at 0 after this rotation
            if dial == 0:
                count_zero += 1
    # Print the final count (the password)
    print(count_zero)

if __name__ == "__main__":
    main()
