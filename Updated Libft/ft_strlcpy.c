/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:30:31 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/08 19:30:35 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (src[res])
		res++;
	if (size < 1)
		return (res);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (res);
}

/*int	main(void)
{
	char	dest[50];
	char	*src;
	int		size;

	src = "Power is everything!";
	size = 21;
	printf("%d\n", ft_strlcpy(dest, src, size));
	printf(".%s.\n\n", dest);
	printf("%d\n", ft_strlcpy(dest, src, size));
	printf(".%s.\n\n", dest);
}*/
