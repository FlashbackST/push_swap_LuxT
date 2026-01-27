.PHONY: all clean fclean re libft

NAME	= push_swap
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I.
LIBFT_DIR = ./Updated\ Libft
LIBFT	= $(LIBFT_DIR)/libft.a
SRCS	= stack_add_bottom.c create_stack.c parse_arguments.c free_stack.c print_stack.c copy_stack.c swap_a.c swap_b.c swap_a+b.c push_a.c push_b.c rotate_a.c rotate_b.c rotate_a+b.c reverse_rotate_a.c reverse_rotate_b.c reverse_rotate_a+b.c simple_algorithm_insertionsort_utils.c simple_algorithm_selectionsort_utils.c simple_algorithm_selectionsort.c simple_algorithm_insertionsort.c flags.c check_for_duplicates.c check_if_numbers.c check_if_outside_valid_range.c error_output.c disorder_metric.c print_disorder.c benchmark_init.c benchmark_record.c benchmark_display.c benchmark_display_utils.c main_utils.c main.c
OBJS	= $(SRCS:.c=.o)
all: libft $(NAME)

libft:
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h benchmark.h flags.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

