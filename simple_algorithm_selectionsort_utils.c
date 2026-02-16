/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm_selectionsort_utils.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:37:08 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/26 10:37:16 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

int	find_min_position(t_stack *stack)
{
	int	i;
	int	min_pos;
	int	min_value;

	if (!stack || stack->size == 0)
		return (-1);
	min_pos = 0;
	min_value = stack->collection[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->collection[i] < min_value)
		{
			min_value = stack->collection[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

void	rotate_to_min(t_stack *stack_a, int min_pos, t_flags *flags,
				t_benchmark *bench)
{
	int	min_value;
	int	size;

	(void)flags;
	min_value = stack_a->collection[min_pos];
	size = stack_a->size;
	if (min_pos <= size / 2)
	{
		while (stack_a->collection[0] != min_value)
			ra(stack_a, bench);
	}
	else
	{
		while (stack_a->collection[0] != min_value)
			rra(stack_a, bench);
	}
}
