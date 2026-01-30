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

static void	print_op(const char *name, int count)
{
	write(2, name, ft_strlen_bench(name));
	write(2, ":  ", 3);
	put_nbr_fd(count, 2);
}

static void	print_swap_push_ops(t_op_counts *ops)
{
	write(2, "\n[bench]    ", 12);
	print_op("sa", ops->sa);
	write(2, "    ", 4);
	print_op("sb", ops->sb);
	write(2, "    ", 4);
	print_op("ss", ops->ss);
	write(2, "    ", 4);
	print_op("pa", ops->pa);
	write(2, "    ", 4);
	print_op("pb", ops->pb);
}

static void	print_rotate_ops(t_op_counts *ops)
{
	write(2, "\n[bench]    ", 12);
	print_op("ra", ops->ra);
	write(2, "    ", 4);
	print_op("rb", ops->rb);
	write(2, "    ", 4);
	print_op("rr", ops->rr);
	write(2, "    ", 4);
	print_op("rra", ops->rra);
	write(2, "    ", 4);
	print_op("rrb", ops->rrb);
	write(2, "    ", 4);
	print_op("rrr", ops->rrr);
	write(2, "\n", 1);
}

void	benchmark_display(t_benchmark *bench)
{
	if (!bench || !bench->enabled)
		return ;
	write(2, "\n[bench] disorder: ", 18);
	put_double_fd(bench->disorder * 100, 2);
	write(2, "%\n", 2);
	if (bench->strategy_name && bench->complexity_class)
	{
		write(2, "[bench] strategy: ", 18);
		write(2, bench->strategy_name, ft_strlen_bench(bench->strategy_name));
		write(2, " / ", 3);
		write(2, bench->complexity_class,
			ft_strlen_bench(bench->complexity_class));
		write(2, "\n", 1);
	}
	write(2, "[bench] total_ops: ", 19);
	put_nbr_fd(bench->ops.total, 2);
	print_swap_push_ops(&bench->ops);
	print_rotate_ops(&bench->ops);
}
