/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:52:09 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/25 14:52:12 by sthinnes         ###   ########.fr       */
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

t_stack	*parse_arguments(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	int		num;
	int		num_count;

	num_count = count_numbers(argc, argv);
	stack = create_stack(num_count);
	if (!stack)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (!is_flag(argv[i]))
		{
			num = ft_atoi(argv[i]);
			stack_add_bottom(stack, num);
		}
		i++;
	}
	return (stack);
}
