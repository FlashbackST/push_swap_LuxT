/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm_turksort_rotate_functions.c      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 22:59:22 by sthinnes          #+#    #+#             */
/*   Updated: 2026/02/08 22:59:26 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

static void	rotate_both_forward(t_rotate_pair *pair, t_benchmark *bench)
{
	while (pair->pos_a > 0 && pair->pos_b > 0)
	{
		rr(pair->stack_a, pair->stack_b, bench);
		(pair->pos_a)--;
		(pair->pos_b)--;
	}
}

static void	rotate_both_reverse(t_rotate_pair *pair, t_benchmark *bench)
{
	int	moves_a;
	int	moves_b;
	int	moves;

	moves_a = pair->stack_a->size - pair->pos_a;
	moves_b = pair->stack_b->size - pair->pos_b;
	if (moves_a < moves_b)
		moves = moves_a;
	else
		moves = moves_b;
	while (moves > 0)
	{
		rrr(pair->stack_a, pair->stack_b, bench);
		moves--;
	}
}

static void	rotate_b_to_top(t_stack *stack_b, int pos_b, t_benchmark *bench)
{
	if (pos_b == 0)
		return ;
	if (pos_b <= stack_b->size / 2)
	{
		while (pos_b > 0)
		{
			rb(stack_b, bench);
			pos_b--;
		}
	}
	else
	{
		while (pos_b < stack_b->size)
		{
			rrb(stack_b, bench);
			pos_b++;
		}
	}
}

static void	rotate_a_to_top(t_stack *stack_a, int pos_a, t_benchmark *bench)
{
	if (pos_a == 0)
		return ;
	if (pos_a <= stack_a->size / 2)
	{
		while (pos_a > 0)
		{
			ra(stack_a, bench);
			pos_a--;
		}
	}
	else
	{
		while (pos_a < stack_a->size)
		{
			rra(stack_a, bench);
			pos_a++;
		}
	}
}

void	rotate_both_optimally(t_stack *stack_a, t_stack *stack_b,
			int pos_b, t_benchmark *bench)
{
	t_rotate_pair	pair;

	pair.stack_a = stack_a;
	pair.stack_b = stack_b;
	pair.pos_a = find_ideal_pos_in_a(stack_a, stack_b->collection[pos_b]);
	pair.pos_b = pos_b;
	if (pair.pos_a <= stack_a->size / 2 && pos_b <= stack_b->size / 2)
		rotate_both_forward(&pair, bench);
	else if (pair.pos_a > stack_a->size / 2 && pos_b > stack_b->size / 2)
		rotate_both_reverse(&pair, bench);
	rotate_b_to_top(stack_b, pair.pos_b, bench);
	rotate_a_to_top(stack_a, pair.pos_a, bench);
}
