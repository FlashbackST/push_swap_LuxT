/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm_insertionsort.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:54:15 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/25 12:54:20 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//include <stdio.h>

static int	find_insert_position(t_stack *stack_a, int value)
{
	int	i;
	int	best_pos;
	int	best_diff;

	if (stack_a->size == 0)
		return (0);
	best_pos = 0;
	best_diff = 2147483647;
	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->collection[i] > value
			&& stack_a->collection[i] - value < best_diff)
		{
			best_diff = stack_a->collection[i] - value;
			best_pos = i;
		}
		i++;
	}
	if (best_diff == 2147483647)
		return (find_max_position(stack_a) + 1);
	return (best_pos);
}

static void	rotate_to_position(t_stack *stack_a, int pos, t_flags *flags)
{
	int	size;

	size = stack_a->size;
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(stack_a);
			print_verbose(flags, "ra\n");
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(stack_a);
			print_verbose(flags, "rra\n");
			pos++;
		}
	}
}

void	insertion_sort(t_stack *stack_a, t_stack *stack_b, t_flags *flags)
{
	int	insert_pos;
	int	value;
	int	min_pos;

	if (!stack_a || stack_a->size <= 1)
		return ;
	while (stack_a->size > 0)
	{
		pb(stack_a, stack_b);
		print_verbose(flags, "pb\n");
	}
	while (stack_b->size > 0)
	{
		value = stack_b->collection[0];
		insert_pos = find_insert_position(stack_a, value);
		rotate_to_position(stack_a, insert_pos, flags);
		pa(stack_a, stack_b);
		print_verbose(flags, "pa\n");
	}
	min_pos = find_min_position(stack_a);
	rotate_to_position(stack_a, min_pos, flags);
}
