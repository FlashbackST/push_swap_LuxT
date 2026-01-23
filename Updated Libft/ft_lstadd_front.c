/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:04:33 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/12 13:04:36 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

/*t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
	{
		return ;
	}
	new->next = *lst;
	*lst = new;
}

/*int	main(void)
{
	t_list	*list = NULL;
	t_list	*node1 = ft_lstnew("First");
	t_list	*node2 = ft_lstnew("Second");

	ft_lstadd_front(&list, node1);
	ft_lstadd_front(&list, node2);
	t_list	*current = list;
	while (current)
	{
		printf("[%s] -> ", (char *)current->content);
		current = current->next;
	}
	printf("NULL\n");
	free(node1);
	free(node2);
}*/
