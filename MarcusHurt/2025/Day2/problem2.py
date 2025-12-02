def is_repeated_at_least_twice(n):
    # Convert the number to a string
    s = str(n)
    l = len(s)
    # Try all possible substring lengths (from 1 up to half the length)
    for sublen in range(1, l // 2 + 1):
        # Only consider substrings that evenly divide the number
        if l % sublen != 0:
            continue
        times = l // sublen
        # Must repeat at least twice
        if times < 2:
            continue
        sub = s[:sublen]
        # Check if repeating the substring forms the number
        if sub * times == s:
            return True
    return False


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
                if is_repeated_at_least_twice(n):
                    total += n  # Add invalid ID to total
    # Print the final sum of invalid IDs
    print(total)

if __name__ == "__main__":
    main()
