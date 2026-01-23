/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:32:14 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/08 19:32:24 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c -= 32;
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

	result = ft_toupper('R');
	printf("%c\n", result);
	result = ft_toupper('H');
	printf("%c\n", result);
	result = ft_toupper('e');
	printf("%c\n", result);
	result = ft_toupper('b');
	printf("%c\n", result);
	result = ft_toupper('5');
	printf("%c\n", result);
	result = ft_toupper('8');
	printf("%c\n", result);
	result = ft_toupper('-');
	printf("%c\n", result);
	result = ft_toupper('@');
	printf("%c\n", result);
}*/
