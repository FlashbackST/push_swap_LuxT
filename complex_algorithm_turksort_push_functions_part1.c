/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm_turksort_push_functions_part1.c  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 22:58:56 by sthinnes          #+#    #+#             */
/*   Updated: 2026/02/08 22:59:02 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

static int	find_min_in_b(t_stack *stack_b)
{
	int	best_val;
	int	best_pos;
	int	i;

	best_val = stack_b->collection[0];
	best_pos = 0;
	i = 1;
	while (i < stack_b->size)
	{
		if (stack_b->collection[i] < best_val)
		{
			best_val = stack_b->collection[i];
			best_pos = i;
		}
		i++;
	}
	return (best_pos);
}

int	find_pos_in_b(t_stack *stack_b, int value)
{
	int	i;
	int	best_pos;
	int	best_val;

	best_val = 2147483647;
	best_pos = 0;
	i = 0;
	while (i < stack_b->size)
	{
		if (stack_b->collection[i] > value
			&& stack_b->collection[i] < best_val)
		{
			best_val = stack_b->collection[i];
			best_pos = i;
		}
		i++;
	}
	if (best_val == 2147483647)
		best_pos = find_min_in_b(stack_b);
	return (best_pos);
}

static int	get_count(int pos, int size)
{
	int	count;

	count = pos;
	if (pos > size / 2)
		count = size - pos;
	return (count);
}

int	calc_push_count(int pos_a, int pos_b, t_stack *a, t_stack *b)
{
	int	count_a;
	int	count_b;

	count_a = get_count(pos_a, a->size);
	count_b = get_count(pos_b, b->size);
	if ((pos_a <= a->size / 2 && pos_b <= b->size / 2)
		|| (pos_a > a->size / 2 && pos_b > b->size / 2))
	{
		if (count_a > count_b)
			return (count_a);
		return (count_b);
	}
	return (count_a + count_b);
}

int	find_cheapest_in_a(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	cheapest;
	int	min_cost;
	int	cost;
	int	pos_b;

	i = 0;
	min_cost = 2147483647;
	cheapest = 0;
	while (i < stack_a->size)
	{
		pos_b = find_pos_in_b(stack_b, stack_a->collection[i]);
		cost = calc_push_count(i, pos_b, stack_a, stack_b);
		if (cost < min_cost || (cost == min_cost
				&& stack_a->collection[i] > stack_a->collection[cheapest]))
		{
			min_cost = cost;
			cheapest = i;
		}
		i++;
	}
	return (cheapest);
}
