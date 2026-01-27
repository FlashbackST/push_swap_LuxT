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

static void	run_sorting(t_stack *stack_a, t_stack *stack_b,
				t_flags *flags, t_benchmark *bench)
{
	if (flags->bench)
	{
		insertion_sort(stack_a, stack_b, flags, bench);
	}
	else if (flags->simple)
	{
		print_stack(stack_a, stack_b);
		ft_printf("\n");
		insertion_sort(stack_a, stack_b, flags, bench);
		ft_printf("\n");
		print_stack(stack_a, stack_b);
	}
	else
		ft_printf("Error Flags\n");
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
	stack_a->disorder = compute_disorder(stack_a->collection, stack_a->size);
	if (!flags.bench)
		print_disorder(stack_a->disorder);
	init_benchmark(&bench, stack_a, &flags);
	run_sorting(stack_a, stack_b, &flags, &bench);
	benchmark_display(&bench);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
