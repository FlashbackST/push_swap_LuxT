/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:26:28 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/22 22:26:31 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int capacity)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
	{
		return (NULL);
	}
	new_stack->collection = malloc(sizeof(int) * capacity);
	if (new_stack->collection == NULL)
	{
		free(new_stack);
		return (NULL);
	}
	new_stack->capacity = capacity;
	new_stack->size = 0;
	return (new_stack);
}
