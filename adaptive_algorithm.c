/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_algorithm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:55:49 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/23 12:55:52 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

void	adaptive_algorithm(t_stack *stack_a, t_stack *stack_b,
			t_flags *flags, t_benchmark *bench)
{
	double	disorder;

	disorder = stack_a->disorder;
	if (disorder < 0.2)
	{
		insertion_sort(stack_a, stack_b, flags, bench);
		bench->strategy_name = "Simple (Insertion sort)";
		bench->complexity_class = "O(n^2)";
	}
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		bucket_sort(stack_a, stack_b, flags, bench);
		bench->strategy_name = "Medium (Bucket sort)";
		bench->complexity_class = "O(n√n)";
	}
	else
	{
		turk_sort(stack_a, stack_b, flags, bench);
		bench->strategy_name = "Complex (Turk sort)";
		bench->complexity_class = "O(n log n)";
	}
}
