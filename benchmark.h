/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:47:59 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/27 10:48:01 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCHMARK_H
# define BENCHMARK_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_op_counts
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_op_counts;

typedef struct s_benchmark
{
	int				enabled;
	double			disorder;
	const char		*strategy_name;
	const char		*complexity_class;
	t_op_counts		ops;
}	t_benchmark;

void	benchmark_init(t_benchmark *bench, int enabled);
void	benchmark_set_disorder(t_benchmark *bench, double disorder);
void	benchmark_set_strategy(t_benchmark *bench, int stack_size);
void	benchmark_record_op(t_benchmark *bench, const char *op);
void	benchmark_display(t_benchmark *bench);
void	put_nbr_fd(int n, int fd);
void	put_double_fd(double n, int fd);
int		ft_strlen_bench(const char *s);
#endif
