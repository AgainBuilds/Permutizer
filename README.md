# Permutizer 

A C++ program that takes a name or word as input, calculates all possible letter arrangements, and identifies real English words from the results.

Built in Week 3 of learning C++

---

## What it does

- Takes a word as user input
- Calculates the total number of possible arrangements using factorial (n!)
- Generates every unique arrangement of the letters
- Loads a 370,000+ word English dictionary
- Outputs only real English words found from the arrangements

---

## How it works

The program uses three core concepts:
- **Factorial calculation** — counts total arrangements (n!)
- **next_permutation** — generates every arrangement systematically
- **unordered_set** — stores the dictionary for O(1) hash table lookup speed

---

## How to use

**Compile:**

g++ permutizer.cpp -o permutizer

**Run:**

./permutizer

**Example:**

Input: CAT

The number of arrangements is: 6

ACT
ATC
CAT
CTA
TAC
TCA

Real English words found:
ACT
CAT

---

## Requirements

- C++ compiler (GCC recommended)
- words_alpha.txt dictionary file in the same folder
- Download dictionary: https://github.com/dwyl/english-words

---

## Built with

- C++ (STL)
- algorithm — sort, next_permutation
- unordered_set — O(1) dictionary lookup
- fstream — file reading

---

## Author

**Again** — AgainBuilds
Started C++: 02/05/2026
github.com/AgainBuilds
