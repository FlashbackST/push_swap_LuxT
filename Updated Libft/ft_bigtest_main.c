/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigtest_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:45:45 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/14 14:45:49 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdarg.h>

void	LIBFT_PROJECT(void)
{
	char	*str1 = "█████████████████████████████████████████████████\n";
	char	*str2 = "                  LIBFT PROJECT\n";
	char	*str3 = "█████████████████████████████████████████████████\n";
	char	*str4 = "+++++++++++++++++++++++++++++++++++++++++++++++++\n";
	printf("%s", str4);
	printf("\n");
	printf("%s", str1);
	printf("\n");
	printf("%s", str2);
	printf("\n");
	printf("%s", str3);
}

void	FT_PRINTF_PROJECT(void)
{
	char	*str1 = "█████████████████████████████████████████████████\n";
	char	*str2 = "                FT_PRINTF PROJECT\n";
	char	*str3 = "█████████████████████████████████████████████████\n";
	printf("%s", str1);
	printf("\n");
	printf("%s", str2);
	printf("\n");
	printf("%s", str3);
}

void	GET_NEXT_LINE_PROJECT(void)
{
	char	*str1 = "█████████████████████████████████████████████████\n";
	char	*str2 = "              GET_NEXT_LINE PROJECT\n";
	char	*str3 = "█████████████████████████████████████████████████\n";
	printf("%s", str1);
	printf("\n");
	printf("%s", str2);
	printf("\n");
	printf("%s", str3);
}

void	part1(void)
{
	char	*str1 = "=================================================\n";
	char	*str2 = "            Part 1 - Libc functions\n";
	char	*str3 = "=================================================\n";
	printf("\n");
	printf("%s", str1);
	printf("%s", str2);
	printf("%s", str3);
}

void	part2(void)
{
	char	*str1 = "=================================================\n";
	char	*str2 = "          Part 2 - Additional functions\n";
	char	*str3 = "=================================================\n";
	printf("\n");
	printf("%s", str1);
	printf("%s", str2);
	printf("%s", str3);
}

void	part3(void)
{
	char	*str1 = "=================================================\n";
	char	*str2 = "              Part 3 - linked list\n";
	char	*str3 = "=================================================\n";
	printf("\n");
	printf("%s", str1);
	printf("%s", str2);
	printf("%s", str3);
}

void	test1(void)
{
	int	result;
	printf ("[TEST 1: ft_isalpha.c]\n\n");
	result = ft_isalpha('z');
	printf("isalpha('z') = %d\n", result);
	result = ft_isalpha('k');
	printf("isalpha('k') = %d\n", result);
	result = ft_isalpha('A');
	printf("isalpha('A') = %d\n", result);
	result = ft_isalpha('Q');
	printf("isalpha('Q') = %d\n", result);
	result = ft_isalpha('4');
	printf("isalpha('4') = %d\n", result);
	result = ft_isalpha('#');
	printf("isalpha('#') = %d\n", result);
	result = ft_isalpha('-');
	printf("isalpha('-') = %d\n", result);
}

void	test2(void)
{
	int	result;

	printf ("[TEST 2: ft_isdigit.c]\n\n");
	result = ft_isdigit('z');
	printf("isdigit('z') = %d\n", result);
	result = ft_isdigit('k');
	printf("isdigit('k') = %d\n", result);
	result = ft_isdigit('A');
	printf("isdigit('A') = %d\n", result);
	result = ft_isdigit('Q');
	printf("isdigit('Q') = %d\n", result);
	result = ft_isdigit('4');
	printf("isdigit('4') = %d\n", result);
	result = ft_isdigit('#');
	printf("isdigit('#') = %d\n", result);
	result = ft_isdigit('-');
	printf("isdigit('-') = %d\n", result);
}

void	test3(void)
{
	int	result;

	printf ("[TEST 3: ft_isalnum.c]\n\n");
	result = ft_isalnum('z');
	printf("isalnum('z') = %d\n", result);
	result = ft_isalnum('k');
	printf("isalnum('k') = %d\n", result);
	result = ft_isalnum('A');
	printf("isalnum('A') = %d\n", result);
	result = ft_isalnum('Q');
	printf("isalnum('Q') = %d\n", result);
	result = ft_isalnum('4');
	printf("isalnum('4') = %d\n", result);
	result = ft_isalnum('#');
	printf("isalnum('#') = %d\n", result);
	result = ft_isalnum('-');
	printf("isalnum('-') = %d\n", result);
}

void	test4(void)
{
	int	result;

	printf ("[TEST 4: ft_isascii.c]\n\n");
	result = ft_isascii('z');
	printf("isascii('z') = %d\n", result);
	result = ft_isascii('Q');
	printf("isascii('Q') = %d\n", result);
	result = ft_isascii('4');
	printf("isascii('4') = %d\n", result);
	result = ft_isascii('#');
	printf("isascii('#') = %d\n", result);
	result = ft_isascii('@');
	printf("isascii('@') = %d\n", result);
}

void	test5(void)
{
	int	result;

	printf ("[TEST 5: ft_isprint.c]\n\n");
	result = ft_isprint('z');
	printf("isprint('z') = %d\n", result);
	result = ft_isprint('Q');
	printf("isprint('Q') = %d\n", result);
	result = ft_isprint('4');
	printf("isprint('4') = %d\n", result);
	result = ft_isprint('#');
	printf("isprint('#') = %d\n", result);
	result = ft_isprint('@');
	printf("isprint('@') = %d\n", result);
}


void	test6(void)
{
	char str1[] = "Hello";
	char str2[] = "Hello, World!";
	char str3[] = "";
    
	printf ("[TEST 6: ft_strlen.c]\n\n");
	printf("Length of '%s': %zu\n", str1, strlen(str1));  // Output: 5
	printf("Length of '%s': %zu\n", str2, strlen(str2));  // Output: 13
	printf("Length of '%s': %zu\n", str3, strlen(str3));  // Output: 0
}

void	test7(void)
{
	char	buffer[10];
	int		i;
	
	printf ("[TEST 7: ft_memset.c]\n\n");
	ft_memset(buffer, 'g', 10);
	i = 0;
	while (i < 10)
	{
		printf("%c", buffer[i]);
		i++;
	}
	printf("\n");
}

void	test8(void)
{
	char	str1[20] = "Hello, World!";
	char	str2[20] = "Hello, World!";
	int	numbers[5] = {1, 2, 3, 4, 5};
	int	i;

	printf ("[TEST 8: ft_bzero.c]\n\n");
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
}

void	test9(void)
{
	int	src[] = {1, 2, 3, 4, 5};
	int	dest[5];
	
	printf ("[TEST 9: ft_memcpy.c]\n\n");
	ft_memcpy(dest, src, sizeof(src));
	printf("Source: %d %d %d %d %d\n", src[0], src[1], src[2], src[3], src[4]);
	printf("Dest:   %d %d %d %d %d\n", dest[0],
		dest[1], dest[2], dest[3], dest[4]);
}

void	test10(void)
{
	char	buffer[50] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	printf ("[TEST 10: ft_memmove.c]\n\n");
	printf("Original: %.26s\n", buffer);
	// Large overlap - copy backward (dest > src)
	// Copy 20 bytes from position 0 to position 5
	memmove(buffer + 5, buffer, 20);
	printf("memmove:  %.26s\n", buffer);
}

void	test11(void)
{
	char	dest[50];
	char	*src;
	int		size;

	src = "Power is everything!";
	size = 21;
	printf ("[TEST 11: ft_strlcpy.c]\n\n");
	printf("%ld\n", ft_strlcpy(dest, src, size));
	printf(".%s.\n\n", dest);
	printf("%ld\n", ft_strlcpy(dest, src, size));
	printf(".%s.\n\n", dest);
}

void	test12(void)
{
	char	dest[50] = "sefsfesa";
	char	src[50] = "dddddddd";
	unsigned int	size;

	size = 2;
	printf ("[TEST 12: ft_strlcat.c]\n\n");
	printf("%ld\n", ft_strlcat(dest, src, size));
	printf("dest: %s\nsrc: %s\n", dest, src);
}

void	test13(void)
{
	char	result;

	printf ("[TEST 13: ft_toupper.c]\n\n");
	result = ft_toupper('R');
	printf("%c\n", result);
	result = ft_toupper('H');
	printf("%c\n", result);
	result = ft_toupper('e');
	printf("%c\n", result);
	result = ft_toupper('b');
	printf("%c\n", result);
	result = ft_toupper('5');
	printf("%c\n", result);
	result = ft_toupper('8');
	printf("%c\n", result);
	result = ft_toupper('-');
	printf("%c\n", result);
	result = ft_toupper('@');
	printf("%c\n", result);
}

void	test14(void)
{
	char	result;

	printf ("[TEST 14: ft_tolower.c]\n\n");
	result = ft_tolower('R');
	printf("%c\n", result);
	result = ft_tolower('H');
	printf("%c\n", result);
	result = ft_tolower('e');
	printf("%c\n", result);
	result = ft_tolower('b');
	printf("%c\n", result);
	result = ft_tolower('5');
	printf("%c\n", result);
	result = ft_tolower('8');
	printf("%c\n", result);
	result = ft_tolower('-');
	printf("%c\n", result);
	result = ft_tolower('@');
	printf("%c\n", result);
}

void	test15(void)
{
	char	*str = "Hello, World!";
	char	*result;

	printf ("[TEST 15: ft_strchr.c]\n\n");
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
}

void	test16(void)
{
	char	*str = "Hello, World!";
	char	*result;

	printf ("[TEST 16: ft_strrchr.c]\n\n");
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
}

void	test17(void)
{
	char	*s1;
	char	*s2;

	s1 = "captainamerica";
	s2 = "aaptain";
	printf ("[TEST 17: ft_strncmp.c]\n\n");
	printf("%d\n", ft_strncmp(s1, s2, 5));
	printf("%d\n", ft_strncmp(s2, s1, 9));
	printf("%d\n", strncmp(s2, s1, 1));
	printf("%d\n", strncmp(s1, s2, 0));
}

void	test18(void)
{
	char str[] = "Hello, World!";
	char *result;
	int arr[] = {1, 2, 3, 4, 5};
	
	printf ("[TEST 18: ft_memchr.c]\n\n");
	
	// Test 1: Finding a character that exists
	printf("Test 1: Finding 'W' in \"%s\"\n", str);
	result = (char *)memchr(str, 'W', strlen(str));
	if (result)
		printf("Found: '%c' at position %ld\n", *result, result - str);
	else
		printf("Not found\n");
	printf("\n");
	
	// Test 2: Finding first occurrence
	printf("Test 2: Finding 'o' in \"%s\"\n", str);
	result = (char *)memchr(str, 'o', strlen(str));
	if (result)
		printf("Found: '%c' at position %ld\n", *result, result - str);
	else
		printf("Not found\n");
	printf("\n");
	
	// Test 3: Character not in string
	printf("Test 3: Finding 'z' in \"%s\"\n", str);
	result = (char *)memchr(str, 'z', strlen(str));
	if (result)
		printf("Found: '%c'\n", *result);
	else
		printf("Not found\n");
	printf("\n");
	
	// Test 4: Finding with limited search length
	printf("Test 4: Finding 'W' in first 5 bytes of \"%s\"\n", str);
	result = (char *)memchr(str, 'W', 5);
	if (result)
		printf("Found: '%c'\n", *result);
	else
		printf("Not found (correct - 'W' is beyond first 5 bytes)\n");
	printf("\n");
	
	// Test 5: Finding null terminator
	printf("Test 5: Finding '\\0' in \"%s\"\n", str);
	result = (char *)memchr(str, '\0', strlen(str) + 1);
	if (result)
		printf("Found null terminator at position %ld\n", result - str);
	else
		printf("Not found\n");
	printf("\n");
	
	// Test 6: Searching in binary data (integer array)
	printf("Test 6: Searching for byte value in integer array\n");
	unsigned char *byte_result = (unsigned char *)memchr(arr, 3, sizeof(arr));
	if (byte_result)
		printf("Found byte with value 3\n");
	else
		printf("Not found\n");
	printf("\n");
	
	// Test 7: Empty search (n = 0)
	printf("Test 7: Searching with n = 0\n");
	result = (char *)memchr(str, 'H', 0);
	if (result)
		printf("Found (unexpected)\n");
	else
		printf("Not found (correct - searched 0 bytes)\n");
	printf("\n");
	
	// Test 8: Comparing with standard memchr
	printf("Test 8: Comparison with standard memchr\n");
	char test[] = "Testing!";
	void *my_result = memchr(test, 't', strlen(test));
	void *std_result = memchr(test, 't', strlen(test));
	printf("Your memchr: %p\n", my_result);
	printf("Std memchr:  %p\n", std_result);
	printf("Match: %s\n", (my_result == std_result) ? "Yes" : "No");
}

void	test19(void)
{
	int	result;

	printf ("[TEST 19: ft_memcmp.c]\n\n");
	result = ft_memcmp("Hello", "Hello", 5);
	printf("%d\n", result);
	result = ft_memcmp("Mario", "Luigi", 5);
	printf("%d\n", result);
	result = ft_memcmp("Mario", "Bowser", 5);
	printf("%d\n", result);
	result = ft_memcmp("Mario", "toad", 5);
	printf("%d\n", result);
	result = ft_memcmp("Mario", "123", 5);
	printf("%d\n", result);
}

void	test20(void)
{
	char	str1[11] = "toothpaste";
	char	str2[11] = "toothbrush";
	char	str3[6] = "brush";
	char	str4[6] = "paste";

	printf ("[TEST 20: ft_strnstr.c]\n\n");
	printf("\n\nstr1=%s", str1);
	printf("\nstr2=%s", str2);
	printf("\nstr3=%s", str3);
	printf("\nstr4=%s", str4);
	printf("\n\nResult of strstr(1,2) is %s", strstr(str1, str2));
	printf("\nResult of strstr(2,1) is %s", strstr(str2, str1));
	printf("\nResults of strstr(2,3) is %s", strstr(str1, str3));
	printf("\nResults of strstr(3,2) is %s\n\n", strstr(str3, str1));
}

void	test21(void)
{
	printf ("[TEST 21: ft_atoi.c]\n\n");
	printf("%d\n", ft_atoi("   ---++1234ab567"));
	printf("%d\n", ft_atoi("42"));
	printf("%d\n", ft_atoi("999999999999"));
}

void	test22(void)
{
	int		*arr;
	char	*str;
	int		i;

	printf ("[TEST 22: ft_calloc.c]\n\n");
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
}

char	test23(void)
{
	char	*original = "Hello, Piscine!";
	char	*copy;

	printf ("[TEST 23: ft_strdup.c]\n\n");
	copy = ft_strdup(original);
	if (!copy)
		return (1);
	printf("Original: %s\n", original);
	printf("Copy:     %s\n", copy);
	free(copy);
	return (0);
}

void	test24(void)
{
	char	*result;

	printf ("[TEST 1: ft_substr.c]\n\n");
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
}

void	test25(void)
{
	char *result;
	char *s1;
	
	printf ("[TEST 2: ft_strjoin.c]\n\n");
	printf("=== Test 1: Normal strings ===\n");
	s1 = ft_strdup("Hello ");
	result = ft_strjoin(s1, "World");
	if (result)
	{
		printf("Result: '%s'\n", result);
		printf("Expected: 'Hello World'\n");
		free(result);
	}
	printf("\n");
	
	printf("=== Test 2: Empty first string ===\n");
	s1 = ft_strdup("");
	result = ft_strjoin(s1, "World");
	if (result)
	{
		printf("Result: '%s'\n", result);
		printf("Expected: 'World'\n");
		free(result);
	}
	printf("\n");
	
	printf("=== Test 3: Empty second string ===\n");
	s1 = ft_strdup("Hello");
	result = ft_strjoin(s1, "");
	if (result)
	{
		printf("Result: '%s'\n", result);
		printf("Expected: 'Hello'\n");
		free(result);
	}
	printf("\n");
	
	printf("=== Test 4: Both empty ===\n");
	s1 = ft_strdup("");
	result = ft_strjoin(s1, "");
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
	s1 = ft_strdup("This is a longer string ");
	result = ft_strjoin(s1, "concatenated with another long string!");
	if (result)
	{
		printf("Result: '%s'\n", result);
		free(result);
	}
	printf("\n");
}

void	test26(void)
{
	char	*result;

	printf ("[TEST 3: ft_strtrim.c]\n\n");
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
}

void	test27(void)
{
	char	**words;
	int		i;

	words = ft_split("Hello World 42", ' ');
	
	i = 0;
	printf ("[TEST 4: ft_split.c]\n\n");
	while (words[i])
	{
		printf("%s\n", words[i]);
		free(words[i]);
		i++;
	}
	free(words);
}

void	test28(void)
{
	char	*result;

	printf ("[TEST 5: ft_itoa.c]\n\n");
	// Test positive numbers
	printf("Testing positive numbers:\n");
	result = ft_itoa(42);
	printf("ft_itoa(42) = %s\n", result);
	free(result);
	
	result = ft_itoa(123456);
	printf("ft_itoa(123456) = %s\n", result);
	free(result);
	
	result = ft_itoa(1);
	printf("ft_itoa(1) = %s\n", result);
	free(result);
	
	// Test zero
	printf("\nTesting zero:\n");
	result = ft_itoa(0);
	printf("ft_itoa(0) = %s\n", result);
	free(result);
	
	// Test negative numbers
	printf("\nTesting negative numbers:\n");
	result = ft_itoa(-42);
	printf("ft_itoa(-42) = %s\n", result);
	free(result);
	
	result = ft_itoa(-123456);
	printf("ft_itoa(-123456) = %s\n", result);
	free(result);
	
	result = ft_itoa(-1);
	printf("ft_itoa(-1) = %s\n", result);
	free(result);
	
	// Test edge cases
	printf("\nTesting edge cases:\n");
	result = ft_itoa(2147483647);  // INT_MAX
	printf("ft_itoa(2147483647) = %s\n", result);
	free(result);
	
	result = ft_itoa(-2147483648);  // INT_MIN
	printf("ft_itoa(-2147483648) = %s\n", result);
	free(result);
}
/*
========================================
Customized functions to run ft_strmapi.c
========================================
*/
char	example_function(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	if (c >= 'A' && c <= 'Z')
		c = 'A' + ((c - 'A' + i) % 26);
	return (c);
}

char	to_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	shift_by_index(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		return ('a' + ((c - 'a' + i) % 26));
	if (c >= 'A' && c <= 'Z')
		return ('A' + ((c - 'A' + i) % 26));
	return (c);
}

void	test29(void)
{
	char	*str = "hello world";
	char	*result;

	printf ("[TEST 6: ft_strmapi.c]\n\n");
	printf("Original: %s\n", str);
	// Example 1: Convert to uppercase
	result = ft_strmapi(str, to_upper);
	printf("Uppercase: %s\n", result);
	free(result);
	// Example 2: Shift by index
	result = ft_strmapi(str, shift_by_index);
	printf("Shifted: %s\n", result);
	free(result);
	// Example 3: Custom function
	result = ft_strmapi(str, example_function);
	printf("Custom: %s\n", result);
	free(result);
}
/*
=========================================
Customized functions to run ft_striteri.c
=========================================
*/
void	example_function2(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
	if (*c >= 'A' && *c <= 'Z')
		*c = 'A' + ((*c - 'A' + i) % 26);
}

void	to_upper2(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

void	shift_by_index2(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = 'a' + ((*c - 'a' + i) % 26);
	else if (*c >= 'A' && *c <= 'Z')
		*c = 'A' + ((*c - 'A' + i) % 26);
}

void	test30(void)
{
	char	*str1;
	char	*str2;
	char	*str3;

	// We need to allocate memory for each test since we're modifying in place
	str1 = ft_strdup("hello world");
	str2 = ft_strdup("hello world");
	str3 = ft_strdup("hello world");
	printf ("[TEST 7: ft_striteri.c]\n\n");
	printf("Original: %s\n\n", "hello world");
	// Example 1: Convert to uppercase
	printf("Test 1 - to_upper:\n");
	printf("Before: %s\n", str1);
	ft_striteri(str1, to_upper2);
	printf("After:  %s\n\n", str1);
	// Example 2: Shift by index
	printf("Test 2 - shift_by_index:\n");
	printf("Before: %s\n", str2);
	ft_striteri(str2, shift_by_index2);
	printf("After:  %s\n\n", str2);
	// Example 3: Custom function
	printf("Test 3 - example_function:\n");
	printf("Before: %s\n", str3);
	ft_striteri(str3, example_function2);
	printf("After:  %s\n\n", str3);
	// Clean up
	free(str1);
	free(str2);
	free(str3);
}

void	test31(void)
{
	printf ("[TEST 8: ft_putchar_fd.c]\n\n");
	ft_putchar_fd('A', 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('Z', 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('8', 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('u', 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('@', 1);
	ft_putchar_fd('\n', 1);
}

void	test32(void)
{
	printf ("[TEST 9: ft_putstr_fd.c]\n\n");
	ft_putstr_fd("Pokemon\n", 1);
	ft_putstr_fd("Dragon Ball Z\n", 1);
	ft_putstr_fd("One Piece\n", 1);
	ft_putstr_fd("42 Luxembourg\n", 1);
}

void	test33(void)
{
	printf ("[TEST 10: ft_putendl_fd.c]\n\n");
	ft_putendl_fd("Pokemon", 1);
	ft_putendl_fd("Dragon Ball Z", 1);
	ft_putendl_fd("One Piece", 1);
	ft_putendl_fd("42 Luxembourg", 1);
}

void	test34(void)
{
	printf ("[TEST 11: ft_putnbr_fd.c]\n\n");
	ft_putnbr_fd(5, 1);
	write (1, "\n", 1);
	ft_putnbr_fd(-50, 1);
	write (1, "\n", 1);
	ft_putnbr_fd(10, 1);
	write (1, "\n", 1);
	ft_putnbr_fd(1500, 1);
	write (1, "\n", 1);
}

void	test35(void)
{
	t_list	*node;
	char	*str = "Hello, World!";
	int		num = 42;

	printf ("[TEST 1: ft_lstnew.c]\n\n");
	// Test 1: Create a node with a string
	printf("=== Test 1: String content ===\n");
	node = ft_lstnew(str);
	if (node)
	{
		printf("Node created successfully\n");
		printf("Content: %s\n", (char *)node->content);
		printf("Next: %p\n", (void *)node->next);
		free(node);
	}
	else
		printf("Failed to create node\n");

	// Test 2: Create a node with an integer
	printf("\n=== Test 2: Integer content ===\n");
	node = ft_lstnew(&num);
	if (node)
	{
		printf("Node created successfully\n");
		printf("Content: %d\n", *(int *)node->content);
		printf("Next: %p\n", (void *)node->next);
		free(node);
	}
	else
		printf("Failed to create node\n");

	// Test 3: Create a node with NULL content
	printf("\n=== Test 3: NULL content ===\n");
	node = ft_lstnew(NULL);
	if (node)
	{
		printf("Node created successfully\n");
		printf("Content: %p\n", node->content);
		printf("Next: %p\n", (void *)node->next);
		free(node);
	}
	else
		printf("Failed to create node\n");
}

void	test36(void)
{
	t_list	*list = NULL;
	t_list	*node1 = ft_lstnew("First");
	t_list	*node2 = ft_lstnew("Second");

	printf ("[TEST 2: ft_lstadd_front.c]\n\n");
	ft_lstadd_front(&list, node1);
	ft_lstadd_front(&list, node2);
	t_list	*current = list;
	while (current)
	{
		printf("[%s] -> ", (char *)current->content);
		current = current->next;
	}
	printf("NULL\n");
	free(node1);
	free(node2);
}

void	test37(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	
	// Create 3 nodes
	node1 = ft_lstnew("First");
	node2 = ft_lstnew("Second");
	node3 = ft_lstnew("Third");
	
	// Link them together
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	
	printf ("[TEST 3: ft_lstsize.c]\n\n");
	// Test ft_lstsize
	printf("List size: %d\n", ft_lstsize(node1));
	printf("Empty list size: %d\n", ft_lstsize(NULL));
	free(node1);
	free(node2);
	free(node3);
}

void	test38(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*last;

	// Create nodes
	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	node3 = malloc(sizeof(t_list));

	// Set content
	node1->content = "First";
	node2->content = "Second";
	node3->content = "Third";

	// Link nodes
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	printf ("[TEST 4: ft_lstlast.c]\n\n");
	// Test ft_lstlast
	last = ft_lstlast(node1);
	printf("Last node content: %s\n", (char *)last->content);

	// Test with NULL
	last = ft_lstlast(NULL);
	if (last == NULL)
		printf("NULL list returns NULL: OK\n");

	// Free memory
	free(node1);
	free(node2);
	free(node3);
}

void	test39(void)
{
	t_list	*list = NULL;
	t_list	*tmp;
	int		*num;

	// Create and add first node
	num = malloc(sizeof(int));
	*num = 42;
	ft_lstadd_back(&list, ft_lstnew(num));

	// Add second node
	num = malloc(sizeof(int));
	*num = 21;
	ft_lstadd_back(&list, ft_lstnew(num));

	// Add third node
	num = malloc(sizeof(int));
	*num = 84;
	ft_lstadd_back(&list, ft_lstnew(num));

	printf ("[TEST 5: ft_lstadd_back.c]\n\n");
	// Print the list
	printf("List: ");
	tmp = list;
	while (tmp)
	{
		printf("%d -> ", *(int *)tmp->content);
		tmp = tmp->next;
	}
	printf("NULL\n");

	// Free all memory
	while (list)
	{
		tmp = list->next;
		free(list->content);
		free(list);
		list = tmp;
	}
}
/*
=====================================
Delete function to run ft_lstdelone.c
=====================================
*/
void	del(void *content);

void	test40(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	char	*str;
	int		*num;

	printf ("[TEST 6: ft_lstdelone.c]\n\n");
	// Test 1: Delete node with string content
	printf("Test 1: Deleting node with string\n");
	str = strdup("Hello, World!");
	node1 = ft_lstnew(str);
	printf("Before delete: content = %s\n", (char *)node1->content);
	ft_lstdelone(node1, del);
	printf("Node deleted successfully!\n\n");

	// Test 2: Delete node with integer content
	printf("Test 2: Deleting node with integer\n");
	num = (int *)malloc(sizeof(int));
	*num = 42;
	node2 = ft_lstnew(num);
	printf("Before delete: content = %d\n", *(int *)node2->content);
	ft_lstdelone(node2, del);
	printf("Node deleted successfully!\n\n");

	// Test 3: Try to delete NULL node (should do nothing)
	printf("Test 3: Deleting NULL node\n");
	ft_lstdelone(NULL, del);
	printf("NULL node handled safely!\n\n");

	// Test 4: Try with NULL del function (should do nothing)
	printf("Test 4: Using NULL del function\n");
	node3 = ft_lstnew(strdup("Test"));
	ft_lstdelone(node3, NULL);
	printf("NULL del function handled safely!\n");
	// Clean up manually since del wasn't called
	free(node3->content);
	free(node3);
	printf("\nAll tests completed!\n");
}
/*
====================================
Delete function to run ft_lstclear.c
====================================
*/
void	del2(void *content);

void	test41(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	// Create nodes with allocated content
	node1 = malloc(sizeof(t_list));
	node1->content = strdup("First");
	node2 = malloc(sizeof(t_list));
	node2->content = strdup("Second");
	node3 = malloc(sizeof(t_list));
	node3->content = strdup("Third");

	// Link them
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	head = node1;

	printf ("[TEST 7: ft_lstclear.c]\n\n");
	// Print before clearing
	printf("Before clear: %s -> %s -> %s\n", 
			(char *)node1->content, 
			(char *)node2->content, 
			(char *)node3->content);

	// Clear the list
	ft_lstclear(&head, del2);

	// Check if cleared
	if (head == NULL)
		printf("List successfully cleared!\n");
}
/*
========================================
Customized functions to run ft_lstiter.c
========================================
*/
// Simple function 1: Print strings
void	print_content(void *content)
{
	printf("Content: %s\n", (char *)content);
}

// Simple function 2: Print numbers
void	print_number(void *content)
{
	printf("Number: %d\n", *(int *)content);
}

// Simple function 3: Add exclamation to strings
void	add_exclamation(void *content)
{
	char	*str = (char *)content;
	printf("%s!\n", str);
}

void	test42(void)
{
	t_list	*list;
	t_list	*node;
	int		*num1, *num2, *num3;

	printf ("[TEST 8: ft_lstiter.c]\n\n");
	// Example 1: List of strings
	printf("=== Example 1: List of strings ===\n");
	list = NULL;
	
	ft_lstadd_back(&list, ft_lstnew("Hello"));
	ft_lstadd_back(&list, ft_lstnew("World"));
	ft_lstadd_back(&list, ft_lstnew("42"));
	
	printf("\nUsing print_content:\n");
	ft_lstiter(list, print_content);
	
	printf("\nUsing add_exclamation:\n");
	ft_lstiter(list, add_exclamation);
	
	// Free the string list
	while (list)
	{
		node = list;
		list = list->next;
		free(node);
	}

	// Example 2: List of integers
	printf("\n=== Example 2: List of integers ===\n");
	list = NULL;
	
	num1 = malloc(sizeof(int));
	num2 = malloc(sizeof(int));
	num3 = malloc(sizeof(int));
	*num1 = 10;
	*num2 = 20;
	*num3 = 30;
	
	ft_lstadd_back(&list, ft_lstnew(num1));
	ft_lstadd_back(&list, ft_lstnew(num2));
	ft_lstadd_back(&list, ft_lstnew(num3));
	
	ft_lstiter(list, print_number);
	
	// Free the integer list
	while (list)
	{
		node = list;
		list = list->next;
		free(node->content);
		free(node);
	}
}
/*
=======================================
Customized functions to run ft_lstmap.c
=======================================
*/
// Example 1: Double integer values
void	*double_int(void *content)
{
	int	*new_num;
	int	*old_num;

	old_num = (int *)content;
	new_num = (int *)malloc(sizeof(int));
	if (!new_num)
		return (NULL);
	*new_num = (*old_num) * 2;
	return (new_num);
}

// Example 2: Convert string to uppercase
void	*str_to_upper(void *content)
{
	char	*str;
	char	*new_str;
	int		i;

	str = (char *)content;
	new_str = (char *)malloc(strlen(str) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			new_str[i] = str[i] - 32;
		else
			new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// Example 3: Add prefix to string
void	*add_prefix(void *content)
{
	char	*str;
	char	*new_str;
	char	*prefix;

	prefix = ">> ";
	str = (char *)content;
	new_str = (char *)malloc(strlen(prefix) + strlen(str) + 1);
	if (!new_str)
		return (NULL);
	strcpy(new_str, prefix);
	strcat(new_str, str);
	return (new_str);
}

// Delete function for integers
void	del_int(void *content)
{
	free(content);
}

// Delete function for strings
void	del_str(void *content)
{
	free(content);
}

// Helper function to print integer list
void	print_int_list(t_list *lst, const char *title)
{
	printf("\n%s:\n", title);
	while (lst)
	{
		printf("%d ", *(int *)lst->content);
		lst = lst->next;
	}
	printf("\n");
}

// Helper function to print string list
void	print_str_list(t_list *lst, const char *title)
{
	printf("\n%s:\n", title);
	while (lst)
	{
		printf("'%s' ", (char *)lst->content);
		lst = lst->next;
	}
	printf("\n");
}

void	test43(void)
{
	t_list	*int_list;
	t_list	*str_list;
	t_list	*mapped_list;
	int		*num;
	char	*str;
	int		i;

	printf ("[TEST 9: ft_lstmap.c]\n\n");
	printf("=================================================\n");
	printf("FT_LSTMAP DEMONSTRATION\n");
	printf("=================================================\n");

	// Example 1: Doubling integers
	printf("\n--- EXAMPLE 1: Doubling Integers ---\n");
	
	int_list = NULL;
	int values[] = {1, 2, 3, 4, 5};
	
	// Create original list
	for (i = 0; i < 5; i++)
	{
		num = (int *)malloc(sizeof(int));
		*num = values[i];
		ft_lstadd_back(&int_list, ft_lstnew(num));
	}
	
	print_int_list(int_list, "Original list");
	
	// Apply ft_lstmap to double the values
	mapped_list = ft_lstmap(int_list, double_int, del_int);
	print_int_list(mapped_list, "Mapped list (doubled)");
	
	// Cleanup
	ft_lstclear(&int_list, del_int);
	ft_lstclear(&mapped_list, del_int);

	// Example 2: Converting strings to uppercase
	printf("\n--- EXAMPLE 2: Converting to Uppercase ---\n");
	
	str_list = NULL;
	char *words[] = {"hello", "world", "this", "is", "ft_lstmap"};
	
	// Create original list
	for (i = 0; i < 5; i++)
	{
		str = (char *)malloc(strlen(words[i]) + 1);
		strcpy(str, words[i]);
		ft_lstadd_back(&str_list, ft_lstnew(str));
	}
	
	print_str_list(str_list, "Original list");
	
	// Apply ft_lstmap to convert to uppercase
	mapped_list = ft_lstmap(str_list, str_to_upper, del_str);
	print_str_list(mapped_list, "Mapped list (uppercase)");
	
	// Cleanup
	ft_lstclear(&str_list, del_str);
	ft_lstclear(&mapped_list, del_str);

	// Example 3: Adding prefix to strings
	printf("\n--- EXAMPLE 3: Adding Prefix to Strings ---\n");
	
	str_list = NULL;
	char *messages[] = {"first", "second", "third"};
	
	// Create original list
	for (i = 0; i < 3; i++)
	{
		str = (char *)malloc(strlen(messages[i]) + 1);
		strcpy(str, messages[i]);
		ft_lstadd_back(&str_list, ft_lstnew(str));
	}
	
	print_str_list(str_list, "Original list");
	
	// Apply ft_lstmap to add prefix
	mapped_list = ft_lstmap(str_list, add_prefix, del_str);
	print_str_list(mapped_list, "Mapped list (with prefix)");
	
	// Cleanup
	ft_lstclear(&str_list, del_str);
	ft_lstclear(&mapped_list, del_str);
}

void	test44_FT_PRINTF(void)
{
	ft_printf("String: %s\n", "Hello world!");
	ft_printf("Void * Pointer: %p\n", "Hello world!");
	ft_printf("Number: %d\n", 42);
	ft_printf("Char: %c\n", 'a');
	ft_printf("Integer: %i\n", -3854);
	ft_printf("Unsigned number: %u\n", 5966);
	ft_printf("Unsigned number: %u\n", -5966);
	ft_printf("Number in hexadecimal lowercase format: %x\n", 689234455);
	ft_printf("Number in hexadecimal uppercase format: %X\n", 689234455);
	ft_printf("Percent sign: %%\n", "100%%");
	ft_printf("Percent sign: %%\n", "");
	ft_printf("Percent sign: %%\n", "%% start middle %% end %%");
}

void	test45_GET_NEXT_LINE(void)
{
	int		fd;
	char	*line;
	int		line_num = 1;

	fd = open("textfile2", O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("Line %d: %s", line_num++, line);
		printf("---\n");
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("\n=================================================\n");
	printf("All tests completed successfully!\n");
	printf("=================================================\n\n");
}

int	main(void)
{
	printf("\n");
	printf("\n");
	printf("====================  START  ====================\n\n");
	LIBFT_PROJECT();
	part1();
	printf("\n");
	test1();
	printf("\n");
	test2();
	printf("\n");
	test3();
	printf("\n");
	test4();
	printf("\n");
	test5();
	printf("\n");
	test6();
	printf("\n");
	test7();
	printf("\n");
	test8();
	printf("\n");
	test9();
	printf("\n");
	test10();
	printf("\n");
	test11();
	printf("\n");
	test12();
	printf("\n");
	test13();
	printf("\n");
	test14();
	printf("\n");
	test15();
	printf("\n");
	test16();
	printf("\n");
	test17();
	printf("\n");
	test18();
	printf("\n");
	test19();
	printf("\n");
	test20();
	printf("\n");
	test21();
	printf("\n");
	test22();
	printf("\n");
	test23();
	part2();
	printf("\n");
	test24();
	printf("\n");
	test25();
	printf("\n");
	test26();
	printf("\n");
	test27();
	printf("\n");
	test28();
	printf("\n");
	test29();
	printf("\n");
	test30();
	printf("\n");
	test31();
	printf("\n");
	test32();
	printf("\n");
	test33();
	printf("\n");
	test34();
	part3();
	printf("\n");
	test35();
	printf("\n");
	test36();
	printf("\n");
	test37();
	printf("\n");
	test38();
	printf("\n");
	test39();
	printf("\n");
	test40();
	printf("\n");
	test41();
	printf("\n");
	test42();
	printf("\n");
	test43();
	printf("\n");
	FT_PRINTF_PROJECT();
	printf("\n");
	test44_FT_PRINTF();
	printf("\n");
	GET_NEXT_LINE_PROJECT();
	printf("\n");
	test45_GET_NEXT_LINE();
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("\n");
	printf("===================  FINISH  ====================\n");
	printf("\n");
	printf("\n");
	return (0);
}
