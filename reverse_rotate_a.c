/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:10:35 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/23 14:10:46 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"
//#include <stdio.h>

void	rra(t_stack *stack_a, t_benchmark *bench)
{
	int	temp;
	int	i;

	if (!stack_a || stack_a->size < 2)
		return ;
	temp = stack_a->collection[stack_a->size - 1];
	i = stack_a->size - 1;
	while (i > 0)
	{
		stack_a->collection[i] = stack_a->collection[i - 1];
		i--;
	}
	stack_a->collection[0] = temp;
	if (!bench || !bench->enabled)
		write(1, "rra\n", 4);
	if (bench)
		benchmark_record_op(bench, "rra");
}
