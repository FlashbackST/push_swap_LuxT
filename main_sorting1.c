/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sorting1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:26:59 by sthinnes          #+#    #+#             */
/*   Updated: 2026/02/06 18:27:03 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

void	run_medium_first(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench)
{
	if (!flags->quiet)
	{
		print_stack(stack_a, stack_b);
		print_header(flags, 1);
	}
	make_benchmark(bench, stack_a, flags);
	bench->strategy_name = "Bucket sort";
	bench->complexity_class = "O(n√n)";
	bucket_sort(stack_a, stack_b, flags, bench);
	if (!flags->quiet)
	{
		ft_printf("\n");
		print_stack(stack_a, stack_b);
		benchmark_display(bench);
		ft_printf("========================\n");
		print_disorder(stack_a->disorder);
		print_stack(stack_a, stack_b);
		print_header(flags, 0);
	}
}

void	run_simple_first(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench)
{
	if (!flags->quiet)
	{
		print_stack(stack_a, stack_b);
		print_header(flags, 0);
	}
	make_benchmark(bench, stack_a, flags);
	bench->strategy_name = "Insertion sort";
	bench->complexity_class = "O(n^2)";
	insertion_sort(stack_a, stack_b, flags, bench);
	if (!flags->quiet)
	{
		ft_printf("\n");
		print_stack(stack_a, stack_b);
		benchmark_display(bench);
		ft_printf("========================\n");
		print_disorder(stack_a->disorder);
		print_stack(stack_a, stack_b);
		print_header(flags, 1);
	}
}

void	execute_medium_then_simple(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench)
{
	t_stack		*temp_a;
	t_benchmark	bench2;

	temp_a = create_stack(stack_a->capacity);
	copy_stack(temp_a, stack_a);
	run_medium_first(stack_a, stack_b, flags, bench);
	make_benchmark(&bench2, stack_a, flags);
	bench2.strategy_name = "Insertion sort";
	bench2.complexity_class = "O(n^2)";
	copy_stack(stack_a, temp_a);
	stack_b->size = 0;
	finish_medium_first(stack_a, stack_b, flags, &bench2);
	free_stack(temp_a);
}

void	execute_simple_then_medium(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench)
{
	t_stack		*temp_a;
	t_benchmark	bench2;

	temp_a = create_stack(stack_a->capacity);
	copy_stack(temp_a, stack_a);
	run_simple_first(stack_a, stack_b, flags, bench);
	make_benchmark(&bench2, stack_a, flags);
	bench2.strategy_name = "Bucket sort";
	bench2.complexity_class = "O(n√n)";
	copy_stack(stack_a, temp_a);
	stack_b->size = 0;
	finish_simple_first(stack_a, stack_b, flags, &bench2);
	free_stack(temp_a);
}

void	run_both_algorithms(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench)
{
	if (flags->medium_order < flags->simple_order)
		execute_medium_then_simple(stack_a, stack_b, flags, bench);
	else
		execute_simple_then_medium(stack_a, stack_b, flags, bench);
}
