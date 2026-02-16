/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sorting2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:43:47 by sthinnes          #+#    #+#             */
/*   Updated: 2026/02/06 18:43:50 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

void	finish_medium_first(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench2)
{
	insertion_sort(stack_a, stack_b, flags, bench2);
	if (!flags->quiet)
	{
		ft_printf("\n");
		print_stack(stack_a, stack_b);
		benchmark_display(bench2);
	}
}

void	finish_simple_first(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench2)
{
	bucket_sort(stack_a, stack_b, flags, bench2);
	if (!flags->quiet)
	{
		ft_printf("\n");
		print_stack(stack_a, stack_b);
		benchmark_display(bench2);
	}
}
