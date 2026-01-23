/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:52:09 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/23 14:52:12 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*parse_arguments(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	int		num;

	stack = create_stack(argc -1);
	if (!stack)
	{
		return (NULL);
	}
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		stack_add_bottom(stack, num);
		i++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
	{
		return (0);
	}
	stack_a = parse_arguments(argc, argv);
	stack_b = create_stack(argc - 1);
	if (!stack_a || !stack_b)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (1);
	}
	print_stack(stack_a, "Stack A");
	print_stack(stack_b, "Stack B");
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
