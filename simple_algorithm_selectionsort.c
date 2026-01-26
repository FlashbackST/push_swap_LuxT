/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm_selectionsort.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:37:59 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/26 08:38:12 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//include <stdio.h>

void	selection_sort(t_stack *stack_a, t_stack *stack_b, t_flags *flags)
{
	int	min_pos;

	if (!stack_a || stack_a->size <= 1)
		return ;
	while (stack_a->size > 0)
	{
		min_pos = find_min_position(stack_a);
		rotate_to_min(stack_a, min_pos, flags);
		pb(stack_a, stack_b);
		print_verbose(flags, "pb\n");
	}
	while (stack_b->size > 0)
	{
		pa(stack_a, stack_b);
		print_verbose(flags, "pa\n");
	}
}
