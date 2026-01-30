/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_stack_is_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:53:21 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/29 15:53:25 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	if (!stack || stack->size <= 1)
		return (1);
	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->collection[i] > stack->collection[i + 1])
			return (0);
		i++;
	}
	return (1);
}
