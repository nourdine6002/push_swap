*This project has been created as part of the 42 curriculum by `nodoulah`.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum.

The objective of the project is to sort a list of integers stored in **stack A** using a limited set of allowed operations and an auxiliary **stack B**. The program must output a sequence of operations that sorts stack A in ascending order, while stack B is empty at the end.

The main challenge of the project is to minimize the number of operations.  
To achieve this, the algorithm uses index normalization, the Longest Increasing Subsequence (LIS), and a cost-based reinsertion strategy.

A second program, **checker**, is included to verify that the operations correctly sort the stack.

---

## Instructions

### Compilation

To compile the project, run:

```bash
make && make bonus
```

### Execution
Run push_swap with a list of integers as arguments:
```bash
./push_swap 3 1 2
```

To verify the correctness of these operations, use the checker:

```bash
./push_swap 3 1 2 | ./checker 3 1 2
```

./push_swap 3 1 2 | ./checker 3 1 2
The checker will display:

`OK` if stack A is sorted and stack B is empty

`KO` if the stack is not sorted

`Error` if the input or instructions are invalid

## Resources

### References

- 42 subject: *push_swap*
- https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
- https://en.wikipedia.org/wiki/Longest_increasing_subsequence
- https://en.wikipedia.org/wiki/Sorting_algorithm

### Use of Artificial Intelligence

AI tools (ChatGPT) were used as a learning and support resource during this project to:
- Understand algorithmic concepts such as the Longest Increasing Subsequence (LIS)
- Clarify cost-based rotation and optimization strategies
- Help improve explanations and documentation

## Usage Examples

Sort a small list of integers:

```bash
./push_swap 3 2 1
```
Verify the output using the checker:
```
./push_swap 3 2 1 | ./checker 3 2 1
```
Test with a larger input:
```
./push_swap 5 1 4 2 3
```
## Complexity

- Longest Increasing Subsequence calculation: O(n²)
- Reinsertion phase: O(n²)
- Efficient for the project requirements (100–500 numbers)

## Project Structure

- `push_swap/` — main sorting program
- `checker/` — validation program
- `libft/` — custom C library
- `get_next_line/` — input reader for checker
- `Makefile`
