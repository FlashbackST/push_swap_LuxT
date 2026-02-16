/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm_utils4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 22:25:25 by sthinnes          #+#    #+#             */
/*   Updated: 2026/02/10 22:25:31 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "benchmark.h"

static void	set_simple_strategy(t_benchmark *bench)
{
	bench->strategy_name = "Insertion sort";
	bench->complexity_class = "O(n^2)";
}

static void	set_medium_strategy(t_benchmark *bench)
{
	bench->strategy_name = "Bucket sort";
	bench->complexity_class = "O(n√n)";
}

static void	set_complex_strategy(t_benchmark *bench)
{
	bench->strategy_name = "Turk sort";
	bench->complexity_class = "O(n log n)";
}

static void	set_adaptive_strategy(t_benchmark *bench)
{
	bench->strategy_name = "Adaptive";
	bench->complexity_class = "varies";
}

void	set_strategy_name(t_benchmark *bench, int algo_idx)
{
	if (algo_idx == 0)
		set_simple_strategy(bench);
	else if (algo_idx == 1)
		set_medium_strategy(bench);
	else if (algo_idx == 2)
		set_complex_strategy(bench);
	else if (algo_idx == 3)
		set_adaptive_strategy(bench);
}
