/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:56:06 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/12 12:56:11 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlen(const char *s);

/*char	example_function(unsigned int i, char c)
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
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*int	main(void)
{
	char	*str = "hello world";
	char	*result;

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
}*/
