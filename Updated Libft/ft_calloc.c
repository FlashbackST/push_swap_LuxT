/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:38:00 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/08 19:38:04 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*byte_ptr;
	size_t			total_size;
	size_t			i;

	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > __SIZE_MAX__ / size)
		return (0);
	if (ptr == 0)
		return (0);
	byte_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < total_size)
	{
		byte_ptr[i] = 0;
		i++;
	}
	return (ptr);
}

/*int	main(void)
{
	int		*arr;
	char	*str;
	int		i;

	// Test 1: Integer array
	arr = (int *)ft_calloc(5, sizeof(int));
	printf("Integer array: ");
	i = 0;
	while (i < 5)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	free(arr);
	// Test 2: String
	str = (char *)ft_calloc(10, sizeof(char));
	printf("String (empty): \"%s\"\n", str);
	free(str);
}*/
