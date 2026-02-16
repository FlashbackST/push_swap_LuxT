/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 02:12:24 by sthinnes          #+#    #+#             */
/*   Updated: 2026/02/14 02:12:28 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

char	*get_next_line(int fd);
int		execute_operation(t_stack *stack_a, t_stack *stack_b, char *op);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);

#endif
