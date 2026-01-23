/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:24:01 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/08 19:24:03 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*int	main(void)
{
	int	result;

	result = ft_isalnum('z');
	printf("isalnum('z') = %d\n", result);
	result = ft_isalnum('k');
	printf("isalnum('k') = %d\n", result);
	result = ft_isalnum('A');
	printf("isalnum('A') = %d\n", result);
	result = ft_isalnum('Q');
	printf("isalnum('Q') = %d\n", result);
	result = ft_isalnum('4');
	printf("isalnum('4') = %d\n", result);
	result = ft_isalnum('#');
	printf("isalnum('#') = %d\n", result);
	result = ft_isalnum('-');
	printf("isalnum('-') = %d\n", result);
}*/
