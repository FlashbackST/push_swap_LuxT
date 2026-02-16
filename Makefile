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

