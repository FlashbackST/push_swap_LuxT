/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:54:47 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/29 09:54:49 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			return (1);
		i++;
	}
	return (0);
}

void	parse_split_arg(char *arg, t_stack *stack)
{
	char	**split;
	int		i;
	int		num;

	split = ft_split(arg, ' ');
	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		num = ft_atoi(split[i]);
		stack_add_bottom(stack, num);
		free(split[i]);
		i++;
	}
	free(split);
}

void	process_argument(char *arg, t_stack *stack)
{
	int	num;

	if (has_space(arg))
		parse_split_arg(arg, stack);
	else
	{
		num = ft_atoi(arg);
		stack_add_bottom(stack, num);
	}
}
