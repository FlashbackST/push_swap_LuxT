/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm_insertionsort_utils.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:49:29 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/26 11:49:33 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//include <stdio.h>

int	find_max_position(t_stack *stack)
{
	int	i;
	int	max_pos;
	int	max_value;

	if (!stack || stack->size == 0)
		return (-1);
	max_pos = 0;
	max_value = stack->collection[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->collection[i] > max_value)
		{
			max_value = stack->collection[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}
