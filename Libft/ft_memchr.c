/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:35:47 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/08 19:35:50 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
		{
			return ((void *)(ptr + i));
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char str[] = "Hello, World!";
	char *result;
	int arr[] = {1, 2, 3, 4, 5};
	
	printf("=== Testing memchr ===\n\n");
	
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
}*/
