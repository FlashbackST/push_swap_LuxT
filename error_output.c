/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:48:51 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/26 17:49:00 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include <stdio.h>

int	error_output(int argc, char **argv)
{
	if (check_if_numbers(argc, argv))
	{
		write (2, "Error\n", 6);
		exit (1);
	}
	if (check_if_outside_valid_range(argc, argv))
	{
		write (2, "Error\n", 6);
		exit (1);
	}
	return (0);
}
