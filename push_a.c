/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:08:12 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/23 14:08:16 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"
//#include <stdio.h>

void	pa(t_stack *stack_a, t_stack *stack_b, t_benchmark *bench)
{
	int	i;

	if (!stack_b || stack_b->size == 0)
		return ;
	i = stack_a->size;
	while (i > 0)
	{
		stack_a->collection[i] = stack_a->collection[i - 1];
		i--;
	}
	stack_a->collection[0] = stack_b->collection[0];
	stack_a->size++;
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->collection[i] = stack_b->collection[i + 1];
		i++;
	}
	stack_b->size--;
	if (!bench || !bench->enabled)
		write(1, "pa\n", 3);
	if (bench)
		benchmark_record_op(bench, "pa");
}
