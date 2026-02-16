/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_disorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 21:23:46 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/26 21:23:48 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_disorder(double disorder)
{
	int	whole;
	int	decimal;

	whole = (int)disorder;
	decimal = (int)((disorder - whole) * 100);
	ft_printf("Initial disorder: %d.", whole);
	if (decimal < 10)
		ft_printf("0");
	ft_printf("%d\n\n", decimal);
}
