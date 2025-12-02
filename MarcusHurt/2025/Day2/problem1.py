def is_repeated_twice(n):
    # Convert the number to a string
    s = str(n)
    l = len(s)
    # Only consider numbers with even length
    if l % 2 != 0:
        return False
    half = l // 2
    # Check if the first half equals the second half
    return s[:half] == s[half:]


def main():
    # Total sum of all invalid IDs
    total = 0
    # Read the input file containing the ranges
    with open("puzzle_input.txt") as f:
        line = f.read().strip()
        # Split ranges by comma
        ranges = line.split(",")
        for r in ranges:
            if not r:
                continue  # Skip empty entries
            # Each range is in the form start-end
            start, end = map(int, r.split("-"))
            # Check each number in the range
            for n in range(start, end + 1):
                if is_repeated_twice(n):
                    total += n  # Add invalid ID to total
    # Print the final sum of invalid IDs
    print(total)

if __name__ == "__main__":
    main()
