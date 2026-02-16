/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:56:30 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/12 12:56:33 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

/*size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dup;

	i = 0;
	while (src[i])
		i++;
	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
	{
		return (0);
	}
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	example_function(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
	if (*c >= 'A' && *c <= 'Z')
		*c = 'A' + ((*c - 'A' + i) % 26);
}

void	to_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

void	shift_by_index(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = 'a' + ((*c - 'a' + i) % 26);
	else if (*c >= 'A' && *c <= 'Z')
		*c = 'A' + ((*c - 'A' + i) % 26);
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*int	main(void)
{
	char	*str1;
	char	*str2;
	char	*str3;

	// We need to allocate memory for each test since we're modifying in place
	str1 = ft_strdup("hello world");
	str2 = ft_strdup("hello world");
	str3 = ft_strdup("hello world");
	printf("Original: %s\n\n", "hello world");
	// Example 1: Convert to uppercase
	printf("Test 1 - to_upper:\n");
	printf("Before: %s\n", str1);
	ft_striteri(str1, to_upper);
	printf("After:  %s\n\n", str1);
	// Example 2: Shift by index
	printf("Test 2 - shift_by_index:\n");
	printf("Before: %s\n", str2);
	ft_striteri(str2, shift_by_index);
	printf("After:  %s\n\n", str2);
	// Example 3: Custom function
	printf("Test 3 - example_function:\n");
	printf("Before: %s\n", str3);
	ft_striteri(str3, example_function);
	printf("After:  %s\n\n", str3);
	// Clean up
	free(str1);
	free(str2);
	free(str3);
}*/
