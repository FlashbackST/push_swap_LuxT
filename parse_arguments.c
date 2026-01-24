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
	copy_stack(stack_b, stack_a);
	print_stack(stack_a, stack_b);
	sa(stack_a);
	print_stack(stack_a, stack_b);
	sb(stack_b);
	print_stack(stack_a, stack_b);
	ss(stack_a, stack_b);
	print_stack(stack_a, stack_b);
	pa(stack_a, stack_b);
	print_stack(stack_a, stack_b);
	pb(stack_a, stack_b);
	print_stack(stack_a, stack_b);
	ra(stack_a);
	print_stack(stack_a, stack_b);
	rb(stack_b);
	print_stack(stack_a, stack_b);
	rr(stack_a, stack_b);
	print_stack(stack_a, stack_b);
	rra(stack_a);
	print_stack(stack_a, stack_b);
	rrb(stack_b);
	print_stack(stack_a, stack_b);
	rrr(stack_a, stack_b);
	print_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
