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

typedef struct s_bucket
{
	int	*data;
	int	size;
	int	capacity;
}	t_bucket;

typedef struct s_bucket_data
{
	int			num_buckets;
	int			min_val;
	int			max_val;
	long long	bucket_range;
}	t_bucket_data;

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

typedef struct s_pos_pair
{
	int	pos_a;
	int	pos_b;
}	t_pos_pair;

t_stack	*create_stack(int capacity);
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
int		ft_printf(const char *format, ...);
void	stack_add_bottom(t_stack *stack, int value);
void	print_stack(t_stack *stack_a, t_stack *stack_b);
void	free_stack(t_stack *stack);
t_stack	*parse_arguments(int argc, char **argv);
void	copy_stack(t_stack *dest, t_stack *src);
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
int		find_max_position(t_stack *stack);
void	insertion_sort(t_stack *stack_a, t_stack *stack_b, t_flags *flags,
			t_benchmark *bench);
void	print_verbose(t_flags *flags, char *msg);
int		find_min_position(t_stack *stack);
void	rotate_to_min(t_stack *stack_a, int min_pos, t_flags *flags,
			t_benchmark *bench);
void	handle_bigger_case(t_stack *stack_a, t_stack *stack_b, t_flags *flags);
void	handle_smaller_case(t_stack *stack_a, t_stack *stack_b, t_flags *flags);
void	selection_sort(t_stack *stack_a, t_stack *stack_b, t_flags *flags,
			t_benchmark *bench);
void	bucket_sort(t_stack *stack_a, t_stack *stack_b, t_flags *flags,
			t_benchmark *bench);
void	push_all_to_b(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench);
int		find_in_bucket(t_stack *stack, int bucket, int min, int range);
void	rotate_to_position_b(t_stack *stack_b, int pos, t_rotate_ctx *ctx);
int		find_insert_position_a(t_stack *stack_a, int value);
void	rotate_to_position_a(t_stack *stack_a, int pos, t_rotate_ctx *ctx);
void	rotate_both_stacks(t_stack *stack_a, t_stack *stack_b,
			t_rotate_ctx *ctx, int pos_data);
void	optimize_with_swap(t_stack *stack_a, t_stack *stack_b,
			t_rotate_ctx *ctx);
void	process_bucket(t_stack *stack_a, t_stack *stack_b,
			t_bucket_info *info, t_rotate_ctx *ctx);
int		find_min_in_array(int *arr, int n);
int		find_max_in_array(int *arr, int n);
int		check_for_duplicates(t_stack *stack_a);
int		check_if_numbers(int argc, char **argv);
int		check_if_outside_valid_range(int argc, char **argv);
int		error_output(int argc, char **argv);
double	compute_disorder(int *stack_a, int size);
void	print_disorder(double disorder);
int		is_flag(char *arg);
int		count_numbers(int argc, char **argv);
void	make_benchmark(t_benchmark *bench, t_stack *stack_a, t_flags *flags);
int		handle_errors(int argc, char **argv, int num_count);
int		check_stacks_and_duplicates(t_stack *stack_a, t_stack *stack_b);
int		is_sorted(t_stack *stack);
int		main(int argc, char **argv);
int		has_space(char *str);
void	parse_split_arg(char *arg, t_stack *stack);
void	process_argument(char *arg, t_stack *stack);
#endif
