/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:00:51 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/12 13:00:53 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

/*int	main(void)
{
	ft_putnbr_fd(5, 1);
	write (1, "\n", 1);
	ft_putnbr_fd(-50, 1);
	write (1, "\n", 1);
	ft_putnbr_fd(10, 1);
	write (1, "\n", 1);
	ft_putnbr_fd(1500, 1);
	write (1, "\n", 1);
}*/
