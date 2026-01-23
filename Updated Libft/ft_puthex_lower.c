/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 23:20:12 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/17 23:20:14 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <unistd.h>

int	ft_puthex_lower(unsigned long num)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (num >= 16)
	{
		count += ft_puthex_lower(num / 16);
	}
	write(1, &hex[num % 16], 1);
	count++;
	return (count);
}
