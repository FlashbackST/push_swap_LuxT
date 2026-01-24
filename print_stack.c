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

static int	get_max_size(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size > stack_a->size)
		return (stack_b->size);
	return (stack_a->size);
}

static void	print_stack_value(t_stack *stack, int index)
{
	if (index < stack->size)
		ft_printf("%d ", stack->collection[index]);
	else
		ft_printf("  ");
}

static void	print_stack_row(t_stack *stack_a, t_stack *stack_b, int i)
{
	print_stack_value(stack_a, i);
	if (i < stack_b->size)
		ft_printf("%d\n", stack_b->collection[i]);
	else
		ft_printf("\n");
}

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	max_size;

	if (!stack_a || !stack_b)
	{
		ft_printf("Error: One or both stacks are null\n");
		return ;
	}
	max_size = get_max_size(stack_a, stack_b);
	i = 0;
	while (i < max_size)
	{
		print_stack_row(stack_a, stack_b, i);
		i++;
	}
	ft_printf("\n- -\na b\n");
}
