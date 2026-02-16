/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:26:29 by sthinnes          #+#    #+#             */
/*   Updated: 2026/02/06 18:26:37 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

void	print_header(t_flags *flags, int is_medium)
{
	if (flags->bench)
	{
		if (is_medium)
			ft_printf("\n=== MEDIUM ===\n");
		else
			ft_printf("\n=== SIMPLE ===\n");
	}
	else
	{
		if (is_medium)
			ft_printf("\n=== MEDIUM ===\n\n");
		else
			ft_printf("\n=== SIMPLE ===\n\n");
	}
}

void	run_single_simple(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench)
{
	int	was_sorted;

	if (!flags->quiet)
	{
		print_stack(stack_a, stack_b);
		print_header(flags, 0);
	}
	was_sorted = is_sorted(stack_a);
	insertion_sort(stack_a, stack_b, flags, bench);
	if (!was_sorted && !flags->quiet)
		ft_printf("\n");
	if (!flags->quiet)
		print_stack(stack_a, stack_b);
}

void	run_single_medium(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench)
{
	int	was_sorted;

	if (!flags->quiet)
	{
		print_stack(stack_a, stack_b);
		print_header(flags, 1);
	}
	was_sorted = is_sorted(stack_a);
	bucket_sort(stack_a, stack_b, flags, bench);
	if (!was_sorted && !flags->quiet)
		ft_printf("\n");
	if (!flags->quiet)
		print_stack(stack_a, stack_b);
}

void	setup_and_sort(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench)
{
	int	algo_count;

	stack_a->disorder = compute_disorder(stack_a->collection, stack_a->size);
	algo_count = flags->simple + flags->medium + flags->complex
		+ flags->adaptive;
	if (!flags->quiet && algo_count == 1)
		print_disorder(stack_a->disorder);
	if (algo_count < 2)
		make_benchmark(bench, stack_a, flags);
	run_sorting(stack_a, stack_b, flags, bench);
	if (algo_count < 2 && !flags->quiet)
	{
		benchmark_display(bench);
		if (flags->bench && algo_count == 0)
		{
			ft_printf("\n");
			print_stack(stack_a, stack_b);
		}
	}
}
