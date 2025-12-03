def max_joltage(bank):
    # Find the largest two-digit number from the bank using two digits in order
    digits = [d for d in bank.strip()]
    max_val = 0
    for i in range(len(digits) - 1):
        for j in range(i + 1, len(digits)):
            val = int(digits[i] + digits[j])
            if val > max_val:
                max_val = val
    return max_val


def main():
    total = 0
    with open("puzzle_input.txt") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            total += max_joltage(line)
    print(total)

if __name__ == "__main__":
    main()
