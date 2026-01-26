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
//#include <stdio.h>

int	check_if_numbers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (!(argv[i][0] == '-' && argv[i][1] == '-'))
		{
			j = 0;
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			if (!argv[i][j])
				return (1);
			while (argv[i][j])
			{
				if (argv[i][j] < '0' || argv[i][j] > '9')
					return (1);
				j++;
			}
		}
		i++;
	}
	return (0);
}
