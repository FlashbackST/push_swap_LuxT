/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:24:53 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/08 19:25:03 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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

	result = ft_isascii('z');
	printf("isascii('z') = %d\n", result);
	result = ft_isascii('Q');
	printf("isascii('Q') = %d\n", result);
	result = ft_isascii('4');
	printf("isascii('4') = %d\n", result);
	result = ft_isascii('#');
	printf("isascii('#') = %d\n", result);
	result = ft_isascii('@');
	printf("isascii('@') = %d\n", result);
}*/
