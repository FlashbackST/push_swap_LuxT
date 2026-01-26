/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sventhinnes <sventhinnes@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:38:40 by sventhinnes       #+#    #+#             */
/*   Updated: 2026/01/25 17:38:40 by sventhinnes      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_flag(char *arg)
{
	if (!arg)
		return (0);
	if (arg[0] == '-' && arg[1] == '-')
		return (1);
	return (0);
}

static int	count_numbers(int argc, char **argv)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (i < argc)
	{
		if (!is_flag(argv[i]))
			count++;
		i++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_flags		flags;
	int			num_count;

	if (argc < 2)
		return (0);
	init_flags(&flags);
	parse_flags(argc, argv, &flags);
	num_count = count_numbers(argc, argv);
	if (num_count == 0)
		return (0);
	stack_a = parse_arguments(argc, argv);
	stack_b = create_stack(num_count);
	if (!stack_a || !stack_b)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (1);
	}
	if (flags.simple)
	{
		print_stack(stack_a, stack_b);
		ft_printf("\n");
		insertion_sort(stack_a, stack_b, &flags);
		//selection_sort(stack_a, stack_b, &flags);
	}
	else
		ft_printf("Error Flags\n");
	ft_printf("\n");
	print_stack(stack_a, stack_b);
	/*copy_stack(stack_b, stack_a);
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
	print_stack(stack_a, stack_b);*/
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
