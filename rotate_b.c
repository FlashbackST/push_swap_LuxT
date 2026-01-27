/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:09:07 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/23 14:09:10 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"
//#include <stdio.h>

void	rb(t_stack *stack_b, t_benchmark *bench)
{
	int	temp;
	int	i;

	if (!stack_b || stack_b->size < 2)
		return ;
	temp = stack_b->collection[0];
	i = 0;
	while (i < stack_b->size - 1)
	{
		stack_b->collection[i] = stack_b->collection[i + 1];
		i++;
	}
	stack_b->collection[stack_b->size - 1] = temp;
	if (!bench || !bench->enabled)
		write(1, "rb\n", 3);
	if (bench)
		benchmark_record_op(bench, "rb");
}
