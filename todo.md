# PUSH_SWAP
## PARSING
The program must work with several numerical arguments
- [x] ./push_swap 1 3 5 +9 20 -4 50 60 04 08

The program also works if you receive a single character list as a parameter
- [x] ./push_swap "3 4 6 8 9 74 -56 +495"

The program should NOT work if it encounters another character
- [x] ./push_swap 1 3 dog 35 80 -3
- [x] ./push_swap a
- [x] ./push_swap 1 2 3 5 67b778 947
- [x] ./push_swap " 12 4 6 8 54fhd 4354"
- [x] ./push_swap 1 --    45 32
        these examples should return "Error\n"

The program should NOT work if it encounters a double number

- [x] ./push_swap 1 3 58 9 3
- [x] ./push_swap 3 03
- [x] ./push_swap " 49 128     50 38   49"
    these examples should return "Error\n"
- [x] ./push_swap "95 99 -9 10 9"
        this example should work because -9 & 9 are not equal

The program should work with INT MAX & INT MIN
- [x] ./push_swap 2147483647 2 4 7
- [x] ./push_swap 99 -2147483648 23 545
- [x] ./push_swap "2147483647 843 56544 24394"
    these examples should work and sort your list
- [x] ./push_swap 54867543867438 3
- [x] ./push_swap -2147483647765 4 5
- [x] ./push_swap "214748364748385 28 47 29"
    these examples should return "Error\n"

Nothing has been specified when strings and int are mixed. It's up to you what you want to do
- [x] ./push_swap "1 2 4 3" 76 90 "348 05
---
## STRUCTURE
### Step 1
[Linked list lesson](https://code-vault.net/course/z1ry7bakhs:1603732279805)
- [x] Create `t_list`
- [x] Initialize and add nodes to `t_list`
- [x] Pass the array of `int` to the structure
- [x] Check for leaks and if double-linked
- [x] Implement the moves (use generic functions)
  - [x] SWAP
  - [x] PUSH
  - [x] ROTATE
  - [x] REVERSE ROTATE
---
## ALGORITHM
### Step 2
- [x] Sort 3 numbers
- [ ] Sort 5 numbers
### Step 3
- [ ] Push A to B
- [ ] Target decision (Greedy phase)
- [ ] Find cheapest argument
- [ ] Optimize moves
- [ ] Rotate A to sort from smallest to biggest
### Step 4
- [ ] Verify `norminette`
- [ ] Check for leaks
- [ ] Check and clean repo for forbidden files
- [ ] Check for forgotten printf()
---