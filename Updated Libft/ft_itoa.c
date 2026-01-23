/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:55:12 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/12 12:55:19 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static size_t	ft_numlen(long num, int is_negative)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	if (is_negative)
		len++;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	size_t	len;

	num = n;
	if (num < 0)
		num = -num;
	len = ft_numlen(num, n < 0);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

/*int	main(void)
{
	char	*result;
	
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
}*/
