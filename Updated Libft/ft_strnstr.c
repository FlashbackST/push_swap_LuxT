/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 19:37:06 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/08 19:37:13 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == '\0')
	{
		return ((char *)big);
	}
	while (big[i] && i < len)
	{
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
			{
				return ((char *)&big[i]);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	str1[11] = "toothpaste";
	char	str2[11] = "toothbrush";
	char	str3[6] = "brush";
	char	str4[6] = "paste";

	printf("\n\nstr1=%s", str1);
	printf("\nstr2=%s", str2);
	printf("\nstr3=%s", str3);
	printf("\nstr4=%s", str4);
	printf("\n\nResult of strstr(1,2) is %s", strstr(str1, str2));
	printf("\nResult of strstr(2,1) is %s", strstr(str2, str1));
	printf("\nResults of strstr(2,3) is %s", strstr(str1, str3));
	printf("\nResults of strstr(3,2) is %s\n\n", strstr(str3, str1));
}*/
