# push_swap

**push_swap** is a sorting project from the 42 / Codam curriculum.  
The goal is to sort a list of integers using **two stacks** (`A` and `B`) and a limited set of operations, while printing the operations to `stdout`.

This repository includes:
- `push_swap` (mandatory) — outputs the sequence of operations to sort stack A
- `checker` (bonus) — reads operations from `stdin` and prints `OK` / `KO`

---

## ✅ Rules (concept)

You start with:
- **Stack A**: the numbers from the arguments
- **Stack B**: empty

You must sort stack A in ascending order using only these operations:

### Swap
- `sa` — swap the first 2 elements of A
- `sb` — swap the first 2 elements of B
- `ss` — `sa` and `sb` at the same time

### Push
- `pa` — push the top element of B to A
- `pb` — push the top element of A to B

### Rotate
- `ra` — shift up all elements of A by 1
- `rb` — shift up all elements of B by 1
- `rr` — `ra` and `rb` at the same time

### Reverse rotate
- `rra` — shift down all elements of A by 1
- `rrb` — shift down all elements of B by 1
- `rrr` — `rra` and `rrb` at the same time

`push_swap` prints one instruction per line (e.g. `pb`, `ra`, `pa`, ...).

---

## ⚙️ Build

This project builds `libft` and then compiles the binaries.

### Build push_swap
    make

### Build checker (bonus)
    make bonus

Other targets:
    make clean
    make fclean
    make re
    make re_bonus

---

## ▶️ Usage

### push_swap
    ./push_swap 3 2 1

You can also pass numbers as a single quoted string (it will be split by spaces in this implementation):
    ./push_swap "3 2 1"

### checker (bonus)

Run `push_swap`, pipe its output into `checker`, and pass the same numbers to `checker`:

    ARG="3 2 1"
    ./push_swap $ARG | ./checker $ARG

Expected output:
- `OK` if the result is sorted and stack B is empty
- `KO` otherwise

---

## 🧾 Input validation

`push_swap` checks:
- non-numeric arguments
- integer overflow (must fit in `INT_MIN ... INT_MAX`)
- duplicates

On error it prints:
- `Error\n` to `stderr` and exits.

---

## 🧱 Data structures

### push_swap stack node (`t_stack`)

Each element is a linked list node:

- `value` — original integer value
- `index` — rank in sorted order (assigned from max to min)
- `pos` — current position in its stack (0 = top)
- `target` — desired position in stack A for insertion
- `a_cost` / `b_cost` — rotation costs needed to bring elements into place
- `next` — next node

---

## 🧠 Algorithm overview (this implementation)

This project uses an **index + cost-based insertion** strategy:

1) **Parse input into stack A**
   - Supports both `./push_swap 1 2 3` and `./push_swap "1 2 3"` (space-splitting per argument).
   - Validates integer bounds.

2) **Assign indices (ranks)**
   - Repeatedly finds the maximum unindexed value and assigns it the next highest index.
   - After this step, bigger numbers have bigger `index` values.

3) **Push most elements to stack B**
   - Keep only **3** elements in stack A.
   - The algorithm first pushes roughly half of the smaller indices to B, then pushes until A has 3 elements left.

4) **Sort 3 elements in stack A**
   - Uses a small dedicated routine for 3 elements.

5) **Reinsert from stack B into stack A (optimal cost move)**
   For each node in B:
   - Compute its **target position** in A:
     - the position of the smallest index in A that is bigger than the node’s index,
     - or, if none exists, the position of the minimum index in A.
   - Compute the **cost** to rotate A and B:
     - positive cost => `ra` / `rb`
     - negative cost => `rra` / `rrb`
     - costs are minimized by choosing reverse rotations for elements in the second half.
   - Choose the element in B with minimal:
     - `abs(a_cost) + abs(b_cost)`
   - Perform combined rotations when possible:
     - if both costs are positive => use `rr`
     - if both costs are negative => use `rrr`
   - Finish remaining rotations separately, then `pa`.

6) **Final alignment**
   - Rotate stack A until the minimum index is on top (best direction chosen).

---

## 📁 Project structure

### Mandatory (push_swap)
- `srcs/main.c`
  - Builds stack A, assigns indices, runs sorting strategy.

- `srcs/add_to_stack.c`
  - Parses arguments (supports space-splitting per argv entry).
  - Validates number format and integer bounds.

- `srcs/check_duplic.c`
  - Detects duplicates in stack A.

- Operations:
  - `srcs/push.c` — `pa`, `pb`
  - `srcs/swap.c` — `sa`, `sb`, `ss`
  - `srcs/rotate.c` — `ra`, `rb`, `rr`
  - `srcs/reverse_rotate.c` — `rra`, `rrb`, `rrr`

- Sorting logic:
  - `srcs/sort_stack.c` — main sorting routine and 3-element sort
  - `srcs/stack_b.c` — pushing strategy to move elements into B
  - `srcs/find_target.c` — target position logic for insertion into A
  - `srcs/calculate_costs.c` — computes a/b rotation costs
  - `srcs/move.c` — executes the chosen cheapest move from B to A
  - `srcs/final_sort.c` — final rotation to align A

- Utilities:
  - `srcs/utils.c`, `srcs/ft_utils.c`

### Bonus (checker)
- `bonus/main_cheker.c`
  - Reads instructions from `stdin` (via `get_next_line`)
  - Applies them to stacks
  - Prints `OK` / `KO`

- Instruction parsing:
  - `bonus/parse_arg.c` — parses argv into stack A (argv must be separate numbers)

- Operations (checker versions):
  - `bonus/swap_checker.c`
  - `bonus/push_checker.c`
  - `bonus/rotate_checker.c`
  - `bonus/reverse_rotate_checker.c`

- Utilities:
  - `bonus/utils_1.c`, `bonus/utils_2.c`

---

## 🧠 What I learned

- Implementing and reasoning about stack-based algorithms with strict operation constraints
- Building a real cost-based insertion strategy to reduce operation count
- Using indices (ranks) to simplify comparisons and target search
- Handling input validation thoroughly (duplicates, bounds, malformed input)
- Writing a separate checker program to validate operation sequences
