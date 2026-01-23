/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:26:40 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/08 19:26:44 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

/*int	main(void)
{
	char str1[] = "Hello";
	char str2[] = "Hello, World!";
	char str3[] = "";
    
	printf("Length of '%s': %zu\n", str1, strlen(str1));  // Output: 5
	printf("Length of '%s': %zu\n", str2, strlen(str2));  // Output: 13
	printf("Length of '%s': %zu\n", str3, strlen(str3));  // Output: 0
}*/
