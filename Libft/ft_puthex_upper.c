/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 08:50:52 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/19 08:50:56 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <unistd.h>

int	ft_puthex_upper(unsigned long num)
{
	char	*hex;
	int		count;

	hex = "0123456789ABCDEF";
	count = 0;
	if (num >= 16)
	{
		count += ft_puthex_upper(num / 16);
	}
	write(1, &hex[num % 16], 1);
	count++;
	return (count);
}
