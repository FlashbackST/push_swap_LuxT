/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:25:25 by sthinnes          #+#    #+#             */
/*   Updated: 2026/02/06 18:25:31 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

static void	execute_algorithm(t_stack *stack_a, t_stack *stack_b,
				t_flags *flags, t_benchmark *bench)
{
	if (flags->complex)
		turk_sort(stack_a, stack_b, flags, bench);
	else if (flags->medium)
		bucket_sort(stack_a, stack_b, flags, bench);
	else if (flags->adaptive)
		adaptive_algorithm(stack_a, stack_b, flags, bench);
	else
		turk_sort(stack_a, stack_b, flags, bench);
}

void	run_sorting(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench)
{
	int	algo_count;

	algo_count = flags->simple + flags->medium + flags->complex
		+ flags->adaptive;
	if (flags->bench && algo_count == 0)
	{
		if (!flags->quiet)
			print_stack(stack_a, stack_b);
		execute_algorithm(stack_a, stack_b, flags, bench);
	}
	else if (algo_count >= 2)
		run_multiple_algorithms(stack_a, stack_b, flags, bench);
	else if (flags->simple)
		run_single_simple(stack_a, stack_b, flags, bench);
	else if (flags->medium)
		run_single_medium(stack_a, stack_b, flags, bench);
	else if (flags->complex)
		run_single_complex(stack_a, stack_b, flags, bench);
	else if (flags->adaptive)
		run_single_adaptive(stack_a, stack_b, flags, bench);
	else
		turk_sort(stack_a, stack_b, flags, bench);
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
