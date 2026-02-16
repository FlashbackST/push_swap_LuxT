/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 23:04:45 by sthinnes          #+#    #+#             */
/*   Updated: 2026/02/08 23:04:49 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

void	run_single_complex(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench)
{
	int	was_sorted;

	if (!flags->quiet)
	{
		print_stack(stack_a, stack_b);
		ft_printf("\n=== COMPLEX ===\n");
		if (!flags->bench)
			ft_printf("\n");
	}
	was_sorted = is_sorted(stack_a);
	turk_sort(stack_a, stack_b, flags, bench);
	if (!was_sorted && !flags->quiet)
		ft_printf("\n");
	if (!flags->quiet)
		print_stack(stack_a, stack_b);
}

void	run_single_adaptive(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench)
{
	int	was_sorted;

	if (!flags->quiet)
	{
		print_stack(stack_a, stack_b);
		ft_printf("\n=== ADAPTIVE ===\n");
		if (!flags->bench)
			ft_printf("\n");
	}
	was_sorted = is_sorted(stack_a);
	adaptive_algorithm(stack_a, stack_b, flags, bench);
	if (!was_sorted && !flags->quiet)
		ft_printf("\n");
	if (!flags->quiet)
		print_stack(stack_a, stack_b);
}

static void	execute_algorithm(t_algo_ctx *ctx, int algo_type)
{
	if (algo_type == 0)
		insertion_sort(ctx->stack_a, ctx->stack_b, ctx->flags, ctx->bench);
	else if (algo_type == 1)
		bucket_sort(ctx->stack_a, ctx->stack_b, ctx->flags, ctx->bench);
	else if (algo_type == 2)
		turk_sort(ctx->stack_a, ctx->stack_b, ctx->flags, ctx->bench);
	else if (algo_type == 3)
		adaptive_algorithm(ctx->stack_a, ctx->stack_b, ctx->flags, ctx->bench);
}

static void	print_algorithm_header(int algo_type, t_flags *flags)
{
	ft_printf("\n");
	if (algo_type == 0)
		ft_printf("=== SIMPLE ===\n");
	else if (algo_type == 1)
		ft_printf("=== MEDIUM ===\n");
	else if (algo_type == 2)
		ft_printf("=== COMPLEX ===\n");
	else if (algo_type == 3)
		ft_printf("=== ADAPTIVE ===\n");
	if (!flags->bench)
		ft_printf("\n");
}

void	run_algorithm_with_header(t_algo_ctx *ctx, int algo_type)
{
	if (!ctx->flags->quiet)
		print_algorithm_header(algo_type, ctx->flags);
	execute_algorithm(ctx, algo_type);
	if (!ctx->flags->quiet)
	{
		ft_printf("\n");
		print_stack(ctx->stack_a, ctx->stack_b);
		benchmark_display(ctx->bench);
	}
}
