def main():
    # Start with the dial pointing at 50
    dial = 50
    # Counter for how many times the dial points at 0 during any click
    count_zero = 0
    # Read the input file containing the sequence of rotations
    with open("puzzle_input.txt") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue  # Skip empty lines
            direction = line[0]  # 'L' or 'R'
            value = int(line[1:])  # Number of clicks to rotate
            # Determine step direction: left (-1) or right (+1)
            if direction == 'L':
                step = -1
            elif direction == 'R':
                step = 1
            else:
                raise ValueError(f"Unknown direction: {direction}")
            # For each click, move the dial and check if it points at 0
            for i in range(1, value + 1):
                dial = (dial + step) % 100
                if dial == 0:
                    count_zero += 1
    # Print the final count (the password)
    print(count_zero)

if __name__ == "__main__":
    main()
