/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm_turksort_rotate_min.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:45:44 by sthinnes          #+#    #+#             */
/*   Updated: 2026/02/09 19:45:46 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

static int	find_min_pos(t_stack *stack_a)
{
	int	min_pos;
	int	min_val;
	int	i;

	min_pos = 0;
	min_val = stack_a->collection[0];
	i = 1;
	while (i < stack_a->size)
	{
		if (stack_a->collection[i] < min_val)
		{
			min_val = stack_a->collection[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

static void	rotate_min_to_top(t_stack *stack_a, int min_pos,
				t_benchmark *bench)
{
	while (min_pos != 0)
	{
		if (min_pos <= stack_a->size / 2)
		{
			ra(stack_a, bench);
			min_pos--;
		}
		else
		{
			rra(stack_a, bench);
			min_pos++;
			if (min_pos >= stack_a->size)
				min_pos = 0;
		}
	}
}

void	final_rotate_to_min(t_stack *stack_a, t_benchmark *bench)
{
	int	min_pos;

	if (!stack_a || stack_a->size == 0)
		return ;
	min_pos = find_min_pos(stack_a);
	rotate_min_to_top(stack_a, min_pos, bench);
}
