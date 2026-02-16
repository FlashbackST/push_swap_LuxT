/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm_bucketsort_rotate_functions.c     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:17:00 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/28 15:17:03 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

static void	do_rr_operations(t_stack *stack_a, t_stack *stack_b,
				t_pos_pair *pos, t_rotate_ctx *ctx)
{
	while (pos->pos_a > 0 && pos->pos_b > 0)
	{
		rr(stack_a, stack_b, ctx->bench);
		pos->pos_a--;
		pos->pos_b--;
	}
}

static void	do_rrr_operations(t_stack *stack_a, t_stack *stack_b,
				t_pos_pair *pos, t_rotate_ctx *ctx)
{
	int	size_a;
	int	size_b;

	size_a = stack_a->size;
	size_b = stack_b->size;
	while (pos->pos_a < size_a && pos->pos_b < size_b)
	{
		rrr(stack_a, stack_b, ctx->bench);
		pos->pos_a++;
		pos->pos_b++;
	}
}

void	rotate_both_stacks(t_stack *stack_a, t_stack *stack_b,
			t_rotate_ctx *ctx, int pos_data)
{
	t_pos_pair	pos;
	int			size_a;
	int			size_b;

	pos.pos_a = pos_data >> 16;
	pos.pos_b = pos_data & 0xFFFF;
	size_a = stack_a->size;
	size_b = stack_b->size;
	if (pos.pos_a <= size_a / 2 && pos.pos_b <= size_b / 2)
		do_rr_operations(stack_a, stack_b, &pos, ctx);
	else if (pos.pos_a > size_a / 2 && pos.pos_b > size_b / 2)
		do_rrr_operations(stack_a, stack_b, &pos, ctx);
	rotate_to_position_a(stack_a, pos.pos_a, ctx);
	rotate_to_position_b(stack_b, pos.pos_b, ctx);
}
