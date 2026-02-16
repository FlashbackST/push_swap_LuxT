/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm_turksort_push_functions_part2.c  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:15:41 by sthinnes          #+#    #+#             */
/*   Updated: 2026/02/10 17:15:43 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

static void	rotate_both_same_dir(t_stack *a, t_stack *b, t_rot_params *p,
				t_benchmark *bn)
{
	while (p->pa > 0 && p->pa <= a->size / 2
		&& p->pb > 0 && p->pb <= b->size / 2)
	{
		rr(a, b, bn);
		p->pa--;
		p->pb--;
	}
	while (p->pa > a->size / 2 && p->pb > b->size / 2
		&& p->pa < a->size && p->pb < b->size)
	{
		rrr(a, b, bn);
		p->pa++;
		p->pb++;
	}
}

static void	rotate_a_only(t_stack *a, int pa, t_benchmark *bn)
{
	while (pa > 0 && pa <= a->size / 2)
	{
		ra(a, bn);
		pa--;
	}
	while (pa > a->size / 2 && pa < a->size)
	{
		rra(a, bn);
		pa++;
	}
}

static void	rotate_b_only(t_stack *b, int pb, t_benchmark *bn)
{
	while (pb > 0 && pb <= b->size / 2)
	{
		rb(b, bn);
		pb--;
	}
	while (pb > b->size / 2 && pb < b->size)
	{
		rrb(b, bn);
		pb++;
	}
}

void	push_cheapest_from_a(t_stack *stack_a, t_stack *stack_b,
			t_benchmark *bench)
{
	t_rot_params	p;

	p.pa = find_cheapest_in_a(stack_a, stack_b);
	p.pb = find_pos_in_b(stack_b, stack_a->collection[p.pa]);
	rotate_both_same_dir(stack_a, stack_b, &p, bench);
	rotate_a_only(stack_a, p.pa, bench);
	rotate_b_only(stack_b, p.pb, bench);
	pb(stack_a, stack_b, bench);
}
