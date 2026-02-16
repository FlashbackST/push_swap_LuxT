/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 02:12:08 by sthinnes          #+#    #+#             */
/*   Updated: 2026/02/14 02:12:12 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	check_result(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size != 0)
		return (0);
	return (is_sorted(stack_a));
}

static void	handle_error(t_stack *a, t_stack *b, char *line)
{
	write(2, "Error\n", 6);
	if (line)
		free(line);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	exit(1);
}

static void	read_and_execute(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;
	int		result;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		result = execute_operation(stack_a, stack_b, line);
		free(line);
		if (result == -1)
			handle_error(stack_a, stack_b, NULL);
	}
}

static int	validate_input(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (check_if_numbers(argc, argv))
		return (write(2, "Error\n", 6), 1);
	if (check_if_outside_valid_range(argc, argv))
		return (write(2, "Error\n", 6), 1);
	return (-1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		num_count;
	int		status;

	status = validate_input(argc, argv);
	if (status != -1)
		return (status);
	num_count = count_numbers(argc, argv);
	stack_a = parse_arguments(argc, argv);
	stack_b = create_stack(num_count);
	if (!stack_a || !stack_b || check_for_duplicates(stack_a))
		handle_error(stack_a, stack_b, NULL);
	read_and_execute(stack_a, stack_b);
	if (check_result(stack_a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
