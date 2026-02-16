/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:27:53 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/08 19:27:56 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

/*int	main(void)
{
	char	str1[20] = "Hello, World!";
	char	str2[20] = "Hello, World!";
	int	numbers[5] = {1, 2, 3, 4, 5};
	int	i;

	printf("Before ft_bzero: '%s'\n", str1);
	ft_bzero(str1, 5);
	printf("After ft_bzero:  '%s'\n", str1);
	printf("(First 5 bytes zeroed)\n\n");
	printf("Before bzero:    '%s'\n", str2);
	bzero(str2, 5);
	printf("After bzero:     '%s'\n", str2);
	printf("(Should match ft_bzero)\n\n");
	printf("Before ft_bzero: ");
	i = 0;
	while (i < 5)
	{
		printf("%d ", numbers[i]);
		i++;
	}
	ft_bzero(numbers, sizeof(int) * 3);
	printf("\nAfter ft_bzero:  ");
	i = 0;
	while (i < 5)
	{
		printf("%d ", numbers[i]);
		i++;
	}
	printf("\n(First 3 ints zeroed)\n");
}*/
