/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:27:18 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/08 19:27:21 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

/*int	main(void)
{
	char	buffer[10];
	int		i;

	ft_memset(buffer, 'g', 10);
	i = 0;
	while (i < 10)
	{
		printf("%c", buffer[i]);
		i++;
	}
	printf("\n");
}*/
