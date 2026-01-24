/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:22:35 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/24 13:22:43 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include <stdio.h>

void	copy_stack(t_stack *dest, t_stack *src)
{
	int	i;

	if (!dest || !src)
		return ;
	i = 0;
	while (i < src->size)
	{
		dest->collection[i] = src->collection[i];
		i++;
	}
	dest->size = src->size;
}
