/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm_turksort_utils.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 23:01:14 by sthinnes          #+#    #+#             */
/*   Updated: 2026/02/08 23:01:19 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

static void	update_min_values(t_stack *stack_a, int i,
				int *min_val, int *min_pos)
{
	if (stack_a->collection[i] < *min_val)
	{
		*min_val = stack_a->collection[i];
		*min_pos = i;
	}
}

static void	init_find_pos(t_find_pos *fp, t_stack *stack_a)
{
	fp->best_pos = -1;
	fp->min_diff = 2147483647;
	fp->min_pos = 0;
	fp->min_val = stack_a->collection[0];
}

static void	check_position(t_stack *stack_a, int i, int value, t_find_pos *fp)
{
	if (stack_a->collection[i] > value
		&& stack_a->collection[i] - value < fp->min_diff)
	{
		fp->min_diff = stack_a->collection[i] - value;
		fp->best_pos = i;
	}
}

int	find_ideal_pos_in_a(t_stack *stack_a, int value)
{
	t_find_pos	fp;
	int			i;

	if (!stack_a || stack_a->size == 0)
		return (0);
	init_find_pos(&fp, stack_a);
	i = -1;
	while (++i < stack_a->size)
	{
		check_position(stack_a, i, value, &fp);
		update_min_values(stack_a, i, &fp.min_val, &fp.min_pos);
	}
	if (fp.best_pos == -1)
		return (fp.min_pos);
	return (fp.best_pos);
}
