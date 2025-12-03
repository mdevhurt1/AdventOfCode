def max_joltage_12(bank):
    # Find the largest 12-digit number by picking 12 digits in order
    digits = [d for d in bank.strip()]
    # Sort digits in descending order, but keep only the first occurrence in order
    # We need to select 12 digits, keeping their original order
    n = len(digits)
    if n <= 12:
        return int(''.join(digits))
    # Greedy: for each position, pick the largest possible digit that allows enough digits left
    result = []
    start = 0
    for remaining in range(12, 0, -1):
        # Find the max digit in the range start to n - remaining
        max_digit = max(digits[start:n - remaining + 1])
        # Find the first occurrence of max_digit in allowed range
        idx = digits.index(max_digit, start, n - remaining + 1)
        result.append(max_digit)
        start = idx + 1
    return int(''.join(result))


def main():
    total = 0
    with open("puzzle_input.txt") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            total += max_joltage_12(line)
    print(total)

if __name__ == "__main__":
    main()
