/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:23:52 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/08 19:23:55 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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

	result = ft_isdigit('z');
	printf("isdigit('z') = %d\n", result);
	result = ft_isdigit('k');
	printf("isdigit('k') = %d\n", result);
	result = ft_isdigit('A');
	printf("isdigit('A') = %d\n", result);
	result = ft_isdigit('Q');
	printf("isdigit('Q') = %d\n", result);
	result = ft_isdigit('4');
	printf("isdigit('4') = %d\n", result);
	result = ft_isdigit('#');
	printf("isdigit('#') = %d\n", result);
	result = ft_isdigit('-');
	printf("isdigit('-') = %d\n", result);
}*/
