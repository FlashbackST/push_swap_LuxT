/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm_turksort_index.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 23:01:46 by sthinnes          #+#    #+#             */
/*   Updated: 2026/02/08 23:01:49 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

static int	calculate_rank(t_stack *stack_a, int index)
{
	int	rank;
	int	j;

	rank = 1;
	j = 0;
	while (j < stack_a->size)
	{
		if (stack_a->collection[j] < stack_a->collection[index])
			rank++;
		j++;
	}
	return (rank);
}

int	*create_index_array(t_stack *stack_a)
{
	int	*indexed;
	int	i;

	indexed = malloc(sizeof(int) * stack_a->size);
	if (!indexed)
		return (NULL);
	i = 0;
	while (i < stack_a->size)
	{
		indexed[i] = stack_a->collection[i];
		stack_a->collection[i] = calculate_rank(stack_a, i);
		i++;
	}
	return (indexed);
}

static void	restore_stack_values(t_stack *stack, int *indexed, int total_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < total_size)
		{
			if (stack->collection[i] == j + 1)
			{
				stack->collection[i] = indexed[j];
				break ;
			}
			j++;
		}
		i++;
	}
}

void	restore_original_values(t_stack *stack_a, t_stack *stack_b,
			int *indexed)
{
	int	total_size;

	total_size = stack_a->size + stack_b->size;
	restore_stack_values(stack_a, indexed, total_size);
	restore_stack_values(stack_b, indexed, total_size);
}
