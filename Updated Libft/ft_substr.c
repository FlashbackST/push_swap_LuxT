/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:52:11 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/12 12:52:16 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlen(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substring;	

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (start + len > s_len)
		len = s_len - start;
	substring = malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

/*int	main(void)
{
	char	*result;

	// Test 1: Normal substring
	printf("Test 1: Normal substring\n");
	result = ft_substr("Hello World", 6, 5);
	printf("Expected: 'World'\n");
	printf("Got:      '%s'\n\n", result);
	free(result);

	// Test 2: Substring from start
	printf("Test 2: Substring from start\n");
	result = ft_substr("Hello World", 0, 5);
	printf("Expected: 'Hello'\n");
	printf("Got:      '%s'\n\n", result);
	free(result);

	// Test 3: Start beyond string length
	printf("Test 3: Start beyond string length\n");
	result = ft_substr("Hello", 10, 5);
	printf("Expected: ''\n");
	printf("Got:      '%s'\n\n", result);
	free(result);

	// Test 4: Length exceeds available characters
	printf("Test 4: Length exceeds available\n");
	result = ft_substr("Hello", 2, 10);
	printf("Expected: 'llo'\n");
	printf("Got:      '%s'\n\n", result);
	free(result);

	// Test 5: Empty string
	printf("Test 5: Empty string\n");
	result = ft_substr("", 0, 5);
	printf("Expected: ''\n");
	printf("Got:      '%s'\n\n", result);
	free(result);

	// Test 6: Length is 0
	printf("Test 6: Length is 0\n");
	result = ft_substr("Hello World", 3, 0);
	printf("Expected: ''\n");
	printf("Got:      '%s'\n\n", result);
	free(result);

	// Test 7: Single character
	printf("Test 7: Single character\n");
	result = ft_substr("Hello", 1, 1);
	printf("Expected: 'e'\n");
	printf("Got:      '%s'\n\n", result);
	free(result);
}*/
