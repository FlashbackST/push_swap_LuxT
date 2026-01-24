/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:03:00 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/23 14:03:03 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include <stdio.h>

void	sa(t_stack *stack_a)
{
	int	temp;

	if (!stack_a || stack_a->size < 2)
		return ;
	temp = stack_a->collection[0];
	stack_a->collection[0] = stack_a->collection[1];
	stack_a->collection[1] = temp;
	write(1, "sa\n", 3);
}
