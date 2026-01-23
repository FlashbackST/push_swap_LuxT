/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:29:33 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/08 19:29:35 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*source;
	unsigned char		*destination;
	size_t				i;

	source = (const unsigned char *)src;
	destination = (unsigned char *)dest;
	i = 0;
	if (destination < source)
	{
		while (i < n)
		{
			destination[i] = source[i];
			i++;
		}
	}
	else if (destination > source)
	{
		i = n;
		while (i > 0)
		{
			i--;
			destination[i] = source[i];
		}
	}
	return (dest);
}

/*int	main(void)
{
	char	buffer[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
	printf("Original: %.26s\n", buffer);
	// Large overlap - copy backward (dest > src)
	// Copy 20 bytes from position 0 to position 5
	memmove(buffer + 5, buffer, 20);
	printf("memmove:  %.26s\n", buffer);
}*/
