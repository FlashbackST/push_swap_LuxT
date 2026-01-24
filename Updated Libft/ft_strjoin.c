/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:52:45 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/12 12:52:48 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static size_t	get_total_length(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;

	len1 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	return (len1 + len2);
}

static void	copy_strings(char *res, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	total_len;

	if (!s2)
		return (NULL);
	total_len = get_total_length(s1, s2);
	res = malloc(total_len + 1);
	if (!res)
		return (NULL);
	copy_strings(res, s1, s2);
	free(s1);
	return (res);
}

/*int	main(void)
{
	char *result;

	printf("=== Test 1: Normal strings ===\n");
	result = ft_strjoin("Hello ", "World");
	if (result)
	{
		printf("Result: '%s'\n", result);
		printf("Expected: 'Hello World'\n");
		free(result);
	}
	printf("\n");

	printf("=== Test 2: Empty first string ===\n");
	result = ft_strjoin("", "World");
	if (result)
	{
		printf("Result: '%s'\n", result);
		printf("Expected: 'World'\n");
		free(result);
	}
	printf("\n");

	printf("=== Test 3: Empty second string ===\n");
	result = ft_strjoin("Hello", "");
	if (result)
	{
		printf("Result: '%s'\n", result);
		printf("Expected: 'Hello'\n");
		free(result);
	}
	printf("\n");

	printf("=== Test 4: Both empty ===\n");
	result = ft_strjoin("", "");
	if (result)
	{
		printf("Result: '%s'\n", result);
		printf("Expected: ''\n");
		free(result);
	}
	printf("\n");

	printf("=== Test 5: NULL strings ===\n");
	result = ft_strjoin(NULL, "World");
	if (result == NULL)
		printf("Result: NULL (correct)\n");
	else
	{
		printf("Result: '%s' (should be NULL!)\n", result);
		free(result);
	}
	printf("\n");

	printf("=== Test 6: Long strings ===\n");
	result = ft_strjoin("This is a longer string ",
		"concatenated with another long string!");
	if (result)
	{
		printf("Result: '%s'\n", result);
		free(result);
	}
	printf("\n");
}*/
