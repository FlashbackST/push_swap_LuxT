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
	flags->verbose = 0;
	flags->debug = 0;
}

void	parse_flags(int argc, char **argv, t_flags *flags)
{
	int	i;

	if (!flags || !argv)
		return ;
	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--simple") == 0)
			flags->simple = 1;
		else if (ft_strcmp(argv[i], "--verbose") == 0)
			flags->verbose = 1;
		else if (ft_strcmp(argv[i], "--debug") == 0)
			flags->debug = 1;
		i++;
	}
}
