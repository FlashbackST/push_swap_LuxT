/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_outside_valid_range.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:42:55 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/26 16:43:00 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include <stdio.h>

static long	ft_strtol(const char *str, char **endptr)
{
	long	result;
	int		sign;
	int		digit;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		result = result * 10 + digit;
		str++;
	}
	if (endptr != NULL)
		*endptr = (char *)str;
	return (result * sign);
}

static int	check_number_range(char *str)
{
	long	num;
	char	*endptr;
	char	*ptr;

	ptr = str;
	while (*ptr)
	{
		num = ft_strtol(ptr, &endptr);
		if (ptr == endptr)
			break ;
		if (num < INT_MIN || num > INT_MAX)
			return (1);
		ptr = endptr;
	}
	return (0);
}

int	check_if_outside_valid_range(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!(argv[i][0] == '-' && argv[i][1] == '-'))
		{
			if (check_number_range(argv[i]))
				return (1);
		}
		i++;
	}
	return (0);
}
