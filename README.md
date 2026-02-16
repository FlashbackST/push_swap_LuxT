# push_swap

*This project has been created as part of the 42 curriculum by <sthinnes> and <dgarot>.*

```text
................................................
                * PUSH_SWAP *

{oups}       /|     |  |      {Sven noooooo}
      O     / |     |  |    \O/
      |<   /  |     |  |     |
     / \  |   |     |  |    / \

 <sthinnes>               <dgarot>
...............................................
```

---

## Description

The project "push_swap" requires the creation of various types of sorting algorithms with different complexity levels. The main objective of this project is to sort a messy "stack a" containing a random quantity of negative and / or positive numbers without duplicates, in ascending order, as quickly as possible using the smallest number of operations. To accomplish this task, we have the following components at our disposal:

- A filled "stack a"
- An empty "stack b"
- A selection of different sorting operations which can move numbers around in the stacks
- A list of sorting algorithms with different complexity levels

### Brief Overview

**Makefile:**

A Makefile is a special file that creates and compiles specific files using the 'make' build automation tool. In this project, the Makefile is used to create the object files (.o) of the different functions, to compile the library "libft.a" inside the "Libft" folder and to compile the executable file "push_swap" of this project.

The Makefile of the project "push_swap" contains this information:

```makefile
.PHONY: all clean fclean re bonus libft

NAME		= push_swap
BONUS_NAME	= checker
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I.
LIBFT_DIR	= Libft
LIBFT		= $(LIBFT_DIR)/libft.a

# Common sources (shared between push_swap and checker)
COMMON_SRCS	= flags.c benchmark_record.c benchmark_init.c \
			  benchmark_display_utils.c benchmark_display.c \
			  swap_a.c swap_b.c swap_a+b.c \
			  push_a.c push_b.c \
			  rotate_a.c rotate_b.c rotate_a+b.c \
			  reverse_rotate_a.c reverse_rotate_b.c reverse_rotate_a+b.c \
			  check_if_numbers.c check_if_outside_valid_range.c check_for_duplicates.c \
			  create_stack.c stack_add_bottom.c \
			  parse_arguments_utils.c parse_arguments.c print_stack.c \
			  disorder_metric.c \
			  simple_algorithm_insertionsort_utils.c simple_algorithm_insertionsort.c \
			  simple_algorithm_selectionsort_utils.c simple_algorithm_selectionsort.c \
			  medium_algorithm_bucketsort_swap_functions.c \
			  medium_algorithm_bucketsort_rotate_functions.c \
			  medium_algorithm_bucketsort_helpers.c \
			  medium_algorithm_bucketsort_utils.c medium_algorithm_bucketsort.c \
			  complex_algorithm_turksort_index.c \
			  complex_algorithm_turksort_push_functions_part1.c \
			  complex_algorithm_turksort_push_functions_part2.c \
			  complex_algorithm_turksort_rotate_functions.c \
			  complex_algorithm_turksort_rotate_min.c \
			  complex_algorithm_turksort_counter.c \
			  complex_algorithm_turksort_utils.c complex_algorithm_turksort.c \
			  adaptive_algorithm.c \
			  print_disorder.c copy_stack.c if_stack_is_sorted.c \
			  error_output.c free_stack.c main_utils.c

# Push_swap specific sources
PUSH_SWAP_SRCS = main_algorithm_utils.c main_algorithm_utils2.c \
				 main_algorithm_utils3.c main_algorithm_utils4.c \
				 main_sorting1.c main_sorting2.c main.c

# All push_swap sources
SRCS		= $(COMMON_SRCS) $(PUSH_SWAP_SRCS)

# Bonus sources
BONUS_SRCS	= checker_bonus.c checker_operations_bonus.c \
			  get_next_line_for_push_swap_bonus.c \
			  get_next_line_utils_for_push_swap_bonus.c

# Object files
OBJS			= $(SRCS:.c=.o)
COMMON_OBJS		= $(COMMON_SRCS:.c=.o)
PUSH_SWAP_OBJS	        = $(PUSH_SWAP_SRCS:.c=.o)
BONUS_OBJS		= $(BONUS_SRCS:.c=.o)

all: libft $(NAME)

bonus: libft $(BONUS_NAME)

libft:
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(COMMON_OBJS) $(PUSH_SWAP_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(COMMON_OBJS) $(PUSH_SWAP_OBJS) $(LIBFT) -lm

$(BONUS_NAME): $(COMMON_OBJS) $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(COMMON_OBJS) $(BONUS_OBJS) $(LIBFT) -lm

%.o: %.c push_swap.h benchmark.h flags.h checker.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(COMMON_OBJS) $(PUSH_SWAP_OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
```

*Obligatory to include in the Makefile for this project: The command 'cc' (command to invoke the C Compiler of the terminal), the Compilation Flags '-Wall', '-Wextra' and '-Werror' to compile the source files to the required output and the rules '$(NAME)', 'all', 'clean', 'fclean' and 're'.*

---

### ► Header files:

---

1. **flags.h:**

   The header file which contains all the function prototypes, includes statements (necessary standard library headers) and a new type definition ("t_flags" → stores the command-line flag settings for the flags "--simple", "--medium", "--complex", "--adaptive", "--bench" and "--quiet" and tracks which algorithm flag (simple, medium, complex or adaptive) appeared at which position in the command-line to create the new flags).

2. **benchmark.h:**

   The header file which contains all the function prototypes, includes statements (necessary standard library headers), new type definitions ("t_op_counts" → stores the counter for the different sorting operations (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb and rrr) and the total counter for all used operations. "t_benchmark" → checks if benchmarking is enabled or not (on / off), how unsorted the input is, which algorithm was used, the complexity level of the used algorithm and it contains the operation counts structure "t_op_counts ops") and the defined structures of "t_stack" and "t_flags" to set up the "benchmark mode".
    
3. **push_swap.h:**

   The main header file which contains all the function prototypes, includes statements (necessary standard library headers and project headers), new type definitions ("t_stack" → features data about the array, capacity and size of the stacks and covers the data of the disorder metric. "t_bucket_info" → covers the main data of the bucket sort algorithm. "t_rotate_ctx" → contains information about the rotation operations for the bucket sort algorithm. "t_chunk_ctx" → contains information about the functionality of the "chunk" sorting for the bucket sort algorithm. "t_pos_pair" → the positions for both stacks used for simultaneous rotations. "t_multi_algo" → used when multiple algorithms are executed for a comparison. "t_rotate_pair" → tracks the rotation positions for both stacks simultaneously. "t_rot_params" → passes the current rotation positions. "t_find_pos" → collects information about the stack state while searching for the ideal insertion position. "t_algo_ctx" → covers the total data needed to run a sorting algorithm) and indicated "INT_MAX" and "INT_MIN" values to carry out the project.

---

### ► All functions used in this project "push_swap":

---

****Files used to implement new flags:****

---

1. ****Functions used in the file "flags.c":****

   **● strcmp:**

   Compares two strings character by character. Returns 0 if the strings are equal, returns non-zero if the strings are different and returns -1 if both strings are NULL.

   **● init_flags:**

   Sets all flags to 0 (turn off) at the start.

   **● set_algo_flag:**

   Checks which algorithm flag was entered and sets the corresponding flag to 1 (turn on). Tracks the flag order for simple, medium, complex and adaptive (to know the order of the entered flags).

   **● process_flag:**

   Processes a single command-line flag by calling "set_algo_flag" to handle algorithm flags, then checks for other flags like --bench or --quiet. Exits with error if the flag is invalid.

   **● parse_flags:**

   Goes through the command-line arguments (Calls "process_flag" for each argument that starts with --). Stops when it finds a non-flag argument (the numbers).

---

****Files used to implement the "benchmark mode":****

---

1. ****Functions used in the file "benchmark_record.c":****

   **● record_swap_ops:**

   Counts all swap operations (sa, sb, ss) and increases the swap counter.

   **● record_push_ops:**

   Counts all push operations (pa, pb) and increases the push counter.

   **● record_rotate_ops:**

   Counts all rotate operations (ra, rb, rr) and increases the rotate counter.

   **● record_reverse_ops:**

   Counts all reverse rotate operations (rra, rrb, rrr) and increases the reverse rotate counter.

   **● benchmark_record_op:**

   Main function that is called whenever any operation happens. Increases the total operation counter (Calls the appropriate helper function to count the specific operation type).


2. ****Functions used in the file "benchmark_init.c":****

   **● init_op_counts:**

   Sets all operation counters to 0 (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr, and total).

   **● benchmark_init:**

   Initializes the benchmark structure. Sets an enabled flag, resets the disorder score to 0 and clears the strategy names (Calls "init_op_counts" to set all counters to 0).

   **● benchmark_set_disorder:**

   Stores the disorder score.

   **● benchmark_set_strategy:**

   Runs the complex algorithm (turk sort) if "--bench" is the only flag that is used.

   **● make_benchmark:**

   Main function that prepares the benchmark before sorting. Initializes the "benchmark mode" and sets the "disorder metric".


3. ****Functions used in the file "benchmark_display_utils.c" (Helper functions):****

   **● put_nbr_fd:**

   Writes an integer to a file descriptor. Handles negative numbers and the special case of -2147483648 (INT_MIN).

   **● put_double_fd:**

   Writes a decimal number to a file descriptor. Splits the number into an integer format with two decimal places.

   **● strlen_bench:**

   Counts how many characters are in the string and returns the length of the string.


4. ****Functions used in the file "benchmark_display.c":****

   **● print_op:**

   Prints one operation name and its count.

   **● print_swap_push_ops:**

   Prints the counts for swap and push operations (sa, sb, ss, pa, pb).

   **● print_rotate_ops:**

   Prints the counts for rotate operations (ra, rb, rr, rra, rrb, rrr).

   **● benchmark_display:**

   Main function that displays all benchmark results (Displays the disorder in percentage, the strategy name and complexity, the total operation count and a detailed summary of all operations).

---

****Functions used to implement the different sorting operations:****

---

1. **swap_a (sa):**

   Swap the first two elements at the top of "stack a". Do nothing if there is only one or no elements.

2. **swap_b (sb):**

   Swap the first two elements at the top of "stack b". Do nothing if there is only one or no elements.

3. **swap_a+b (ss):**

   Swap the first two elements at the top of "stack a" and at the top of "stack b" at the same time.

4. **push_a (pa):**

   Take the first element at the top of "stack b" and put it at the top of "stack a". Do nothing if "stack b" is empty.

5. **push_b (pb):**

   Take the first element at the top of "stack a" and put it at the top of "stack b". Do nothing if "stack a" is empty.

6. **rotate_a (ra):**

   Shift up all elements of "stack a" by one. The first element becomes the last one.

7. **rotate_b (rb):**

   Shift up all elements of "stack b" by one. The first element becomes the last one.

8. **rotate_a+b (rr):**

   Shift up all elements of "stack a" and "stack b" by one at the same time. The first element of "stack a" and "stack b" becomes the last one.

9. **reverse_rotate_a (rra):**

   Shift down all elements of "stack a" by one. The last element becomes the first one.

10. **reverse_rotate_b (rrb):**

    Shift down all elements of "stack b" by one. The last element becomes the first one.

11. **reverse_rotate_a+b (rrr):**

    Shift down all elements of "stack a" and "stack b" by one at the same time. The last element of "stack a" and "stack b" becomes the first one.

---

****Files used to check for "Error" cases:****

---

1. ****Functions used in the file "check_if_numbers.c":****

   **● check_single_number:**

   Validates one number within a string and allows a '+' or '-' sign at the start. Returns 1 (Error) if the passed argument contains more than one '+' or '-' sign at the start or contains non-digit characters. Returns 0 (Valid) if the passed character is a proper integer.

   **● validate_argument:**

   Validates an entire argument string (Skips whitespace, then calls "check_single_number" for each number found in the string). Returns 1 (Error) if the passed string contains any non-digit character or if the string has no numbers at all. Returns 0 (Valid) if all characters of the passed string are proper integers.

   **● check_if_numbers:**

   Main function that checks all command-line arguments (Skips flag arguments, then calls "validate_argument" on each non-flag argument). Returns 1 (Error) if any argument is invalid. Returns 0 (Valid) if all arguments are valid.


2. ****Functions used in the file "check_if_outside_valid_range.c":****

   **● strtol:**

   Converts a string to a long integer (Skips leading whitespace and handles '+'/'-' signs). Parses digits and returns the result. Sets an endpointer to point to the first non-digit character (so caller knows where parsing stopped).

   **● check_number_range:**

   Checks if all numbers in a string are within the valid int range (INT_MIN to INT_MAX). Uses ft_strtol() to parse each number as a long integer. Returns 1 (Error) if any number is outside the valid range. Returns 0 (Valid) if all numbers are within the valid range.

   **● check_if_outside_valid_range:**

   Main function that validates all command-line arguments (Skips flag arguments, then calls "check_number_range" on each non-flag argument). Returns 1 (Error) if any number is out of range. Returns 0 (Valid) if all numbers are within the valid range.


3. ****Functions used in the file "check_for_duplicates.c":****

   **● check_for_duplicates:**

   Compares every number in the stack with every other number. Uses two loops to check (Outer loop picks one number and inner loop checks it against all numbers after it). Returns 1 (Error) if it finds two identical numbers. Returns 0 (Valid) if all numbers are unique.

---

****Files used to implement the two stacks "stack a" and "stack b":****

---

1. ****Functions used in the file "create_stack.c":****

   **● create_stack:**

   Creates a new empty stack with storage capacity for an unspecified amount of numbers. Allocates memory for the stack structure itself and for the array that will hold the numbers. Sets the capacity (maximum size) and the size (current count = 0) for the new stack. Returns the pointer to the new stack or returns NULL if memory allocation fails. If the allocation fails partway through, it frees any allocated memory before returning NULL.


2. ****Functions used in the file "stack_add_bottom.c":****

   **● stack_add_bottom:**

   Adds a number to the bottom of the stack / at position size (If stack is NULL → do nothing. If stack is full (size >= capacity) → do nothing). Then increases the size by 1.


3. ****Functions used in the file "parse_arguments_utils.c":****

   **● has_space:**

   Checks if a string contains any spaces or tabs (Used to detect if an argument has multiple numbers). Returns 1 if it finds a space / tab. Returns 0 if it doesn't find a space / tab.

   **● parse_split_arg:**

   Handles arguments with multiple space-separated numbers. Splits the string by spaces using "ft_split". Converts each numeric argument to an integer using "ft_atoi". Then adds each number to the bottom of the stack using "stack_add_bottom". Finally, it frees the memory used by the split strings.

   **● process_argument:**

   Main function that processes one command-line argument (If the argument contains spaces → calls "parse_split_arg" to handle multiple numbers. If no spaces → converts the single number with "ft_atoi" and adds it to the stack).


4. ****Functions used in the file "parse_arguments.c":****

   **● parse_arguments:**

   Creates and fills the stack from command-line arguments. Counts how many numbers are in all arguments and creates a stack with that capacity. Loops through all arguments (skips program name at index 0). For each non-flag argument, it processes the argument to extract the numbers and adds them to the stack. Returns the filled stack or NULL if creation fails.


5. ****Functions used in the file "print_stack.c":****

   **● get_num_width:**

   Calculates how many characters are needed to print a number by counting all the digits. Adds 1 if it encounters a negative sign (if necessary).

   **● get_stack_width:**

   Finds the largest number in the entire stack. Checks every number and returns the width of the largest number (used for formatting the alignment).

   **● print_stack_row:**

   Prints one row if the current checked position contains an element in both stacks (If "stack a" has an element at position i → print it. If "stack b" has an element at position i → print it with a space between the two stacks).

   **● print_footer:**

   Prints the bottom part of the display. Draws dashes under each stack, then prints centered "a" and "b" labels under the dashed line.

   **● print_stack:**

   Main function that displays both stacks side by side. Prints all rows (one for each position), then prints the footer with the labels "a" and "b".

---

****Files used to implement the "disorder metric":****

---

1. ****Functions used in the file "disorder_metric.c":****

   **●compute_disorder:**

   Calculates how unsorted the stack is. Compares every pair of numbers in the stack and counts the "mistakes" (when a number on the left is bigger than one on the right). Returns a score between 0.0 and 1.0.

---

****Files used to implement the simple sorting algorithms:****

---

****► For insertion sort algorithm:****

---

1. ****Functions used in the file "simple_algorithm_insertionsort_utils.c":****

   **● find_max_position:**

   Finds the position (index) of the largest number in the stack. Loops through all numbers and keeps track of which one is the biggest number. Returns the index where the maximum value is located. Returns -1 if the stack is empty or NULL.


2. ****Functions used in the file "simple_algorithm_insertionsort.c":****

   **● find_insert_position:**

   Finds where to insert a value in "stack a" to keep it sorted. Looks for the smallest number that is bigger than the value. If all numbers are smaller, it returns to the position after the max value. Otherwise, it returns to the position where the number should be placed.

   **● rotate_to_position:**

   Rotates "stack a" until the desired value is at the top. Chooses the shortest path (If desired value is in the first half → rotate up (ra). If desired value is in the second half → rotate down (rra)).

   **● insertion_sort:**

   Main function that initiates the insertion sort algorithm. Pushes all numbers from "stack a" to "stack b". For each number in "stack b", it finds where it should be placed in "stack a", rotates to that position and pushes it back. Finally, it rotates "stack a" so the minimum is on top. Returns without using any operations if the stack is already sorted or contains only 1 element.

---

****► For selection sort algorithm:****

---

1. ****Functions used in the file "simple_algorithm_selectionsort_utils.c":****

   **● find_min_position:**

   Finds the position (index) of the smallest number in the stack. Loops through all numbers and keeps track of which one is the smallest number. Returns the index where the minimum value is located. Returns -1 if the stack is empty or NULL.

   **● rotate_to_min:**

   Rotates "stack a" until the minimum value is at the top. Chooses the shortest path (If minimum value is in the first half → rotate up (ra). If minimum value is in the second half → rotate down (rra)).


2. ****Functions used in the file "simple_algorithm_selectionsort.c":****

   **● selection_sort:**

   Main function that initiates the selection sort algorithm. Finds the minimum value in "stack a", rotates the value to the top and pushes it to "stack b". Repeats it until "stack a" is empty. Finally, it pushes everything back from "stack b" to "stack a" (now sorted in ascending order). Returns without using any operations if the stack is already sorted or contains only 1 element.

---

****Files used to implement the medium sorting algorithm:****

---

1. ****Functions used in the file "medium_algorithm_bucketsort_swap_functions.c":****

   **● can_swap_improve_a:**

   Checks if swapping the top 2 elements in "stack a" would improve the order. Returns 1 if the top element is bigger than the second element (swap would improve the order). Returns 0 if the stack has less than 2 elements or if the stack is already in order.

   **● can_swap_improve_b:**

   Checks if swapping the top 2 elements in "stack b" would improve the order. Returns 1 if the top element is smaller than the second element (swap would improve the order). Returns 0 if the stack has less than 2 elements or if the stack is already in order.

   **● optimize_with_swap:**

   Performs swap operations if it would improve the order (If both stacks need to be swapped → execute operation "ss". If only "stack a" needs to be swapped → execute operation "sa". If only "stack b" needs to be swapped → execute operation "sb". If neither needs to be swapped → do nothing).


2. ****Functions used in the file "medium_algorithm_bucketsort_rotate_functions.c":****

   **● do_rr_operations:**

   Rotates both stacks upward at the same time (Executes the operation "rr"). Continues until one of the desired values reaches 0 (top). 

   **● do_rrr_operations:**

   Rotates both stacks downward at the same time (Executes the operation "rrr"). Continues until one of the desired values reaches the stack size (bottom).

   **● rotate_both_stacks:**

   Main function that rotates both stacks efficiently until the desired values reach the appropriate positions (If both values are in the first half → rotate up (rr) both values at the same time. If both values are in the second half → rotate down (rrr) both values at the same time. Otherwise rotate each value individually). Extracts the positions from "pos_data" (encoded as two 16-bit values). Finishes when the desired value of each stack reaches its exact position.


3. ****Functions used in the file "medium_algorithm_bucketsort_helpers.c" (Helper functions):****

   **● find_min_in_array:**

   Finds the smallest number in an array. Loops through all elements and keeps track of the minimum value. Then it returns the minimum value.

   **● find_max_in_array:**

   Finds the largest number in an array. Loops through all elements and keeps track of the maximum value. Then it returns the maximum value.


4. ****Functions used in the file "medium_algorithm_bucketsort_utils.c" (Helper functions):****

   **● rotate_to_position_b:**

   Rotates "stack b" until the desired value is at the top (If the desired value is in the first half → rotate up (rb). If the desired value is in the second half → rotate down (rrb)).

   **● rotate_to_position_a:**

   Rotates "stack a" until the desired value is at the top (If the desired value is in the first half → rotate up (ra). If the desired value is in the second half → rotate down (rra)).


   **● find_insert_position_a:**

   Finds where to insert a value in "stack a" to keep it sorted. Looks for the first number that is bigger than the value. If the value is bigger than all other numbers, it returns to the stack size (inserts at the end). Otherwise, it returns to the position where the number should be placed.


5. ****Functions used in the file "medium_algorithm_bucketsort.c":****

   **● get_chunk:**

   Calculates which chunk (bucket) a value belongs to. Divides the range (minimum value to maximum value) into equal-sized chunks. Returns the chunk to the corresponding bucket number.

   **● push_chunk_to_b:**

   Pushes all numbers from a specific chunk or below from "stack a" to "stack b", rotating once through "stack a" (If number belongs to current chunk or below → push to "stack b". If number belongs to a lower chunk → rotate it down (rb) in "stack b". If the number belongs to a higher chunk → rotate it to the bottom (ra) of "stack a").

   **● push_back_to_a:**

   Pushes all numbers back from "stack b" to "stack a" in a sorted order. Repeatedly finds the maximum value in "stack b", rotates it to the top, then pushes it to "stack a" ("stack a" is sorted in ascending order).

   **● bucket_sort:**

   Main function that initiates the bucket sort algorithm. Calculates the number of buckets (between 2 and 12). Finds the minimum and maximum values and pushes the numbers to "stack b" chunk by chunk (smallest chunks first). Finally, it pushes everything back to "stack a" (largest chunks first). Returns without using any operations if the stack is already sorted or contains only 1 element.

---

****Files used to implement the complex sorting algorithm:****

---

1. ****Functions used in the file "complex_algorithm_turksort_index.c":****

   **● calculate_rank:**

   Determines the position (rank) of a number in the stack, then it counts how many numbers in the stack are smaller than the number at the given index. The rank starts at 1.

   **● create_index_array:**

   Converts all the actual numbers in "stack a" into their ranks while saving the original values. Instead of random values, the numbers are now organized in sequential order, making sorting easier.

   **● restore_stack_values:**

   Takes a single stack containing assigned ranks and converts the ranks back to their original numbers using the saved array.

   **● restore_original_values:**

   Restores both "stack a" and "stack b" from their ranked versions back to their original values. Calls "restore_stack_values" for each stack recognizing that the original array represents both stacks combined.


2. ****Functions used in the file "complex_algorithm_turksort_push_functions_part1.c":****

   **● find_min_in_b:**

   Searches through "stack b" to find the position of the smallest number. Loops through the entire stack comparing the values and returns the index where the minimum value is located.

   **● find_pos_in_b:**

   Finds where a value from "stack a" should be placed in "stack b" to keep "stack b" sorted in descending order. Looks for the smallest number in "stack b" that is still larger than the given value. If there is no such number (value is larger than everything in "stack b"), it returns the position of the minimum value.

   **● get_count:**

   Calculates the minimum number of rotations needed to bring an element at a given position to the top. Chooses the shortest path (either rotate upward or downward from the position).

   **● calc_push_count:**

   Calculates the total number of operations needed to push an element from "stack a" to "stack b". If both positions are in the same half of the stack (both in the first half or both in the second half), then the stacks can be rotated simultaneously, returning the maximum of the two counts. Otherwise, they must be rotated separately, returning the sum.

   **● find_cheapest_in_a:**

   Finds which element in "stack a" would be the fastest (fewest operations) to push to "stack b". Checks every element in "stack a", calculates the total number of operations needed to push each element from "stack a" to "stack b" and returns the position of the fastest one. If the total number of operations are equal, it prefers the bigger value.


3. ****Functions used in the file "complex_algorithm_turksort_push_functions_part2.c":****

   **● rotate_both_same_dir:**

   Rotates both stacks simultaneously in the same direction when it is necessary (If both positions are in the first half → rotate both stacks upward simultaneously (rr). If both positions are in the second half → rotate both stacks downward simultaneously (rrr)).

   **● rotate_a_only:**

   Rotates only "stack a" to bring an element to the top, choosing the most efficient path (If in the first half → rotate upward (ra). If in the second half → rotate downward (rra)).

   **● rotate_b_only:**

   Rotates only "stack b" to bring an element to the top, choosing the most efficient path (If in the first half → rotate upward (rb). If in the second half → rotate downward (rrb)).

   **● push_cheapest_from_a:**

   Main function that pushes the most efficient element from "stack a" to "stack b". Finds the fastest element to push from "stack a" to "stack b" by finding where the element should be placed in "stack b". Rotates both stacks together when it is necessary. Finally, it performs any remaining individual rotations and pushes the element from "stack a" to "stack b".


4. ****Functions used in the file "complex_algorithm_turksort_rotate_functions.c":****

   **● rotate_both_forward:**

   Rotates both stacks upward simultaneously (using the rr operation) as long as both positions are greater than 0. This saves moves when both elements need to be rotated in the same direction.

   **● rotate_both_reverse:**

   Rotates both stacks downward simultaneously (using the rrr operation). Saves moves by calculating how many reverse rotations each stack needs and performing them together.

   **● rotate_b_to_top:**

Moves an element at a given position in "stack b" to the top, choosing the most efficient path (If the element is in the first half → rotate upward (rb). If the element is in the second half → rotate downward (rrb)).

   **● rotate_a_to_top:**

Moves an element at a given position in "stack a" to the top, choosing the most efficient path (If the element is in the first half → rotate upward (ra). If the element is in the second half → rotate downward (rra)).

   **● rotate_both_optimally:**

   Main function that coordinates the rotating operations to sort both stacks efficiently. Finds where the element from "stack b" should be placed in "stack a" (If both elements are in the first halves → rotate both elements upward simultaneously (rr). If both elements are in the second halves → rotate both elements downward simultaneously (rrr)). Finally, it performs any remaining individual rotations.


5. ****Functions used in the file "complex_algorithm_turksort_rotate_min.c":****

   **● find_min_pos:**

   Searches through "stack a" to find the position of the smallest number. Loops through the entire stack comparing the values and returns the index where the minimum value is located.

   **● rotate_min_to_top:**

   Moves the minimum value to the top of "stack a", choosing the most efficient path (If the minimum value is in the first half → rotate upward (ra). If the minimum value is in the second half → rotate downward (rra)).

   **● final_rotate_to_min:**

   Main function that completes the sorting by putting the smallest element at the top of "stack a". Get called at the end of the sorting algorithm to ensure the stack is in perfect ascending order.


6. ****Functions used in the file "complex_algorithm_turksort_counter.c":****

   **● get_moves_count:**

   Calculates the minimum number of rotations needed to bring an element at a given position to the top of a stack. It chooses the most efficient path (by rotating upward or downward).

   **● calculate_combined_count:**

   Calculates the total number of operations needed to move elements from both stacks to their expected positions. If both positions are in the same half (both in the first half or both in the second half), then the stacks can be rotated simultaneously, returning the maximum of the two counts. Otherwise, they must be rotated separately, returning the sum.

   **● calculate_count:**

   Calculates the total number of operations to push a specific element from "stack b" back to "stack a". Finds where the element should be placed in "stack a", then uses "calculate_combined_count" to determine the total rotation count.

   **● find_cheapest_element:**

   Finds which element in "stack b" would be the fastest (fewest operations) to push back to "stack a". Checks every element in "stack b", calculates the total number of operations needed to push each element from "stack b" back to "stack a" and returns the position of the fastest one.


7. ****Functions used in the file "complex_algorithm_turksort_utils.c":****

   **● update_min_values:**

   Checks if the current element in "stack a" is smaller than the current minimum value. If it is the case, it updates both the minimum value and its position.

   **● init_find_pos:**

   Initializes the variables used for finding the ideal position. Sets up the starting values ("best_pos" as -1 (not found yet), "min_diff" as a very large number and the minimum value as the initial minimum position).

   **● check_position:**

   Checks if the current element in "stack a" is located at a good position to insert a value. Looks for the smallest number in "stack a" that is still larger than the value being inserted. If the smallest number is found and it is closer than previous elements, it updates the best position.

   **● find_ideal_pos_in_a:**

   Main function that finds where a value should be placed in "stack a" to maintain a sorted order. Searches for the smallest number in "stack a" that is larger than the given value. If no such number exists (the value is larger than everything), it returns the position of the minimum value (wrapping around to maintain a sorted order).


8. ****Functions used in the file "complex_algorithm_turksort.c":****

   **● sort_three:**

   Sorts a stack with 2 or 3 elements using hardcoded logic. For 2 elements, it swaps if necessary. For 3 elements, it uses a combination of rotate and swap operations to sort them efficiently.

   **● turk_sort:**

   Main function that initiates the turk sort algorithm. Uses "sort_three" if it has 2-3 elements. Pushes the first two elements to "stack b". If they're in the wrong order in "stack b", it swaps the two elements so "stack b" starts in a sorted order (descending order). While "stack a" has more than 3 elements, it repeatedly finds the fastest element to be pushed and pushes it from "stack a" to "stack b". This keeps "stack b" sorted in a descending order. Once "stack a" has only 3 elements left, it sorts them using "sort_three". While "stack b" has elements, it finds the fastest element in "stack b" to push it back, then rotates both stacks optimally to position it correctly and pushes it to "stack a". Finally, it rotates "stack a" that the minimum value is at the top, making the entire stack sorted in ascending order. Returns without using any operations if the stack is already sorted or contains only 1 element.

---

****Files used to implement the adaptive sorting algorithm:****

---

1. ****Functions used in the file "adaptive_algorithm.c":****

   **● adaptive_algorithm:**

   Automatically chooses the best sorting algorithm based on how unsorted the stack is. It uses the disorder metric to make a logical decision (For low disorder (< 0.2) → Uses simple algorithm (insertion sort). For medium disorder (≥ 0.2 to < 0.5) → Uses medium algorithm (bucket sort). For high disorder (≥ 0.5) → Uses complex algorithm (turk sort)). After running the chosen algorithm, it updates the benchmark metadata to show which strategy was selected and its complexity.

---

****Files used to implement the "main":****

---

1. ****Functions used in the file "print_disorder.c":****

   **● print_disorder:**

   Prints the disorder metric (how unsorted the stack is at the beginning) in a readable format. Splits the decimal number into a whole part and a decimal part.


2. ****Functions used in the file "copy_stack.c":****

   **● copy_stack:**

   Copies all elements from the source stack to the destination stack. Loops through all elements in the source stack and copies them to the destination stack. Also copies the size value of the source stack. Does nothing if either stack is NULL.


3. ****Functions used in the file "if_stack_is_sorted.c":****

   **● is_sorted:**

   Checks if the stack is already sorted in ascending order Returns 1 (true) if the stack is NULL, empty, only has 1 element or all elements are in ascending order. Returns 0 (false) if any element is greater than the next one.


4. ****Functions used in the file "error_output.c":****

   **● error_output:**

   Validates the command-line arguments and exits if there are errors. Checks if all arguments are valid numbers (using "check_if_numbers") and if all numbers are within the valid int range (using "check_if_outside_valid_range"). If either check fails, it writes "Error" to stderr (file descriptor 2) and exits the program with status 1. Returns 0 if all validation passes.


5. ****Functions used in the file "free_stack.c":****

   **● free_stack:**

   Frees all the memory allocated for implementing a stack. Checks if the stack exists (if NULL, it does nothing), frees the array holding the numbers (collection) and frees the stack structure itself. Prevents memory leaks by cleaning up resources in the correct order.


6. ****Functions used in the file "main_algorithm_utils.c":****

   **● print_header:**

   Prints a header to indicate which algorithm is being used (also when benchmark mode is used).

   **● run_single_simple:**

   Runs the simple sorting algorithm (insertion sort) on the stacks:

   → Prints the initial disorder and the initial state of the stacks

   → Prints the "SIMPLE" header

   → Checks if the stack is already sorted

   → Runs the insertion sort algorithm

   → Prints the final state of the stacks

   **● run_single_medium:**

   Runs the medium sorting algorithm (bucket sort) on the stacks:

   → Prints the initial disorder and the initial state of the stacks

   → Prints the "MEDIUM" header

   → Checks if the stack is already sorted

   → Runs the bucket sort algorithm

   → Prints the final state of the stacks

   **● setup_and_sort:**

   Main function that prepares and executes the sorting process:

   → Calculates the disorder: Computes how unsorted the stack is (how far from sorted)

   → Counts the algorithms: Checks how many algorithm flags are enabled (simple, medium, complex, adaptive)

   → Displays the disorder: Shows the "disorder metric" if only one algorithm is used

   → Benchmark setup: Initializes the "benchmark mode" when a single algorithm is used  

   → Runs the sorting: Calls the appropriate sorting algorithm

   → Displays results: Shows the benchmark statistics and the final stack state


7. ****Functions used in the file "main_algorithm_utils2.c":****


   **● run_single_complex:**

   Runs the complex sorting algorithm (turk sort) on the stacks:

   → Prints the initial disorder and the initial state of the stacks

   → Prints the "COMPLEX" header

   → Checks if the stack is already sorted

   → Runs the turk sort algorithm

   → Prints the final state of the stacks

   **● run_single_adaptive:**

   Runs the adaptive sorting algorithm on the stacks:

   → Prints the initial disorder and the initial state of the stacks

   → Prints the "ADAPTIVE" header

   → Checks if the stack is already sorted

   → Runs the adaptive sorting algorithm

   → Prints the final state of the stacks

   **● execute_algorithm:**

   A dispatcher function that calls the appropriate sorting algorithm based on a number code (For 0 → insertion sort (simple) / For 1 → bucket sort (medium) / For 2 → turk sort (complex) / For 3 → adaptive algorithm).

   **● print_algorithm_header:**

   Prints the header for a specific algorithm based on a number code. Connects the same numbers as "execute_algorithm" to their corresponding header names (SIMPLE, MEDIUM, COMPLEX, or ADAPTIVE).

   **● run_algorithm_with_header:**

   Combines tasks like printing the header, running the chosen algorithm and displaying the results (final stack state and benchmark results).


8. ****Functions used in the file "main_algorithm_utils3.c":****

   **● init_algo_arrays:**

   Sets up two arrays from the flags. One array indicates which algorithms are enabled (simple, medium, complex, adaptive) and the other array stores the order in which they should run. This prepares the data needed to run multiple algorithms in the correct sequence.

   **● find_next_algorithm:**

   Finds which algorithm should be executed next by looking for the enabled algorithm with the lowest order number. Returns the index (0-3) of that algorithm or -1 if no more algorithms are left to run.

   **● run_one_algorithm:**

   Runs a single algorithm on a temporary copy of the stack. Saves the original disorder state of the stack, then copies "stack a" to a temporary stack and resets "stack b" to empty. Sets up the "benchmark mode" for this algorithm if it is running and prints the initial disorder. Finally, it runs the algorithm using "run_algorithm_with_header". This allows multiple algorithms to run on the same original data without affecting each other.

   **● run_multiple_algorithms:**

   Responsible for running multiple sorting algorithms on the same input data. Sets up the algorithm, organises the arrays and creates a temporary stack. Loops through the algorithms to find the next  algorithm to run (based on order), prints a separator line between two algorithm outputs (if it is not the first), runs that algorithm on a fresh copy of the data and marks the algorithm as completed. Finally, it frees the temporary stack when finished.


9. ****Functions used in the file "main_algorithm_utils4.c":****

   **● set_simple_strategy:**

   Sets the benchmark metadata for the simple algorithm. It assigns the strategy name "Insertion sort" and the complexity class "O(n^2)" (quadratic time complexity).

   **● set_medium_strategy:**

   Sets the benchmark metadata for the medium algorithm. It assigns the strategy name "Bucket sort" and the complexity class "O(n√n)" (better than quadratic, worse than linearithmic).

   **● set_complex_strategy:**

   Sets the benchmark metadata for the complex algorithm. It assigns the strategy name "Turk sort" and the complexity class "O(n log n)" (linearithmic time complexity - efficient).

   **● set_adaptive_strategy:**

   Sets the benchmark metadata for the adaptive algorithm. It assigns the strategy name "Adaptive" and the complexity class based on which algorithm it chooses.

   **● set_strategy_name:**

   A dispatcher function that calls the appropriate strategy typesetter based on an algorithm index (For 0 → Simple (Insertion sort) / For 1 → Medium (Bucket sort) / For 2 → Complex (Turk sort) / For 3 → Adaptive).


10. ****Functions used in the file "main_sorting1.c":****

    **● run_medium_first:**

    Runs the medium algorithm (bucket sort) and displays its results, then resets everything to run another algorithm afterwards:

    → Prints the initial disorder, the initial stack state and the "MEDIUM" header

    → Sets up the "benchmark mode" with the bucket sort metadata

    → Runs the bucket sort

    → Prints the results, the benchmark stats and a separator line

    → Prints the initial disorder and the initial stack state again with the "SIMPLE" header (preparing for the next used algorithm)

    **● run_simple_first:**

    Runs the simple algorithm (insertion sort) and displays its results, then resets everything to run another algorithm afterwards:

    → Prints the initial disorder, the initial stack state and the "SIMPLE" header

    → Sets up the "benchmark mode" with the insertion sort metadata

    → Runs the insertion sort

    → Prints the results, the benchmark stats and a separator line

    → Prints the initial disorder and the initial stack state again with the "MEDIUM" header (preparing for the next used algorithm)

    **● execute_medium_then_simple:**

    Runs the medium algorithm (bucket sort) first, then runs the simple algorithm (insertion sort) on a fresh copy of the original data:

    → Creates a temporary copy of "stack a"

    → Runs the medium algorithm (bucket sort) on the original stack

    → Resets "stack a" back to the original state using the copy

    → Runs the simple algorithm (insertion sort) on the fresh data

    → Cleans up the temporary stack

    **● execute_simple_then_medium:**

    Runs the simple algorithm (insertion sort) first, then runs the medium algorithm (bucket sort) on a fresh copy of the original data:

    → Creates a temporary copy of "stack a"

    → Runs the simple algorithm (insertion sort) on the original stack

    → Resets "stack a" back to the original state using the copy

    → Runs the medium algorithm (bucket sort) on the fresh data

    → Cleans up the temporary stack

    **● run_both_algorithms:**

    Decides in which order to run the simple and the medium algorithm based on the order of the command-line flags. If "medium_order" is lower than "simple_order", it runs the medium algorithm first. Otherwise, it runs the simple algorithm first.


11. ****Functions used in the file "main_sorting2.c":****

    **● finish_medium_first:**

    Completes the second half of "run_both_algorithms" when medium algorithm (bucket sort) was run first:

    → Runs the simple algorithm (insertion sort)

    → Prints a newline for spacing

    → Displays the final stack state

    → Shows the benchmark results for the second run

    This is called after "run_medium_first" to complete the comparison.

    **● finish_simple_first:**

    Completes the second half of "run_both_algorithms" when simple algorithm (insertion sort) was run first:

    → Runs the medium algorithm (bucket sort)

    → Prints a newline for spacing

    → Displays the final stack state

    → Shows the benchmark results for the second run

    This is called after "run_simple_first" to complete the comparison.


12. ****Functions used in the file "main_utils.c":****

    **● is_flag:**

    Checks if an argument is a flag (starts with --). Returns 1 if it's a flag, returns 0 if it is not.

    **● count_words_in_string:**

    Counts how many space / tab-separated words are in a string. Keeps track if it is currently inside a word.

    **● count_numbers:**

    Counts the total numbers in all command-line arguments. Skips if the argument is a flag (like --simple). If it is not, it counts all elements in the argument. Then it returns the total number count.

    **● handle_errors:**

    Checks for basic errors at the beginning (If less than 2 arguments (no numbers provided), if invalid input or if no numbers after parsing). Returns 1 if an error was found, returns 0 if everything is correct.

    **● check_stacks_and_duplicates:**

    Validates the stacks after the creation. Checks if either stack is NULL (creation failed) and if "stack a" has duplicate numbers. If an error was found, it frees both stacks, then writes "Error" and returns 1. Returns 0 if everything is correct.


13. ****Functions used in the file "main.c":****

    **● execute_algorithm:**

    Chooses the order of the used algorithms based on which flag is enabled. It checks in priority order (Complex (Turk sort) - if enabled / Medium (Bucket sort) - if enabled / Adaptive - if enabled / Simple (Insertion sort) - default if nothing else is enabled).

    **● run_sorting:**

    Main sorting function that decides how to run the sorting based on the flags. It handles different scenarios:

    → Benchmark mode with no algorithm specified: Just runs a default algorithm and displays the result

    → Multiple algorithms enabled (2+): Runs the algorithms in order for comparison using "run_multiple_algorithms"

    → Single algorithm enabled: Runs the appropriate algorithm (simple, medium, complex, or adaptive)

    → No valid flags: Prints an error

    **● main:**

    The main function of the project that coordinates everything:

    → Initialize flags: Sets all flags to default values (0)

    → Parse command-line flags: Analyses the used flags

    → Count numbers: Determines how many numbers need to be sorted

    → Error handling: Checks for invalid input (duplicates, non-numbers or empty input)

    → Create stacks: Implements the numbers into "stack a", then creates an empty "stack b"

    → Validation: Checks if both stacks are valid and no duplicates exist

    → Sorting: Calls "setup_and_sort" which runs the selected algorithm

    → Cleanup: Frees both stacks

    → Exit: Returns 0 on success, returns 1 on error

---

****"Libft" folder:****

---

This folder contains a library of all previously self-implemented functions (with the corresponding C-files, header files and a Makefile to compile the "Libft").

---

## Instructions

### Compilation

To compile the executable file "push_swap", use the provided Makefile by typing the following commands in your terminal:

- **`make`** - Create the object files (.o) of the functions and compiles the library "libft.a" inside the "Libft" folder + the executable file "push_swap"
- **`make clean`** - Remove the object files (.o) of the functions
- **`make fclean`** - Remove the object files (.o) of the functions and the library "libft.a" inside the "Libft" folder + the executable file "push_swap"
- **`make re`** - Recompiles everything from scratch

---

### Compilation Flags

The library "libft.a" inside the "Libft" folder and the executable file "push_swap" are compiled with the following flags:

- **`-Wall`** - Enable all warnings
- **`-Wextra`** - Enable extra warnings
- **`-Werror`** - Treat warnings as errors

---

### Installation

1. Clone the push_swap project to your local computer using `git clone {git repository link} {customized name}` in your terminal.

2. Navigate to the project directory using `cd {directory name of the project folder}` in your terminal.

3. Run the command `make` in your terminal to create the object files (.o) of the functions, to compile the library "libft.a" and the executable file "push_swap".

4. The compiled version of the library "libft.a" will be created inside the "Libft" folder and the compiled version of the executable file "push_swap" will be created in the project directory.

---

### Execution

To run the project "push_swap" with any sorting algorithm, compile the program using:

```bash
make
./push_swap {algorithm flag} {customized arguments}
```

---

To run the project "push_swap" with the "benchmark mode", compile the program using:

```bash
make
./push_swap --bench {customized arguments}
```

---

To run the project "push_swap" with any sorting algorithm + the "benchmark mode", compile the program using:

```bash
make
./push_swap {algorithm flag} --bench {customized arguments}
```

---

### Test

**To verify if a sorting algorithm works properly, compile the program with the "checker_linux" program using:**

● For 100 random numbers:

```bash
make
ARG=$(shuf <(seq -5000 5000) -n 100 | tr '\n' ' '); ./push_swap {algorithm flag} --quiet $ARG | ./checker_linux $ARG
```

● For 500 random numbers:

```bash
make
ARG=$(shuf <(seq -5000 5000) -n 500 | tr '\n' ' '); ./push_swap {algorithm flag} --quiet $ARG | ./checker_linux $ARG
```

---

**To analyse the performance of a sorting algorithm, compile the program using:**

● For 100 random numbers:

```bash
make
ARG=$(shuf <(seq -5000 5000) -n 100 | tr '\n' ' '); ./push_swap {algorithm flag} $ARG | wc -l
```

● For 500 random numbers:

```bash
make
ARG=$(shuf <(seq -5000 5000) -n 500 | tr '\n' ' '); ./push_swap {algorithm flag} $ARG | wc -l
```

---

##Detailed explanation and justification of the selected algorithms

---

## 1. Insertion Sort (Simple Algorithm)

### Algorithm Overview
Insertion Sort builds the sorted array one element at a time by repeatedly finding the maximum element in stack A and rotating it to the top, then pushing it to stack B. After all elements are in B (in descending order), they are pushed back to A (resulting in ascending order).

### Implementation Details

```
While stack A is not empty:
    1. Find the position of the maximum element
    2. Rotate stack A to bring max to top (using ra or rra, whichever is shorter)
    3. Push max to stack B (pb)
After all elements in B:
    4. Push all back to A (repeated pa)
```

### Time Complexity Analysis

- **Best Case:** O(n²)
- **Average Case:** O(n²)
- **Worst Case:** O(n²)

### Space Complexity

- O(1)

### Justification for Selection

**Why Insertion Sort for small inputs (<= 5 elements)?**

1. **Simplicity:** Clean, understandable code that's easy to verify for correctness
2. **Low Operation Count for smaller inputs:** For 3-5 elements, the O(n²) complexity is negligible
3. **Predictable Behavior:** Always produces correct results with minimal edge cases
4. **Norminette Compliance:** Simple logic fits easily within 25-line function limits
5. **No Memory Overhead:** Uses only the provided stacks

**Negative points:**

- Poor scaling for large inputs (abandoned at n > 10)
- Not optimal even for small inputs (Selection Sort sometimes better)
- Simple but not the absolute minimum operations possible

### When Used

- Explicitly via `--simple` flag
- Automatically used in adaptive mode when disorder < 0.2
- Testing and benchmarking comparisons

---

## 2. Selection Sort (Alternative Simple Algorithm)

### Algorithm Overview

Selection Sort repeatedly finds the minimum element and rotates it to the correct position. It's similar to Insertion Sort but often requires fewer operations for small, partially sorted inputs.

### Implementation Details

```
While stack A is not empty:
    1. Find the position of the minimum element
    2. Rotate A to bring min to top (ra or rra, optimized)
    3. Push min to B (pb)
After all in B (ascending):
    4. Push all back to A (repeated pa)
```

### Time Complexity Analysis

- **Best Case:** O(n²)
- **Average Case:** O(n²)
- **Worst Case:** O(n²)

### Space Complexity

- O(1)


### Justification for Selection

**Why include Selection Sort alongside Insertion Sort?**

1. **Complementary Strengths:** Sometimes produces fewer operations than Insertion Sort
2. **Educational Value:** Demonstrates different approaches to the same problem
3. **Benchmark Comparison:** Allows testing which simple algorithm performs better
4. **Code Diversity:** Shows mastery of multiple sorting approaches

**Negative points:**

- Still O(n²), not suitable for large inputs
- Added code complexity for minimal gain

### When Used

- Internal implementation detail (not exposed as primary algorithm)
- Comparison benchmarks
- Can be selected manually for testing

---

## 3. Bucket Sort (Medium Algorithm)

### Algorithm Overview

Bucket Sort divides the input range into √n buckets and distributes elements accordingly. Elements are pushed to stack B in chunks, then retrieved in sorted order with optimizations to minimize rotations.

### Implementation Details

```
1. Calculate number of buckets (√n)
2. Divide value range [min, max] into number of buckets
3. For each chunk:
   - Push all elements to chunk 0 (current chunk B)
   - Optimize with sa / sb swaps when beneficial
4. While B is not empty:
   - Find maximum in B
   - Rotate B to bring max to top (optimized rotation)
   - Push to A (pa)
```

### Time Complexity Analysis

- **Best Case:** O(n√n)
- **Average Case:** O(n√n)
- **Worst Case:** O(n²)

### Space Complexity

- O(1)

### Justification for Selection

**Why Bucket Sort for medium inputs (10-150 elements)?**

1. **Sweet Spot Performance:** O(n√n) is significantly better than O(n²) for 50 to 100 numbers
2. **Predictable Behavior:** Bucket-based approach has consistent performance
3. **Better than Simple, Simpler than Complex:** Bridges the gap between algorithms
4. **Adaptive Optimization:** Can swap elements (sa / sb) to reduce operations
5. **Range Independence:** Works well regardless of value distribution

**Key Optimizations Implemented:**

- **Rotation Optimization:** Choose ra vs rra based on distance
- **Swap Optimization:** Use sa / sb when top two elements are out of order
- **Chunk Processing:** Process buckets incrementally to reduce total rotations
- **Dual-Stack Rotation:** Use rr / rrr when both stacks need rotation

**Negative points:**

- More complex than simple algorithms (harder to debug)
- Not optimal for very large inputs (Turk Sort better)
- Requires careful bucket calculation to avoid edge cases

### When Used

- Explicitly via `--medium` flag
- Automatically in adaptive mode when 0.2 <= disorder < 0.5
- Default choice for 50 to 100 element ranges

---

## 4. Turk Sort (Complex Algorithm)

### Algorithm Overview

Turk Sort is a greedy algorithm that uses a cost-based approach to determine which element from A to push to B next. It calculates the "cost" (number of operations) to push each element and always selects the cheapest option. This results in near-optimal performance for large inputs.

### Implementation Details

```
- Phase 1: Push to B (keep B sorted descending)

1. Push first 2 elements to B
2. For each remaining element in A:
   → Calculate cost to push each element:
      - Cost = rotations in A + rotations in B + 1 (pb)
      - Consider both ra and rra for A
      - Consider both rb and rrb for B
      - Optimize with rr / rrr when rotating both
   → Find cheapest element
   → Execute optimal rotation sequence
   → Push to B (pb)

- Phase 2: Push back to A (A becomes sorted ascending)

1. While B is not empty:
   → Find position in A where B's top fits
   → Rotate A to correct position
   → Push to A (pa)
2. Final rotation: Move minimum to top of A
```

### Time Complexity Analysis

- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n²)

### Space Complexity

- O(1)

### Justification for Selection

**Why Turk Sort for large inputs (100+ elements)?**

1. **Optimal Performance:** Consistently achieves <700 operations for 100 numbers
2. **Greedy Cost-Based:** Always makes the locally optimal choice
3. **Scalability:** O(n log n) means it scales well to 500+ elements
4. **Industry Standard:** Similar to real-world sorting optimizations

**Key Optimizations Implemented:**

1. **Cost Calculation Optimization:**
   ```c
   cost = min(pos_a, size_a - pos_a) + min(pos_b, size_b - pos_b)
   // Choose ra vs rra, rb vs rrb based on which is shorter
   ```

2. **Dual Rotation Optimization:**
   ```c
   // When both stacks rotate same direction, use rr / rrr
   if (rotating_a_up && rotating_b_up)
       use rr instead of ra + rb  // Saves 1 operation per pair
   ```

3. **Position Finding:**
   - Find ideal insertion position in O(n) by comparing values
   - Maintain sorted order in B (descending) during Phase 1

4. **Final Rotation:**
   - After all elements back in A, rotate minimum to top
   - O(n) final pass to ensure sorted order

**Negative points:**

- Most complex implementation (~200+ lines across multiple files)
- Harder to debug and verify correctness
- Requires careful cost calculation to avoid errors
- Multiple helper functions needed (increases code size)

### When Used

- **Default algorithm** when no flags specified
- Explicitly via `--complex` flag
- Automatically in adaptive mode when disorder >= 0.5
- Recommended for all inputs > 50 elements

---

## Comparison

### Operation Count by Input Size

| Input Size |Simple (O(n²)) | Medium (O(n√n)) |  Complex (O(n log n)) | Best Choice |
|------------|---------------|-----------------|-----------------------|-------------|
| 3          | 2-3           | 2-3             | 2-3                   |   Simple    |
| 5          | 7-12          | 7-12            | 8-12                  |   Simple    |
| 10         | 30-50         | 40-60           | 25-35                 |   Medium    |
| 50         | 600-800       | 450-550         | 350-450               |   Medium    |
| 100        | 2000-2500     | 900-1100        | 630-703               |   Complex   |
| 500        | 50000+        | 7000-9000       | 5400-5800             |   Complex   |

### Time Complexity Summary

| Algorithm      | Best Case | Average Case | Worst Case | Space    |
|----------------|-----------|--------------|------------|----------|
| Insertion Sort | O(n²)     | O(n²)        | O(n²)      | O(1)     |
| Selection Sort | O(n²)     | O(n²)        | O(n²)      | O(1)     |
| Bucket Sort    | O(n√n)    | O(n√n)       | O(n²)      | O(1)     |
| Turk Sort      | O(n log n)| O(n log n)   | O(n²)      | O(1)     |

---

### Performance Achievements

- **100 numbers:** Average 652 operations (target: <700)
- **500 numbers:** Average 5594 operations (target: <5500)
- **Norminette compliant**
- **No memory leaks**

---

## Bonus Part

### Description

The bonus part of this project requires the creation of our own "checker" program using only one static variable inside of the function itself. Furthermore, the function is allowed to manage multiple file descriptors at the same time.


### Brief Overview

---

### ► Header file:

---

**checker_bonus.h:**

A header file which contains all the function prototypes and includes statements (project header) to create the executable "checker" file.

---

### ► All functions used for the bonus part:

---

1. **Functions used in the file "get_next_line_utils_for_push_swap_bonus.c":**

   **● strchr:**

   Finds the first occurrence of a character in a string.

   **● strdup:**

   Duplicates a string (allocates memory).


2. **Functions used in the file "get_next_line_for_push_swap_bonus.c":**

   **● strjoin_gnl:**

   Joins two strings into a new string.

   **● extract_line:**

   Extracts one line from the buffer.

   **● update_buffer:**

   Removes the extracted line from the buffer, keeping only what comes after the newline.

   **● read_buffer:**

   Reads data from a file descriptor into the buffer until a complete line is found (contains a newline) or the file ends.

   **● get_next_line:**

   Returns one line at a time from a file.


3. **Functions used in the file "checker_operations_bonus.c":**

   **● exec_swap_ops:**

   Executes swap operations by checking which swap command was received.

   **● exec_push_ops:**

   Executes push operations by checking which push command was received.

   **● exec_rotate_ops:**

   Executes upward rotate operations by checking which rotate command was received.

   **● exec_reverse_ops:**

   Executes downward rotate operations by checking which reverse rotate command was received.

   **● exec_operation:**

   Executes any valid operation.


4. **Functions used in the file "checker_bonus.c":**

   **● check_result:**

   Verifies if the sorting was successful by checking two conditions:

 → "stack b" must be empty (all elements should be back in "stack a")

 → "stack a" must be sorted in ascending order

   **● handle_error:**

   Handles errors by cleaning up resources and exiting.

   **● read_and_execute:**

   Reads the operations from the standard input (stdin) and executes them one by one.

   **● validate_input:**

   Validates the command-line arguments before processing.

   **● main:**

   The main function that coordinates the checker:

 → Validates the input: Check if arguments are valid

 → Early exit: If validation returned 0 or 1, it exits with that status

 → Counts numbers: Determines how many numbers to sort

 → Parses and creates stacks: Converts arguments to "stack a" and creates an empty "stack b"

 → Checks for errors: Verifies if the stacks are valid and no duplicates exists

 → Reads operations: Calls "read_and_execute" to process all operations from stdin

 → Checks result: Verifies if the stack is correctly sorted

 → Outputs result: Writes "OK\n" if sorted correctly, writes "KO\n" if not sorted correctly

 → Cleanup: Frees both stacks

 → Exit: Returns 0 (success)

---

## Instructions

### Compilation

To compile the executable file "checker", use the provided Makefile by typing the following commands in your terminal:

- **`make bonus`** - Create the necessary object files (.o) of the functions and compiles the library "libft.a" inside the "Libft" folder + the executable file "checker"
- **`make clean`** - Remove the necessary object files (.o) of the functions
- **`make fclean`** - Remove the necessary object files (.o) of the functions and the library "libft.a" inside the "Libft" folder + the executable file "checker"
- **`make re`** - Recompiles everything from scratch

---

### Compilation Flags

The executable file "checker" is compiled with the following flags:

- **`-Wall`** - Enable all warnings
- **`-Wextra`** - Enable extra warnings
- **`-Werror`** - Treat warnings as errors

---

### Execution

To run the "checker" program with any sorting algorithm, compile the program using:

```bash
make
./push_swap {algorithm flag} {customized arguments} | ./checker {customized arguments}
```

---

### Test

**To verify if the "checker" program works properly, compile the program using:**

● For 100 random numbers:

```bash
make + make bonus
ARG=$(shuf <(seq -5000 5000) -n 100 | tr '\n' ' '); ./push_swap {algorithm flag} $ARG | ./checker $ARG
```

● For 500 random numbers:

```bash
make + make bonus
ARG=$(shuf <(seq -5000 5000) -n 500 | tr '\n' ' '); ./push_swap {algorithm flag} $ARG | ./checker $ARG
```

● Using my own test files:

- Output "OK":

```bash
make bonus
./checker 3 2 1 < test_bonus_OK(Input 3 2 1).txt
```

- Output "KO":

```bash
make bonus
./checker 3 2 1 < test_bonus_KO(Input 3 2 1).txt
```

- Output "Error":

```bash
make bonus
./checker 3 2 1 < test_bonus_Error(Input 3 2 1).txt
```

---

## Resources

### General Resources

- AI assistant app **Claude.ai** for the explanation of some parts of the project "push_swap"

### Specific Research

**For explanation of the key principle and the composition of the project “push_swap”:**

- https://42-cursus.gitbook.io/guide/2-rank-02/push_swap
- https://github.com/OliverKingz/push_swap
- https://www.youtube.com/watch?v=OaG81sDEpVk

**For explanation of stack implementation:**

- https://www.youtube.com/watch?v=Flk5yrlx5Qo

**For explanation of the different operations (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr):**

- https://www.youtube.com/watch?v=4dMsuxfqufg

**For explanation of the Phony implementation in a Makefile:**

- https://www.youtube.com/watch?v=GO0MHokQn-E

**For explanation of all types of sorting algorithms:**

- https://www.youtube.com/watch?v=rbbTd-gkajw

**For explanation of simple sorting algorithms:**

- https://www.eecs.umich.edu/courses/eecs281/f04/lecnotes/10-elementary%20sorting.pdf
- https://www.geeksforgeeks.org/dsa/comparison-among-bubble-sort-selection-sort-and-insertion-sort/

**→ For insertion sort:**

- https://www.youtube.com/watch?v=JU767SDMDvA
- https://www.youtube.com/watch?v=nKzEJWbkPbQ

**→ For selection sort:**

- https://www.youtube.com/watch?v=EwjnF7rFLns

**→ For bubble sort:**

- https://www.youtube.com/watch?v=p__ETf2CKY4

**For explanation of medium sorting algorithms:**

**→ For block-based sorting:**

- https://www.youtube.com/watch?v=InGeRuRk3f8

**→ For bucket sort:**

- https://www.youtube.com/watch?v=xeT31rm3bN0
- https://www.geeksforgeeks.org/dsa/bucket-sort-2/

**For explanation of complex sorting algorithms:**

**→ For turk sort:**

- "The Art of Computer Programming" by Donald E. Knuth (Book)
- "Introduction to Algorithms" by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest and Clifford Stein (Book)
- "Analysis of Algorithms" by Jeffrey J. McConnell (Book)
- https://arxiv.org/abs/1907.08142

**For explanation of benchmark mode:**

- https://en.wikipedia.org/wiki/Benchmark_(computing)


