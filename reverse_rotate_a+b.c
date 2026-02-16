/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a+b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:11:16 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/23 14:11:19 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

static void	reverse_rotate_stack(t_stack *stack)
{
	int	temp;
	int	i;

	temp = stack->collection[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->collection[i] = stack->collection[i - 1];
		i--;
	}
	stack->collection[0] = temp;
}

void	rrr(t_stack *stack_a, t_stack *stack_b, t_benchmark *bench)
{
	if (stack_a && stack_a->size >= 2)
		reverse_rotate_stack(stack_a);
	if (stack_b && stack_b->size >= 2)
		reverse_rotate_stack(stack_b);
	if (!bench || !bench->enabled)
		write(1, "rrr\n", 4);
	if (bench)
		benchmark_record_op(bench, "rrr");
}
