/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm_bucketsort_helpers.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:11:37 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/28 19:11:40 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_in_array(int *arr, int n)
{
	int	min;
	int	i;

	min = arr[0];
	i = 1;
	while (i < n)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
}

int	find_max_in_array(int *arr, int n)
{
	int	max;
	int	i;

	max = arr[0];
	i = 1;
	while (i < n)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}
