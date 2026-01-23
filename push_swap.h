/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:26:13 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/22 22:26:17 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>

typedef struct s_stack
{
	int	*collection;
	int	capacity;
	int	size;
}	t_stack;

t_stack	*create_stack(int capacity);
int		ft_atoi(const char *nptr);
void	stack_add_bottom(t_stack *stack, int value);
void	print_stack(t_stack *stack, char *name);
void	free_stack(t_stack *stack);
t_stack	*parse_arguments(int argc, char **argv);
#endif
