/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm_bucketsort.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:37:45 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/27 17:37:50 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"
#include <math.h>

static int	get_chunk(int value, int min, int max, int num_chunks)
{
	long	range;
	long	val;
	long	min_val;
	int		chunk;

	if (max == min)
		return (0);
	range = (long)max - (long)min;
	val = (long)value;
	min_val = (long)min;
	chunk = ((val - min_val) * num_chunks) / (range + 1);
	if (chunk >= num_chunks)
		chunk = num_chunks - 1;
	return (chunk);
}

static void	push_chunk_to_b(t_stack *stack_a, t_stack *stack_b,
				t_chunk_ctx *ctx)
{
	int	initial_size;
	int	pushed;
	int	chunk;

	initial_size = stack_a->size;
	pushed = 0;
	while (pushed < initial_size)
	{
		chunk = get_chunk(stack_a->collection[0], ctx->info->min,
				ctx->info->max, ctx->info->num_buckets);
		if (chunk <= ctx->target_chunk)
		{
			pb(stack_a, stack_b, ctx->bench);
			if (stack_b->size > 1 && chunk < ctx->target_chunk)
				rb(stack_b, ctx->bench);
		}
		else
			ra(stack_a, ctx->bench);
		pushed++;
	}
}

static void	push_back_to_a(t_stack *stack_a, t_stack *stack_b,
				t_rotate_ctx *ctx)
{
	int	max_pos;
	int	i;
	int	max_val;

	while (stack_b->size > 0)
	{
		max_pos = 0;
		max_val = stack_b->collection[0];
		i = 1;
		while (i < stack_b->size)
		{
			if (stack_b->collection[i] > max_val)
			{
				max_val = stack_b->collection[i];
				max_pos = i;
			}
			i++;
		}
		rotate_to_position_b(stack_b, max_pos, ctx);
		pa(stack_a, stack_b, ctx->bench);
	}
}

void	bucket_sort(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench)
{
	t_bucket_info	info;
	t_rotate_ctx	ctx;
	t_chunk_ctx		chunk_ctx;

	ctx.flags = flags;
	ctx.bench = bench;
	if (!stack_a || stack_a->size <= 1 || is_sorted(stack_a))
		return ;
	info.num_buckets = (int)ceil(sqrt(stack_a->size));
	if (info.num_buckets < 2)
		info.num_buckets = 2;
	if (info.num_buckets > 12)
		info.num_buckets = 12;
	info.min = find_min_in_array(stack_a->collection, stack_a->size);
	info.max = find_max_in_array(stack_a->collection, stack_a->size);
	chunk_ctx.info = &info;
	chunk_ctx.bench = bench;
	chunk_ctx.target_chunk = 0;
	while (chunk_ctx.target_chunk < info.num_buckets && stack_a->size > 0)
	{
		push_chunk_to_b(stack_a, stack_b, &chunk_ctx);
		chunk_ctx.target_chunk++;
	}
	push_back_to_a(stack_a, stack_b, &ctx);
}
