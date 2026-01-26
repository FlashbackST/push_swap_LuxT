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

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>
# include "flags.h"

typedef struct s_stack
{
	int	*collection;
	int	capacity;
	int	size;
}	t_stack;

t_stack	*create_stack(int capacity);
int		ft_atoi(const char *nptr);
int		ft_printf(const char *format, ...);
void	stack_add_bottom(t_stack *stack, int value);
void	print_stack(t_stack *stack_a, t_stack *stack_b);
void	free_stack(t_stack *stack);
t_stack	*parse_arguments(int argc, char **argv);
void	copy_stack(t_stack *dest, t_stack *src);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
int		find_max_position(t_stack *stack);
void	insertion_sort(t_stack *stack_a, t_stack *stack_b, t_flags *flags);
void	print_verbose(t_flags *flags, char *msg);
int		find_min_position(t_stack *stack);
void	rotate_to_min(t_stack *stack_a, int min_pos, t_flags *flags);
void	handle_bigger_case(t_stack *stack_a, t_stack *stack_b, t_flags *flags);
void	handle_smaller_case(t_stack *stack_a, t_stack *stack_b, t_flags *flags);
void	selection_sort(t_stack *stack_a, t_stack *stack_b, t_flags *flags);
int		main(int argc, char **argv);
#endif
