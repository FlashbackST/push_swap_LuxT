/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm_bucketsort_swap_functions.c       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:14:27 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/28 15:14:29 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

static int	can_swap_improve_a(t_stack *stack_a)
{
	if (stack_a->size < 2)
		return (0);
	return (stack_a->collection[0] > stack_a->collection[1]);
}

static int	can_swap_improve_b(t_stack *stack_b)
{
	if (stack_b->size < 2)
		return (0);
	return (stack_b->collection[0] < stack_b->collection[1]);
}

void	optimize_with_swap(t_stack *stack_a, t_stack *stack_b,
			t_rotate_ctx *ctx)
{
	int	swap_a;
	int	swap_b;

	swap_a = can_swap_improve_a(stack_a);
	swap_b = can_swap_improve_b(stack_b);
	if (swap_a && swap_b)
	{
		ss(stack_a, stack_b, ctx->bench);
	}
	else if (swap_a)
	{
		sa(stack_a, ctx->bench);
	}
	else if (swap_b)
	{
		sb(stack_b, ctx->bench);
	}
}
