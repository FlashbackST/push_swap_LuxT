/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:34:24 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/08 19:34:27 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			last = s;
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return ((char *)last);
}

/*int	main(void)
{
	char	*str = "Hello, World!";
	char	*result;

	// Test 1: Find 'W'
	result = strrchr(str, 'W');
	if (result)
	{
		printf("Found 'W' at position: %ld, substring: '%s'\n",
			result - str, result);
	}
	else
	{
		printf("'W' not found\n");
	}
	// Test 2: Find 'o'
	result = strrchr(str, 'o');
	if (result)
	{
		printf("Found 'o' at position: %ld, substring: '%s'\n",
			result - str, result);
	}
	else
	{
		printf("'o' not found\n");
	}
	// Test 3: Character not in string
	result = strrchr(str, 'z');
	if (result)
	{
		printf("Found 'z'\n");
	}
	else
	{
		printf("'z' not found\n");
	}
	// Test 4: Find null terminator
	result = strrchr(str, '\0');
	if (result)
	{
		printf("Found null terminator at position: %ld\n", result - str);
	}
	// Test 5: First character
	result = strrchr(str, 'H');
	if (result)
	{
		printf("Found 'H' at position: %ld, substring: '%s'\n",
			result - str, result);
	}
}*/
