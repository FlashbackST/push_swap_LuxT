/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:08:51 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/23 14:08:55 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"
//#include <stdio.h>

void	ra(t_stack *stack_a, t_benchmark *bench)
{
	int	temp;
	int	i;

	if (!stack_a || stack_a->size < 2)
		return ;
	temp = stack_a->collection[0];
	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->collection[i] = stack_a->collection[i + 1];
		i++;
	}
	stack_a->collection[stack_a->size - 1] = temp;
	if (!bench || !bench->enabled)
		write(1, "ra\n", 3);
	if (bench)
		benchmark_record_op(bench, "ra");
}
