/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:50:35 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/27 10:50:40 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark.h"

static void	display_header(t_benchmark *bench)
{
	write(2, "\n=== BENCHMARK RESULTS ===\n", 28);
	write(2, "Initial disorder: ", 18);
	put_double_fd(bench->disorder, 2);
	write(2, "%\n", 2);
	if (bench->strategy_name)
	{
		write(2, "Strategy: ", 10);
		write(2, bench->strategy_name, ft_strlen_bench(bench->strategy_name));
		write(2, "\n", 1);
	}
	if (bench->complexity_class)
	{
		write(2, "Complexity: ", 12);
		write(2, bench->complexity_class,
			ft_strlen_bench(bench->complexity_class));
		write(2, "\n", 1);
	}
	write(2, "Total operations: ", 18);
	put_nbr_fd(bench->ops.total, 2);
	write(2, "\n\nOperation breakdown:\n", 23);
}

static void	display_swap_ops(t_op_counts *ops)
{
	write(2, "  sa:  ", 7);
	put_nbr_fd(ops->sa, 2);
	write(2, "\n  sb:  ", 8);
	put_nbr_fd(ops->sb, 2);
	write(2, "\n  ss:  ", 8);
	put_nbr_fd(ops->ss, 2);
	write(2, "\n", 1);
}

static void	display_push_ops(t_op_counts *ops)
{
	write(2, "  pa:  ", 7);
	put_nbr_fd(ops->pa, 2);
	write(2, "\n  pb:  ", 8);
	put_nbr_fd(ops->pb, 2);
	write(2, "\n", 1);
}

static void	display_rotate_ops(t_op_counts *ops)
{
	write(2, "  ra:  ", 7);
	put_nbr_fd(ops->ra, 2);
	write(2, "\n  rb:  ", 8);
	put_nbr_fd(ops->rb, 2);
	write(2, "\n  rr:  ", 8);
	put_nbr_fd(ops->rr, 2);
	write(2, "\n  rra: ", 8);
	put_nbr_fd(ops->rra, 2);
	write(2, "\n  rrb: ", 8);
	put_nbr_fd(ops->rrb, 2);
	write(2, "\n  rrr: ", 8);
	put_nbr_fd(ops->rrr, 2);
	write(2, "\n", 1);
}

void	benchmark_display(t_benchmark *bench)
{
	if (!bench || !bench->enabled)
		return ;
	display_header(bench);
	display_swap_ops(&bench->ops);
	display_push_ops(&bench->ops);
	display_rotate_ops(&bench->ops);
	write(2, "========================\n", 25);
}
