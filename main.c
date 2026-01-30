/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sventhinnes <sventhinnes@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:38:40 by sventhinnes       #+#    #+#             */
/*   Updated: 2026/01/25 17:38:40 by sventhinnes      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

static void	execute_algorithm(t_stack *stack_a, t_stack *stack_b,
				t_flags *flags, t_benchmark *bench)
{
	(void)flags;
	if (flags->medium)
		bucket_sort(stack_a, stack_b, flags, bench);
	else
		insertion_sort(stack_a, stack_b, flags, bench);
}

static void	run_sorting(t_stack *stack_a, t_stack *stack_b,
				t_flags *flags, t_benchmark *bench)
{
	t_stack			*temp_a;
	t_benchmark		bench2;
	int				was_sorted;

	if (flags->bench && !flags->simple && !flags->medium)
	{
		print_stack(stack_a, stack_b);
		execute_algorithm(stack_a, stack_b, flags, bench);
	}
	else if (flags->simple && flags->medium)
	{
		temp_a = create_stack(stack_a->capacity);
		copy_stack(temp_a, stack_a);
		print_stack(stack_a, stack_b);
		if (flags->medium_order < flags->simple_order)
		{
			ft_printf("\n=== MEDIUM ===\n\n");
			make_benchmark(bench, stack_a, flags);
			bench->strategy_name = "Bucket sort";
			bench->complexity_class = "O(n√n)";
			bucket_sort(stack_a, stack_b, flags, bench);
			ft_printf("\n");
			print_stack(stack_a, stack_b);
			benchmark_display(bench);
			ft_printf("========================\n");
			copy_stack(stack_a, temp_a);
			stack_b->size = 0;
			print_disorder(stack_a->disorder);
			print_stack(stack_a, stack_b);
			ft_printf("\n=== SIMPLE ===\n\n");
			make_benchmark(&bench2, stack_a, flags);
			bench2.strategy_name = "Insertion sort";
			bench2.complexity_class = "O(n^2)";
			insertion_sort(stack_a, stack_b, flags, &bench2);
			ft_printf("\n");
			print_stack(stack_a, stack_b);
			benchmark_display(&bench2);
		}
		else
		{
			ft_printf("\n=== SIMPLE ===\n\n");
			make_benchmark(bench, stack_a, flags);
			bench->strategy_name = "Insertion sort";
			bench->complexity_class = "O(n^2)";
			insertion_sort(stack_a, stack_b, flags, bench);
			ft_printf("\n");
			print_stack(stack_a, stack_b);
			benchmark_display(bench);
			ft_printf("========================\n");
			copy_stack(stack_a, temp_a);
			stack_b->size = 0;
			print_disorder(stack_a->disorder);
			print_stack(stack_a, stack_b);
			ft_printf("\n=== MEDIUM ===\n\n");
			make_benchmark(&bench2, stack_a, flags);
			bench2.strategy_name = "Bucket sort";
			bench2.complexity_class = "O(n√n)";
			bucket_sort(stack_a, stack_b, flags, &bench2);
			ft_printf("\n");
			print_stack(stack_a, stack_b);
			benchmark_display(&bench2);
		}
		free_stack(temp_a);
	}
	else if (flags->simple)
	{
		print_stack(stack_a, stack_b);
		ft_printf("\n=== SIMPLE ===\n\n");
		was_sorted = is_sorted(stack_a);
		insertion_sort(stack_a, stack_b, flags, bench);
		if (!was_sorted)
			ft_printf("\n");
		print_stack(stack_a, stack_b);
	}
	else if (flags->medium)
	{
		print_stack(stack_a, stack_b);
		ft_printf("\n=== MEDIUM ===\n\n");
		was_sorted = is_sorted(stack_a);
		bucket_sort(stack_a, stack_b, flags, bench);
		if (!was_sorted)
			ft_printf("\n");
		print_stack(stack_a, stack_b);
	}
	else
		ft_printf("Error Flags\n");
}

static void	setup_and_sort(t_stack *stack_a, t_stack *stack_b,
				t_flags *flags, t_benchmark *bench)
{
	stack_a->disorder = compute_disorder(stack_a->collection, stack_a->size);
	print_disorder(stack_a->disorder);
	if (!(flags->simple && flags->medium))
		make_benchmark(bench, stack_a, flags);
	run_sorting(stack_a, stack_b, flags, bench);
	if (!(flags->simple && flags->medium))
		benchmark_display(bench);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_flags		flags;
	t_benchmark	bench;
	int			num_count;

	init_flags(&flags);
	parse_flags(argc, argv, &flags);
	num_count = count_numbers(argc, argv);
	if (handle_errors(argc, argv, num_count))
		return (0);
	stack_a = parse_arguments(argc, argv);
	stack_b = create_stack(num_count);
	if (check_stacks_and_duplicates(stack_a, stack_b))
		return (1);
	setup_and_sort(stack_a, stack_b, &flags, &bench);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
