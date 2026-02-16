/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:36:24 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/08 19:36:33 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	int	result;

	result = ft_memcmp("Hello", "Hello", 5);
	printf("%d\n", result);
	result = ft_memcmp("Mario", "Luigi", 5);
	printf("%d\n", result);
	result = ft_memcmp("Mario", "Bowser", 5);
	printf("%d\n", result);
	result = ft_memcmp("Mario", "toad", 5);
	printf("%d\n", result);
	result = ft_memcmp("Mario", "123", 5);
	printf("%d\n", result);
}*/
