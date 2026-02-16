/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm_turksort.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 22:57:41 by sthinnes          #+#    #+#             */
/*   Updated: 2026/02/08 22:57:47 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

static void	sort_three(t_stack *a, t_benchmark *b)
{
	if (a->size == 2 && a->collection[0] > a->collection[1])
		sa(a, b);
	else if (a->size == 3)
	{
		if (a->collection[0] > a->collection[1]
			&& a->collection[0] > a->collection[2])
			ra(a, b);
		else if (a->collection[1] > a->collection[2]
			&& a->collection[1] > a->collection[0])
			rra(a, b);
		if (a->collection[0] > a->collection[1])
			sa(a, b);
	}
}

void	turk_sort(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench)
{
	(void)flags;
	if (!stack_a || stack_a->size <= 1 || is_sorted(stack_a))
		return ;
	if (stack_a->size <= 3)
	{
		sort_three(stack_a, bench);
		return ;
	}
	pb(stack_a, stack_b, bench);
	pb(stack_a, stack_b, bench);
	if (stack_b->collection[0] < stack_b->collection[1])
		sb(stack_b, bench);
	while (stack_a->size > 3)
		push_cheapest_from_a(stack_a, stack_b, bench);
	sort_three(stack_a, bench);
	while (stack_b->size > 0)
	{
		rotate_both_optimally(stack_a, stack_b,
			find_cheapest_element(stack_a, stack_b), bench);
		pa(stack_a, stack_b, bench);
	}
	final_rotate_to_min(stack_a, bench);
}
