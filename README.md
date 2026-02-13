_This project has been created as part of the 42 curriculum by lbolea._

# Push_swap
## Description
A set of random positive and negative integers, two stacks and eleven operations with strict rules. Your goal: create a program to sort those integers from smallest to biggest with the lowest possible number of operations. At most :

- Sort **100 random numbers** in fewer than **700** operations.
- Sort **500 random numbers** in no more than **5500** operations.

## Instructions
### Requirements
To compile this project, make sure you got these libraries installed and updated :

```
sudo apt-get update
sudo apt-get install make
sudo apt-get install gcc
sudo apt-get install libc.so.6
```
### Build program
Execute these command inside the directory to :

- Build the program

```
make
```
- Rebuild the program :
```
make re
```
- Clean the objects and dependencies :
```
make clean
```
- Force clean the entire build :
```
make fclean
```
### Execute program
To use the program, you can either use :
```
./push_swap [args ...]
```
or
```
./push_swap "args ..."
```
or
```
./push_swap [args ...] "args ..."
```
or
```
ARG="args ..."
./push_swap $ARG
```
The arguments can be inserted as individual integers and/or inside parenthesis. They must be separated by a space and shouldn´t contain anything else than integers or duplicated entries. In case of improper entries, the following message will be displayed:
```
./push_swap 1 2 three
Error
./push_swap "1 2 three"
Error
./push_swap 1 42 42 3
Error
```
Using checkers included in the project, use this script to test the program :
```
iter=50; sum=0; m=0; for i in $(seq 1 $iter); do 
    ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')");
    if ./push_swap $ARG | ./checker_linux $ARG | grep -q "KO"; then
        echo "Error"; break;
    fi
    n=$(./push_swap $ARG | wc -l);
    if ((n > m)); then
        m=$n;
    fi
    echo "Test $i: $n"; 
    sum=$((sum+n)); 
done;
echo ""
echo "	┏━━━━━━━━━━━━━━━━━━━┓"
echo "	┃      RESULTS      ┃"
echo "	┗━━━━━━━━━━━━━━━━━━━┛"
echo "	    AVERAGE: $((sum/iter))";
echo "	    WORST:   $m";
echo "\n"
```
## Resources

[Time and Space Complexity Analysis](https://www.geeksforgeeks.org/dsa/time-complexity-and-space-complexity/) → Understanding the base of algorithm complexity

[Big _O_ Notation](https://en.wikipedia.org/wiki/Big_O_notation) → The mathematical principle of order of growths

[Sorting algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm#Classification) → Basic list of sorting algorithms by types (comparisons, non-comparisons and others)

[Grokking algorithms](https://edu.anarcho-copy.org/Algorithm/grokking-algorithms-illustrated-programmers-curious.pdf) → An illustrated guide for understanding and manipulate how algorithms can be used in diverse cases

[Sorting algorithms animations](https://www.toptal.com/developers/sorting-algorithms) → A good _side-by-side_ visual representation of algorithms in action

[Stack - Linked list](https://www.geeksforgeeks.org/dsa/implement-a-stack-using-singly-linked-list/) → Implementation of stack abstract data structure as a linked list 

[Doubly linked list](https://en.wikipedia.org/wiki/Doubly_linked_list) → Efficient way of creating a dynamic data structure that can be easily accessed and updated 

[Linked list in C tutorial](https://code-vault.net/course/z1ry7bakhs:1603732279805) → Pretty throughout tutorial on how to implement a stack system in C

[Power of two](https://www.wolframalpha.com/input?i=18446744073709551616&assumption=%22ClashPrefs%22+-%3E+%7B%22Math%22%7D) → 2^64 is not your friend

[Push_swap visualizer](https://github.com/o-reo/push_swap_visualizer) → A great visual tool to understand and debug your algorithm