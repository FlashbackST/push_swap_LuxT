/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm_bucketsort.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:57:57 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/27 16:58:00 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"
#include <math.h>

void	push_all_to_b(t_stack *stack_a, t_stack *stack_b,
				t_flags *flags, t_benchmark *bench)
{
	while (stack_a->size > 0)
	{
		pb(stack_a, stack_b, bench);
		print_verbose(flags, "pb\n");
	}
}

int	find_in_bucket(t_stack *stack, int bucket, int min, int range)
{
	int	i;
	int	elem_bucket;

	i = 0;
	while (i < stack->size)
	{
		if (range == 0)
			elem_bucket = 0;
		else
		{
			elem_bucket = (stack->collection[i] - min) / (range / 2 + 1);
			if (elem_bucket >= 2)
				elem_bucket = 1;
		}
		if (elem_bucket == bucket)
			return (i);
		i++;
	}
	return (-1);
}
