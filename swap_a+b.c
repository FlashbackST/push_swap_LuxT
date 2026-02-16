/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a+b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:05:31 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/23 14:07:49 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

void	ss(t_stack *stack_a, t_stack *stack_b, t_benchmark *bench)
{
	int	temp;

	if (stack_a && stack_a->size >= 2)
	{
		temp = stack_a->collection[0];
		stack_a->collection[0] = stack_a->collection[1];
		stack_a->collection[1] = temp;
	}
	if (stack_b && stack_b->size >= 2)
	{
		temp = stack_b->collection[0];
		stack_b->collection[0] = stack_b->collection[1];
		stack_b->collection[1] = temp;
	}
	if (!bench || !bench->enabled)
		write(1, "ss\n", 3);
	if (bench)
		benchmark_record_op(bench, "ss");
}
