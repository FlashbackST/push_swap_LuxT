/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm_bucketsort_utils.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:36:09 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/27 17:36:13 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"
#include <math.h>

void	rotate_to_position_b(t_stack *stack_b, int pos, t_rotate_ctx *ctx)
{
	int	rotations;

	if (pos <= stack_b->size / 2)
	{
		while (pos-- > 0)
		{
			rb(stack_b, ctx->bench);
			print_verbose(ctx->flags, "rb\n");
		}
	}
	else
	{
		rotations = stack_b->size - pos;
		while (rotations-- > 0)
		{
			rrb(stack_b, ctx->bench);
			print_verbose(ctx->flags, "rrb\n");
		}
	}
}

void	rotate_to_position_a(t_stack *stack_a, int pos, t_rotate_ctx *ctx)
{
	int	rotations;

	if (pos <= stack_a->size / 2)
	{
		while (pos-- > 0)
		{
			ra(stack_a, ctx->bench);
			print_verbose(ctx->flags, "ra\n");
		}
	}
	else
	{
		rotations = stack_a->size - pos;
		while (rotations-- > 0)
		{
			rra(stack_a, ctx->bench);
			print_verbose(ctx->flags, "rra\n");
		}
	}
}

int	find_insert_position_a(t_stack *stack_a, int value)
{
	int	i;
	int	pos;

	if (stack_a->size == 0)
		return (0);
	pos = stack_a->size;
	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->collection[i] > value)
		{
			pos = i;
			break ;
		}
		i++;
	}
	return (pos);
}
