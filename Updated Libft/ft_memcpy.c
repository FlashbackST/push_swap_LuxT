/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:28:46 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/08 19:28:50 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*source;
	unsigned char		*destination;
	size_t				i;

	source = (const unsigned char *)src;
	destination = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	int	src[] = {1, 2, 3, 4, 5};
	int	dest[5];

	ft_memcpy(dest, src, sizeof(src));
	printf("Source: %d %d %d %d %d\n", src[0], src[1], src[2], src[3], src[4]);
	printf("Dest:   %d %d %d %d %d\n", dest[0],
		dest[1], dest[2], dest[3], dest[4]);
}*/
