/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 19:14:42 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/17 19:14:48 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <unistd.h>

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		str = "(null)";
	}
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (i);
}
