/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:28:10 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/23 16:28:13 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack, char *name)
{
	int	i;

	if (!stack)
	{
		printf("%s: (null)\n", name);
		return ;
	}
	if (stack->size == 0)
	{
		printf("%s: (empty)\n", name);
		return ;
	}

	i = 0;
	while (i < stack->size)
	{
		printf("%d\n", stack->collection[i]);
		i++;
	}
	printf("\n");
}
