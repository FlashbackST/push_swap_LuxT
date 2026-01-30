/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm_bucketsort_main.c                 :+:      :+:    :+:   */
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

static int	get_bucket_num(int value, int min, long range, int num_buckets)
{
	long	bucket;
	long	val;
	long	min_val;

	if (range == 0)
		return (0);
	val = (long)value;
	min_val = (long)min;
	bucket = ((val - min_val) * num_buckets) / (range + 1);
	if (bucket >= num_buckets)
		bucket = num_buckets - 1;
	return ((int)bucket);
}

static int	find_max_in_bucket(t_stack *stack_b, int bucket,
				t_bucket_info *info)
{
	int	i;
	int	max_val;
	int	max_pos;
	int	elem_bucket;

	max_pos = -1;
	i = 0;
	while (i < stack_b->size)
	{
		elem_bucket = get_bucket_num(stack_b->collection[i],
				info->min, info->range, info->num_buckets);
		if (elem_bucket == bucket)
		{
			if (max_pos == -1 || stack_b->collection[i] > max_val)
			{
				max_val = stack_b->collection[i];
				max_pos = i;
			}
		}
		i++;
	}
	return (max_pos);
}

static void	push_bucket_to_a(t_stack *stack_a, t_stack *stack_b,
				t_bucket_info *info, t_rotate_ctx *ctx)
{
	int	pos;

	while (1)
	{
		pos = find_max_in_bucket(stack_b, info->current_bucket, info);
		if (pos == -1)
			break ;
		rotate_to_position_b(stack_b, pos, ctx);
		pa(stack_a, stack_b, ctx->bench);
		print_verbose(ctx->flags, "pa\n");
	}
}

void	bucket_sort(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench)
{
	t_bucket_info	info;
	t_rotate_ctx	ctx;

	ctx.flags = flags;
	ctx.bench = bench;
	if (!stack_a || stack_a->size <= 1)
		return ;
	if (is_sorted(stack_a))
		return ;
	info.num_buckets = (int)ceil(sqrt(stack_a->size));
	if (info.num_buckets < 2)
		info.num_buckets = 2;
	info.min = find_min_in_array(stack_a->collection, stack_a->size);
	info.max = find_max_in_array(stack_a->collection, stack_a->size);
	info.range = (long)info.max - (long)info.min;
	push_all_to_b(stack_a, stack_b, flags, bench);
	info.current_bucket = info.num_buckets - 1;
	while (info.current_bucket >= 0)
	{
		push_bucket_to_a(stack_a, stack_b, &info, &ctx);
		info.current_bucket--;
	}
}
