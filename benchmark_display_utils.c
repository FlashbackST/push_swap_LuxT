/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_display_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:04:39 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/27 12:04:43 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark.h"
#include <unistd.h>

void	put_nbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			write(fd, "2147483648", 10);
			return ;
		}
		n = -n;
	}
	if (n >= 10)
		put_nbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void	put_double_fd(double n, int fd)
{
	int	integer_part;
	int	decimal_part;

	integer_part = (int)n;
	decimal_part = (int)((n - integer_part) * 100);
	put_nbr_fd(integer_part, fd);
	if (decimal_part != 0)
	{
		write(fd, ".", 1);
		if (decimal_part < 10)
			write(fd, "0", 1);
		put_nbr_fd(decimal_part, fd);
	}
}

int	ft_strlen_bench(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
