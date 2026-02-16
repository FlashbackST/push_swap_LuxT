/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:03:11 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/23 14:03:18 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

void	sb(t_stack *stack_b, t_benchmark *bench)
{
	int	temp;

	if (!stack_b || stack_b->size < 2)
		return ;
	temp = stack_b->collection[0];
	stack_b->collection[0] = stack_b->collection[1];
	stack_b->collection[1] = temp;
	if (!bench || !bench->enabled)
		write(1, "sb\n", 3);
	if (bench)
		benchmark_record_op(bench, "sb");
}
