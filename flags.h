/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:26:13 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/22 22:26:17 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
	int	simple;
	int	verbose;
	int	debug;
	int	bench;
}	t_flags;

void	init_flags(t_flags *flags);
void	parse_flags(int argc, char **argv, t_flags *flags);
int		ft_strcmp(const char *s1, const char *s2);
#endif
