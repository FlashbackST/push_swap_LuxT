/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:53:27 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/12 12:53:35 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new_str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	new_str = malloc(sizeof(char) * (end - start + 1));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1 + start, end - start + 1);
	return (new_str);
}

/*int	main(void)
{
	char	*result;

	printf("=== FT_STRTRIM TESTS ===\n\n");

	// Test 1: Basic trim from both sides
	printf("Test 1: Basic trim\n");
	result = ft_strtrim("   hello world   ", " ");
	printf("Input:    \"   hello world   \"\n");
	printf("Set:      \" \"\n");
	printf("Result:   \"%s\"\n", result);
	printf("Expected: \"hello world\"\n\n");
	free(result);

	// Test 2: Trim multiple characters
	printf("Test 2: Trim multiple characters\n");
	result = ft_strtrim("xxxhello worldxxx", "x");
	printf("Input:    \"xxxhello worldxxx\"\n");
	printf("Set:      \"x\"\n");
	printf("Result:   \"%s\"\n", result);
	printf("Expected: \"hello world\"\n\n");
	free(result);

	// Test 3: Trim from beginning only
	printf("Test 3: Trim from beginning only\n");
	result = ft_strtrim("!!!hello", "!");
	printf("Input:    \"!!!hello\"\n");
	printf("Set:      \"!\"\n");
	printf("Result:   \"%s\"\n", result);
	printf("Expected: \"hello\"\n\n");
	free(result);

	// Test 4: Trim from end only
	printf("Test 4: Trim from end only\n");
	result = ft_strtrim("hello!!!", "!");
	printf("Input:    \"hello!!!\"\n");
	printf("Set:      \"!\"\n");
	printf("Result:   \"%s\"\n", result);
	printf("Expected: \"hello\"\n\n");
	free(result);

	// Test 5: Multiple characters in set
	printf("Test 5: Multiple characters in set\n");
	result = ft_strtrim("abc123def", "abcdef");
	printf("Input:    \"abc123def\"\n");
	printf("Set:      \"abcdef\"\n");
	printf("Result:   \"%s\"\n", result);
	printf("Expected: \"123\"\n\n");
	free(result);

	// Test 6: Nothing to trim
	printf("Test 6: Nothing to trim\n");
	result = ft_strtrim("hello", "x");
	printf("Input:    \"hello\"\n");
	printf("Set:      \"x\"\n");
	printf("Result:   \"%s\"\n", result);
	printf("Expected: \"hello\"\n\n");
	free(result);

	// Test 7: Trim everything
	printf("Test 7: Trim everything\n");
	result = ft_strtrim("xxxxx", "x");
	printf("Input:    \"xxxxx\"\n");
	printf("Set:      \"x\"\n");
	printf("Result:   \"%s\"\n", result);
	printf("Expected: \"\"\n\n");
	free(result);

	// Test 8: Empty string
	printf("Test 8: Empty string\n");
	result = ft_strtrim("", "x");
	printf("Input:    \"\"\n");
	printf("Set:      \"x\"\n");
	printf("Result:   \"%s\"\n", result);
	printf("Expected: \"\"\n\n");
	free(result);

	// Test 9: Empty set
	printf("Test 9: Empty set\n");
	result = ft_strtrim("hello", "");
	printf("Input:    \"hello\"\n");
	printf("Set:      \"\"\n");
	printf("Result:   \"%s\"\n", result);
	printf("Expected: \"hello\"\n\n");
	free(result);

	// Test 10: Complex set with spaces and newlines
	printf("Test 10: Complex set\n");
	result = ft_strtrim("\n\t  hello world  \t\n", " \n\t");
	printf("Input:    \"\\n\\t  hello world  \\t\\n\"\n");
	printf("Set:      \" \\n\\t\"\n");
	printf("Result:   \"%s\"\n", result);
	printf("Expected: \"hello world\"\n\n");
	free(result);

	// Test 11: NULL string (should return NULL)
	printf("Test 11: NULL string\n");
	result = ft_strtrim(NULL, "x");
	printf("Input:    NULL\n");
	printf("Set:      \"x\"\n");
	printf("Result:   %s\n", result ? result : "NULL");
	printf("Expected: NULL\n\n");

	// Test 12: NULL set (should return NULL)
	printf("Test 12: NULL set\n");
	result = ft_strtrim("hello", NULL);
	printf("Input:    \"hello\"\n");
	printf("Set:      NULL\n");
	printf("Result:   %s\n", result ? result : "NULL");
	printf("Expected: NULL\n\n");

	printf("=== TESTS COMPLETE ===\n");
}*/
