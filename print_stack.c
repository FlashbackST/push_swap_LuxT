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

static int	get_num_width(int num)
{
	int		width;
	long	n;

	if (num == 0)
		return (1);
	width = 0;
	n = num;
	if (n < 0)
	{
		width = 1;
		n = -n;
	}
	while (n > 0)
	{
		width++;
		n /= 10;
	}
	return (width);
}

static int	get_stack_width(t_stack *stack)
{
	int	i;
	int	max_width;
	int	width;

	max_width = 1;
	i = 0;
	while (i < stack->size)
	{
		width = get_num_width(stack->collection[i]);
		if (width > max_width)
			max_width = width;
		i++;
	}
	return (max_width);
}

static void	print_stack_row(t_stack *stack_a, t_stack *stack_b, int i)
{
	if (i < stack_a->size)
		ft_printf("%d", stack_a->collection[i]);
	if (i < stack_b->size)
		ft_printf(" %d", stack_b->collection[i]);
	ft_printf("\n");
}

static void	print_footer(int width_a, int width_b)
{
	int	i;

	i = -1;
	while (++i < width_a)
		ft_printf("-");
	ft_printf(" ");
	i = -1;
	while (++i < width_b)
		ft_printf("-");
	ft_printf("\n");
	i = -1;
	while (++i < (width_a - 1) / 2)
		ft_printf(" ");
	ft_printf("a");
	while (++i < width_a)
		ft_printf(" ");
	ft_printf(" ");
	i = -1;
	while (++i < (width_b - 1) / 2)
		ft_printf(" ");
	ft_printf("b\n");
}

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	max_size;

	if (!stack_a || !stack_b)
		return ;
	max_size = stack_a->size;
	if (stack_b->size > max_size)
		max_size = stack_b->size;
	i = 0;
	while (i < max_size)
	{
		print_stack_row(stack_a, stack_b, i);
		i++;
	}
	print_footer(get_stack_width(stack_a), get_stack_width(stack_b));
}
