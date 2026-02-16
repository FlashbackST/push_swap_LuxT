/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:25:39 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/08 19:25:48 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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

	result = ft_isprint('z');
	printf("isprint('z') = %d\n", result);
	result = ft_isprint('Q');
	printf("isprint('Q') = %d\n", result);
	result = ft_isprint('4');
	printf("isprint('4') = %d\n", result);
	result = ft_isprint('#');
	printf("isprint('#') = %d\n", result);
	result = ft_isprint('@');
	printf("isprint('@') = %d\n", result);
}*/
