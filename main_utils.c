/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:07:17 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/27 11:07:24 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

int	is_flag(char *arg)
{
	if (!arg)
		return (0);
	if (arg[0] == '-' && arg[1] == '-')
		return (1);
	return (0);
}

int	count_numbers(int argc, char **argv)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (i < argc)
	{
		if (!is_flag(argv[i]))
			count++;
		i++;
	}
	return (count);
}

void	init_benchmark(t_benchmark *bench, t_stack *stack_a, t_flags *flags)
{
	benchmark_init(bench, flags->bench);
	if (flags->bench)
	{
		benchmark_set_disorder(bench, stack_a->disorder);
		benchmark_set_strategy(bench, stack_a->size);
	}
}

int	handle_errors(int argc, char **argv, int num_count)
{
	if (argc < 2)
		return (1);
	if (error_output(argc, argv))
		return (1);
	if (num_count == 0)
		return (1);
	return (0);
}

int	check_stacks_and_duplicates(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (1);
	}
	if (check_for_duplicates(stack_a))
	{
		write(2, "Error\n", 6);
		free_stack(stack_a);
		free_stack(stack_b);
		return (1);
	}
	return (0);
}
