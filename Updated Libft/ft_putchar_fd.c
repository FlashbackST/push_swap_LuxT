/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:56:57 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/12 12:57:05 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*int	main(void)
{
	ft_putchar_fd('A', 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('Z', 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('8', 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('u', 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('@', 1);
	ft_putchar_fd('\n', 1);
}*/
