/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:26:13 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/22 22:26:17 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>
# include "flags.h"
# include "benchmark.h"

typedef struct s_stack
{
	int		*collection;
	int		capacity;
	int		size;
	double	disorder;
}	t_stack;

typedef struct s_bucket_info
{
	int		num_buckets;
	int		min;
	int		max;
	long	range;
	int		current_bucket;
}	t_bucket_info;

typedef struct s_rotate_ctx
{
	t_flags			*flags;
	t_benchmark		*bench;
}	t_rotate_ctx;

typedef struct s_chunk_ctx
{
	t_bucket_info	*info;
	t_benchmark		*bench;
	int				target_chunk;
}	t_chunk_ctx;

typedef struct s_pos_pair
{
	int	pos_a;
	int	pos_b;
}	t_pos_pair;

typedef struct s_multi_algo
{
	t_stack		*temp_a;
	t_benchmark	temp_bench;
	int			min_idx;
	int			i;
}	t_multi_algo;

typedef struct s_rotate_pair
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		pos_a;
	int		pos_b;
}	t_rotate_pair;

typedef struct s_rot_params
{
	int	pa;
	int	pb;
}	t_rot_params;

typedef struct s_find_pos
{
	int	best_pos;
	int	min_diff;
	int	min_pos;
	int	min_val;
}	t_find_pos;

typedef struct s_algo_ctx
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_flags		*flags;
	t_benchmark	*bench;
}	t_algo_ctx;

//Benchmark mode
void	make_benchmark(t_benchmark *bench, t_stack *stack_a,
			t_flags *flags);
//Sorting operations
void	sa(t_stack *stack_a, t_benchmark *bench);
void	sb(t_stack *stack_b, t_benchmark *bench);
void	ss(t_stack *stack_a, t_stack *stack_b, t_benchmark *bench);
void	pa(t_stack *stack_a, t_stack *stack_b, t_benchmark *bench);
void	pb(t_stack *stack_a, t_stack *stack_b, t_benchmark *bench);
void	ra(t_stack *stack_a, t_benchmark *bench);
void	rb(t_stack *stack_b, t_benchmark *bench);
void	rr(t_stack *stack_a, t_stack *stack_b, t_benchmark *bench);
void	rra(t_stack *stack_a, t_benchmark *bench);
void	rrb(t_stack *stack_b, t_benchmark *bench);
void	rrr(t_stack *stack_a, t_stack *stack_b, t_benchmark *bench);
//Error output
int		check_if_numbers(int argc, char **argv);
int		check_if_outside_valid_range(int argc, char **argv);
int		check_for_duplicates(t_stack *stack_a);
//Creation of "stack a" and "stack b"
t_stack	*create_stack(int capacity);
void	stack_add_bottom(t_stack *stack, int value);
int		has_space(char *str);
void	parse_split_arg(char *arg, t_stack *stack);
void	process_argument(char *arg, t_stack *stack);
t_stack	*parse_arguments(int argc, char **argv);
void	print_stack(t_stack *stack_a, t_stack *stack_b);
//Disorder metric
double	compute_disorder(int *stack_a, int size);
//Insertion sort algorithm
int		find_max_position(t_stack *stack);
void	insertion_sort(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench);
//Selection sort algorithm
int		find_min_position(t_stack *stack);
void	rotate_to_min(t_stack *stack_a, int min_pos, t_flags *flags,
			t_benchmark *bench);
void	selection_sort(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench);
//Bucket sort algorithm
void	optimize_with_swap(t_stack *stack_a, t_stack *stack_b,
			t_rotate_ctx *ctx);
void	rotate_both_stacks(t_stack *stack_a, t_stack *stack_b,
			t_rotate_ctx *ctx, int pos_data);
int		find_min_in_array(int *arr, int n);
int		find_max_in_array(int *arr, int n);
void	rotate_to_position_b(t_stack *stack_b, int pos,
			t_rotate_ctx *ctx);
void	rotate_to_position_a(t_stack *stack_a, int pos,
			t_rotate_ctx *ctx);
int		find_insert_position_a(t_stack *stack_a, int value);
void	bucket_sort(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench);
//Turk sort algorithm
int		find_pos_in_b(t_stack *stack_b, int value);
int		calc_push_count(int pos_a, int pos_b, t_stack *a, t_stack *b);
int		find_cheapest_in_a(t_stack *stack_a, t_stack *stack_b);
void	push_cheapest_from_a(t_stack *stack_a, t_stack *stack_b,
			t_benchmark *bench);
void	rotate_both_optimally(t_stack *stack_a, t_stack *stack_b,
			int pos_b, t_benchmark *bench);
void	final_rotate_to_min(t_stack *stack_a, t_benchmark *bench);
int		find_cheapest_element(t_stack *stack_a, t_stack *stack_b);
int		find_ideal_pos_in_a(t_stack *stack_a, int value);
void	turk_sort(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench);
//Adaptive sorting algorithm
void	adaptive_algorithm(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench);
//Main
void	print_disorder(double disorder);
void	copy_stack(t_stack *dest, t_stack *src);
int		is_sorted(t_stack *stack);
int		error_output(int argc, char **argv);
void	free_stack(t_stack *stack);
void	print_header(t_flags *flags, int is_medium);
void	run_single_simple(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench);
void	run_single_medium(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench);
void	setup_and_sort(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench);
void	run_single_complex(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench);
void	run_single_adaptive(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench);
void	run_algorithm_with_header(t_algo_ctx *ctx, int algo_type);
void	run_multiple_algorithms(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench);
void	set_strategy_name(t_benchmark *bench, int algo_idx);
void	run_medium_first(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench);
void	run_simple_first(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench);
void	execute_medium_then_simple(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench);
void	execute_simple_then_medium(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench);
void	run_both_algorithms(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench);
void	finish_medium_first(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench2);
void	finish_simple_first(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench2);
int		is_flag(char *arg);
int		count_numbers(int argc, char **argv);
int		handle_errors(int argc, char **argv, int num_count);
int		check_stacks_and_duplicates(t_stack *stack_a, t_stack *stack_b);
void	run_sorting(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench);
int		main(int argc, char **argv);
//Libft
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
int		ft_printf(const char *format, ...);
#endif
