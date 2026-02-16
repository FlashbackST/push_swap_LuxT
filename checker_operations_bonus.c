/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 02:12:54 by sthinnes          #+#    #+#             */
/*   Updated: 2026/02/14 02:13:07 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	exec_swap_ops(t_stack *stack_a, t_stack *stack_b, char *op)
{
	if (ft_strcmp(op, "sa\n") == 0)
		sa(stack_a, NULL);
	else if (ft_strcmp(op, "sb\n") == 0)
		sb(stack_b, NULL);
	else if (ft_strcmp(op, "ss\n") == 0)
		ss(stack_a, stack_b, NULL);
	else
		return (0);
	return (1);
}

static int	exec_push_ops(t_stack *stack_a, t_stack *stack_b, char *op)
{
	if (ft_strcmp(op, "pa\n") == 0)
		pa(stack_a, stack_b, NULL);
	else if (ft_strcmp(op, "pb\n") == 0)
		pb(stack_a, stack_b, NULL);
	else
		return (0);
	return (1);
}

static int	exec_rotate_ops(t_stack *stack_a, t_stack *stack_b, char *op)
{
	if (ft_strcmp(op, "ra\n") == 0)
		ra(stack_a, NULL);
	else if (ft_strcmp(op, "rb\n") == 0)
		rb(stack_b, NULL);
	else if (ft_strcmp(op, "rr\n") == 0)
		rr(stack_a, stack_b, NULL);
	else
		return (0);
	return (1);
}

static int	exec_reverse_ops(t_stack *stack_a, t_stack *stack_b, char *op)
{
	if (ft_strcmp(op, "rra\n") == 0)
		rra(stack_a, NULL);
	else if (ft_strcmp(op, "rrb\n") == 0)
		rrb(stack_b, NULL);
	else if (ft_strcmp(op, "rrr\n") == 0)
		rrr(stack_a, stack_b, NULL);
	else
		return (0);
	return (1);
}

int	execute_operation(t_stack *stack_a, t_stack *stack_b, char *op)
{
	if (exec_swap_ops(stack_a, stack_b, op))
		return (0);
	if (exec_push_ops(stack_a, stack_b, op))
		return (0);
	if (exec_rotate_ops(stack_a, stack_b, op))
		return (0);
	if (exec_reverse_ops(stack_a, stack_b, op))
		return (0);
	return (-1);
}
