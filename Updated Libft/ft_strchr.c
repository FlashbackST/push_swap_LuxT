/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:34:01 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/08 19:34:03 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

/*int	main(void)
{
	char	*str = "Hello, World!";
	char	*result;

	// Test 1: Find 'W'
	result = strchr(str, 'W');
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
	result = strchr(str, 'o');
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
	result = strchr(str, 'z');
	if (result)
	{
		printf("Found 'z'\n");
	}
	else
	{
		printf("'z' not found\n");
	}
	// Test 4: Find null terminator
	result = strchr(str, '\0');
	if (result)
	{
		printf("Found null terminator at position: %ld\n", result - str);
	}
	// Test 5: First character
	result = strchr(str, 'H');
	if (result)
	{
		printf("Found 'H' at position: %ld, substring: '%s'\n",
			result - str, result);
	}
}*/
