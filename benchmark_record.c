/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_record.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:49:46 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/27 10:49:53 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark.h"
#include "flags.h"

static void	record_swap_ops(t_benchmark *bench, const char *op)
{
	if (ft_strcmp(op, "sa") == 0)
		bench->ops.sa++;
	else if (ft_strcmp(op, "sb") == 0)
		bench->ops.sb++;
	else if (ft_strcmp(op, "ss") == 0)
		bench->ops.ss++;
}

static void	record_push_ops(t_benchmark *bench, const char *op)
{
	if (ft_strcmp(op, "pa") == 0)
		bench->ops.pa++;
	else if (ft_strcmp(op, "pb") == 0)
		bench->ops.pb++;
}

static void	record_rotate_ops(t_benchmark *bench, const char *op)
{
	if (ft_strcmp(op, "ra") == 0)
		bench->ops.ra++;
	else if (ft_strcmp(op, "rb") == 0)
		bench->ops.rb++;
	else if (ft_strcmp(op, "rr") == 0)
		bench->ops.rr++;
}

static void	record_reverse_ops(t_benchmark *bench, const char *op)
{
	if (ft_strcmp(op, "rra") == 0)
		bench->ops.rra++;
	else if (ft_strcmp(op, "rrb") == 0)
		bench->ops.rrb++;
	else if (ft_strcmp(op, "rrr") == 0)
		bench->ops.rrr++;
}

void	benchmark_record_op(t_benchmark *bench, const char *op)
{
	if (!bench || !bench->enabled)
		return ;
	bench->ops.total++;
	record_swap_ops(bench, op);
	record_push_ops(bench, op);
	record_rotate_ops(bench, op);
	record_reverse_ops(bench, op);
}
