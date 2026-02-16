/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm_utils3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 23:04:55 by sthinnes          #+#    #+#             */
/*   Updated: 2026/02/08 23:04:58 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

static void	init_algo_arrays(int algos[4], int orders[4], t_flags *flags)
{
	algos[0] = flags->simple;
	algos[1] = flags->medium;
	algos[2] = flags->complex;
	algos[3] = flags->adaptive;
	orders[0] = flags->simple_order;
	orders[1] = flags->medium_order;
	orders[2] = flags->complex_order;
	orders[3] = flags->adaptive_order;
}

static int	find_next_algorithm(int algos[4], int orders[4])
{
	int	min_idx;
	int	j;

	min_idx = -1;
	j = 0;
	while (j < 4)
	{
		if (algos[j] && (min_idx == -1 || orders[j] < orders[min_idx]))
			min_idx = j;
		j++;
	}
	return (min_idx);
}

static void	run_one_algorithm(t_stack *stack_a, t_stack *stack_b,
				t_flags *flags, t_multi_algo *mctx)
{
	t_algo_ctx	actx;
	double		original_disorder;

	original_disorder = stack_a->disorder;
	copy_stack(mctx->temp_a, stack_a);
	mctx->temp_a->disorder = original_disorder;
	stack_b->size = 0;
	make_benchmark(&mctx->temp_bench, mctx->temp_a, flags);
	set_strategy_name(&mctx->temp_bench, mctx->min_idx);
	if (!flags->quiet)
	{
		print_disorder(original_disorder);
		print_stack(mctx->temp_a, stack_b);
	}
	actx.stack_a = mctx->temp_a;
	actx.stack_b = stack_b;
	actx.flags = flags;
	actx.bench = &mctx->temp_bench;
	run_algorithm_with_header(&actx, mctx->min_idx);
}

void	run_multiple_algorithms(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench)
{
	t_multi_algo	ctx;
	int				algos[4];
	int				orders[4];

	(void)bench;
	init_algo_arrays(algos, orders, flags);
	ctx.temp_a = create_stack(stack_a->capacity);
	ctx.i = 0;
	while (ctx.i < 4)
	{
		ctx.min_idx = find_next_algorithm(algos, orders);
		if (ctx.min_idx == -1)
			break ;
		if (!flags->quiet && ctx.i > 0)
			ft_printf("========================\n");
		run_one_algorithm(stack_a, stack_b, flags, &ctx);
		algos[ctx.min_idx] = 0;
		ctx.i++;
	}
	free_stack(ctx.temp_a);
}
