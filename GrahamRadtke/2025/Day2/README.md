# Advent of Code 2025 - Day 2 (Graham Radtke)

## Overview
This folder contains solutions for Day 2 of Advent of Code 2025 by Graham Radtke.

- `problem1.cpp`: Solves Part 1, finding and summing all invalid product IDs in the given ranges where the ID is made of a sequence of digits repeated twice (e.g., 1212, 123123).
- `problem2.cpp`: Solves Part 2, finding and summing all invalid product IDs in the given ranges where the ID is made of a sequence of digits repeated at least twice (e.g., 121212, 123123123).
- `puzzle_input.txt`: The input file containing the product ID ranges to check.
- `problem1.txt` and `problem2.txt`: Problem descriptions for each part.

## Usage
Compile each solution with g++ and run in a bash terminal:

```bash
g++ problem1.cpp -o problem1
./problem1 < puzzle_input.txt # Prints the answer for Part 1

g++ problem2.cpp -o problem2
./problem2 < puzzle_input.txt # Prints the answer for Part 2
```

## Answers
- Part 1: 30608905813
- Part 2: 31898925685
