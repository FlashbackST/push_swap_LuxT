/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a+b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:09:51 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/23 14:10:02 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"
//#include <stdio.h>

static void	rotate_stack(t_stack *stack)
{
	int	temp;
	int	i;

	temp = stack->collection[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->collection[i] = stack->collection[i + 1];
		i++;
	}
	stack->collection[stack->size - 1] = temp;
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_benchmark *bench)
{
	if (stack_a && stack_a->size >= 2)
		rotate_stack(stack_a);
	if (stack_b && stack_b->size >= 2)
		rotate_stack(stack_b);
	if (!bench || !bench->enabled)
		write(1, "rr\n", 3);
	if (bench)
		benchmark_record_op(bench, "rr");
}
