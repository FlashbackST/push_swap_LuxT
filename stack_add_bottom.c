/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_bottom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:17:15 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/23 15:17:18 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_bottom(t_stack *stack, int value)
{
	if (!stack)
	{
		return ;
	}
	if (stack->size >= stack->capacity)
	{
		return ;
	}
	stack->collection[stack->size] = value;
	stack->size++;
}
