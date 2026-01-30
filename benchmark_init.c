/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:48:52 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/27 10:48:55 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark.h"
#include "push_swap.h"

static void	init_op_counts(t_op_counts *ops)
{
	ops->sa = 0;
	ops->sb = 0;
	ops->ss = 0;
	ops->pa = 0;
	ops->pb = 0;
	ops->ra = 0;
	ops->rb = 0;
	ops->rr = 0;
	ops->rra = 0;
	ops->rrb = 0;
	ops->rrr = 0;
	ops->total = 0;
}

void	benchmark_init(t_benchmark *bench, int enabled)
{
	bench->enabled = enabled;
	bench->disorder = 0.0;
	bench->strategy_name = NULL;
	bench->complexity_class = NULL;
	init_op_counts(&bench->ops);
}

void	benchmark_set_disorder(t_benchmark *bench, double disorder)
{
	bench->disorder = disorder;
}

void	benchmark_set_strategy(t_benchmark *bench, int stack_size)
{
	if (stack_size <= 3)
	{
		bench->strategy_name = "Simple sort";
		bench->complexity_class = "O(n^2)";
	}
	else if (stack_size <= 5)
	{
		bench->strategy_name = "Simple (Selection sort)";
		bench->complexity_class = "O(n^2)";
	}
	else
	{
		bench->strategy_name = "Simple (Insertion sort)";
		bench->complexity_class = "O(n^2)";
	}
}

void	make_benchmark(t_benchmark *bench, t_stack *stack_a, t_flags *flags)
{
	benchmark_init(bench, flags->bench);
	benchmark_set_disorder(bench, stack_a->disorder);
	if (flags->medium)
	{
		bench->strategy_name = "Medium (Bucket sort)";
		bench->complexity_class = "O(n√n)";
	}
	else
		benchmark_set_strategy(bench, stack_a->size);
}
