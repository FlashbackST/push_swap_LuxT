/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm_turksort_counter.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 23:00:47 by sthinnes          #+#    #+#             */
/*   Updated: 2026/02/08 23:00:50 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

static int	get_moves_count(int pos, int size)
{
	int	moves;

	moves = pos;
	if (pos > size / 2)
		moves = size - pos;
	return (moves);
}

static int	calculate_combined_count(int pos_a, int pos_b,
				t_stack *stack_a, t_stack *stack_b)
{
	int	moves_a;
	int	moves_b;
	int	cost;

	moves_a = get_moves_count(pos_a, stack_a->size);
	moves_b = get_moves_count(pos_b, stack_b->size);
	if ((pos_a <= stack_a->size / 2 && pos_b <= stack_b->size / 2)
		|| (pos_a > stack_a->size / 2 && pos_b > stack_b->size / 2))
	{
		if (moves_a > moves_b)
			cost = moves_a;
		else
			cost = moves_b;
	}
	else
		cost = moves_a + moves_b;
	return (cost);
}

static int	calculate_count(t_stack *stack_a, t_stack *stack_b, int pos_b)
{
	int	value_b;
	int	pos_a;

	value_b = stack_b->collection[pos_b];
	pos_a = find_ideal_pos_in_a(stack_a, value_b);
	return (calculate_combined_count(pos_a, pos_b, stack_a, stack_b));
}

int	find_cheapest_element(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	min_cost_pos;
	int	min_cost;
	int	cost;

	min_cost = 2147483647;
	min_cost_pos = 0;
	i = 0;
	while (i < stack_b->size)
	{
		cost = calculate_count(stack_a, stack_b, i);
		if (cost < min_cost)
		{
			min_cost = cost;
			min_cost_pos = i;
		}
		i++;
	}
	return (min_cost_pos);
}
