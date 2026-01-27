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
