/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 22:51:41 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/17 22:51:45 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <unistd.h>

int	ft_putptr(void *ptr)
{
	int				count;
	unsigned long	addr;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	addr = (unsigned long)ptr;
	write(1, "0x", 2);
	count = 2;
	count += ft_puthex_lower(addr);
	return (count);
}
