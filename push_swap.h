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

t_stack	*create_stack(int capacity);
int		ft_atoi(const char *nptr);
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
int		check_for_duplicates(t_stack *stack_a);
int		check_if_numbers(int argc, char **argv);
int		check_if_outside_valid_range(int argc, char **argv);
int		error_output(int argc, char **argv);
double	compute_disorder(int *stack_a, int size);
void	print_disorder(double disorder);
int		is_flag(char *arg);
int		count_numbers(int argc, char **argv);
void	init_benchmark(t_benchmark *bench, t_stack *stack_a, t_flags *flags);
int		handle_errors(int argc, char **argv, int num_count);
int		check_stacks_and_duplicates(t_stack *stack_a, t_stack *stack_b);
int		main(int argc, char **argv);
#endif
