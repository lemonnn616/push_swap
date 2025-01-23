# 🔄 push_swap

**push_swap** is a project designed to create a sorting algorithm using two stacks. The objective is to sort a list of integers with the minimum number of operations. This project is part of the 42 School curriculum and focuses on algorithm optimization, data manipulation, and problem-solving.

---

## 🛠️ Features

### **Mandatory Part**
- Implements a program that sorts a stack of integers in ascending order using a second stack and a limited set of operations:
  - `sa`, `sb`, `ss`: Swap the first two elements of a stack.
  - `pa`, `pb`: Push the top element of one stack to another.
  - `ra`, `rb`, `rr`: Rotate a stack (shift all elements up by one).
  - `rra`, `rrb`, `rrr`: Reverse rotate a stack (shift all elements down by one).
- The program outputs the sequence of operations needed to sort the stack with the minimum number of moves.
- Validates input to ensure all values are integers, no duplicates exist, and all values fit within the bounds of an integer.
- Ensures optimal performance by adhering to strict operation count benchmarks:
  - **100 elements**: Fewer than 700 operations.
  - **500 elements**: Fewer than 5500 operations.

### **Bonus Part**
- Implements a `checker` program to verify the correctness of the sorting sequence:
  - Reads a list of integers and a sequence of operations.
  - Executes the operations and checks if the stack is sorted and the auxiliary stack is empty.
  - Outputs `OK` if sorted, or `KO` if not.
- Enhances functionality for error handling and input validation, including:
  - Detection of invalid instructions.
  - Handling of incorrect input formats.
- Provides a robust testing tool for validating `push_swap` outputs.

---

## 🎯 Objectives

- Develop and optimize sorting algorithms tailored for stack-based operations.
- Practice efficient use of data structures and memory management.
- Understand and implement advanced sorting strategies for large datasets.
- Create a robust program that handles edge cases and invalid input gracefully.

---

## 🚀 Usage

### Compilation
1. Clone the repository:

   ```
2. Compile the project:
   ```bash
   make
   ```

### Running the Sorting Program
Run the program with the following syntax:
```bash
./push_swap [list of integers]
```
Example:
```bash
./push_swap 3 2 5 1 4
```

### Running the Checker Program (Bonus)
Use the checker program to validate operations:
```bash
./checker [list of integers]
```
Input operations manually or via a file to test sorting validity.

Example:
```bash
./checker 3 2 5 1 4
sa
pb
ra
pa
```

---

## 📝 Operations Summary

| Operation | Description                                 |
|-----------|---------------------------------------------|
| `sa`      | Swap the first two elements of stack `a`.   |
| `sb`      | Swap the first two elements of stack `b`.   |
| `ss`      | Swap the first two elements of both stacks. |
| `pa`      | Push the top element of stack `b` to `a`.   |
| `pb`      | Push the top element of stack `a` to `b`.   |
| `ra`      | Rotate stack `a` upwards.                  |
| `rb`      | Rotate stack `b` upwards.                  |
| `rr`      | Rotate both stacks upwards.                |
| `rra`     | Reverse rotate stack `a`.                  |
| `rrb`     | Reverse rotate stack `b`.                  |
| `rrr`     | Reverse rotate both stacks.                |

---

