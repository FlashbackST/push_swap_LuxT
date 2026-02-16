/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:21:08 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/08 19:21:11 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
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

	result = ft_isalpha('z');
	printf("isalpha('z') = %d\n", result);
	result = ft_isalpha('k');
	printf("isalpha('k') = %d\n", result);
	result = ft_isalpha('A');
	printf("isalpha('A') = %d\n", result);
	result = ft_isalpha('Q');
	printf("isalpha('Q') = %d\n", result);
	result = ft_isalpha('4');
	printf("isalpha('4') = %d\n", result);
	result = ft_isalpha('#');
	printf("isalpha('#') = %d\n", result);
	result = ft_isalpha('-');
	printf("isalpha('-') = %d\n", result);
}*/
