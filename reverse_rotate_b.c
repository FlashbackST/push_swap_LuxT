/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:10:58 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/23 14:11:01 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include <stdio.h>

void	rrb(t_stack *stack_b)
{
	int	temp;
	int	i;

	if (!stack_b || stack_b->size < 2)
		return ;
	temp = stack_b->collection[stack_b->size - 1];
	i = stack_b->size - 1;
	while (i > 0)
	{
		stack_b->collection[i] = stack_b->collection[i - 1];
		i--;
	}
	stack_b->collection[0] = temp;
	write(1, "rrb\n", 4);
}
