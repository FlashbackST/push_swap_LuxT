/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:33:34 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/08 19:33:37 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c += 32;
		return (c);
	}
	else
	{
		return (c);
	}
}

/*int	main(void)
{
	char	result;

	result = ft_tolower('R');
	printf("%c\n", result);
	result = ft_tolower('H');
	printf("%c\n", result);
	result = ft_tolower('e');
	printf("%c\n", result);
	result = ft_tolower('b');
	printf("%c\n", result);
	result = ft_tolower('5');
	printf("%c\n", result);
	result = ft_tolower('8');
	printf("%c\n", result);
	result = ft_tolower('-');
	printf("%c\n", result);
	result = ft_tolower('@');
	printf("%c\n", result);
}*/
