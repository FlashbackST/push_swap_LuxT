/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:26:13 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/22 22:26:17 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"
#include <unistd.h>

int	is_flag(char *arg);

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	init_flags(t_flags *flags)
{
	if (!flags)
		return ;
	flags->simple = 0;
	flags->medium = 0;
	flags->bench = 0;
	flags->simple_order = 0;
	flags->medium_order = 0;
}

static void	process_flag(char *arg, t_flags *flags, int *order)
{
	if (ft_strcmp(arg, "--simple") == 0)
	{
		flags->simple = 1;
		flags->simple_order = (*order)++;
	}
	else if (ft_strcmp(arg, "--medium") == 0)
	{
		flags->medium = 1;
		flags->medium_order = (*order)++;
	}
	else if (ft_strcmp(arg, "--bench") == 0)
		flags->bench = 1;
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	parse_flags(int argc, char **argv, t_flags *flags)
{
	int	i;
	int	order;

	if (!flags || !argv)
		return ;
	i = 1;
	order = 0;
	while (i < argc && is_flag(argv[i]))
	{
		process_flag(argv[i], flags, &order);
		i++;
	}
}
