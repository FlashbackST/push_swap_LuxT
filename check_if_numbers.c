/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:55:35 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/26 15:55:38 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_single_number(char *str, int *j)
{
	if (str[*j] == '-' || str[*j] == '+')
		(*j)++;
	if (!str[*j] || str[*j] == ' ' || str[*j] == '\t')
		return (1);
	while (str[*j] && str[*j] != ' ' && str[*j] != '\t')
	{
		if (str[*j] < '0' || str[*j] > '9')
			return (1);
		(*j)++;
	}
	return (0);
}

static int	validate_argument(char *arg)
{
	int	j;
	int	has_number;

	j = 0;
	has_number = 0;
	while (arg[j])
	{
		while (arg[j] == ' ' || arg[j] == '\t')
			j++;
		if (arg[j])
		{
			if (check_single_number(arg, &j))
				return (1);
			has_number = 1;
		}
	}
	if (!has_number)
		return (1);
	return (0);
}

int	check_if_numbers(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!(argv[i][0] == '-' && argv[i][1] == '-'))
		{
			if (validate_argument(argv[i]))
				return (1);
		}
		i++;
	}
	return (0);
}
