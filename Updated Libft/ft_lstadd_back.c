/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:06:15 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/12 13:06:16 by sthinnes         ###   ########.fr       */
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new;
}

/*int	main(void)
{
	t_list	*list = NULL;
	t_list	*tmp;
	int		*num;

	// Create and add first node
	num = malloc(sizeof(int));
	*num = 42;
	ft_lstadd_back(&list, ft_lstnew(num));

	// Add second node
	num = malloc(sizeof(int));
	*num = 21;
	ft_lstadd_back(&list, ft_lstnew(num));

	// Add third node
	num = malloc(sizeof(int));
	*num = 84;
	ft_lstadd_back(&list, ft_lstnew(num));

	// Print the list
	printf("List: ");
	tmp = list;
	while (tmp)
	{
		printf("%d -> ", *(int *)tmp->content);
		tmp = tmp->next;
	}
	printf("NULL\n");

	// Free all memory
	while (list)
	{
		tmp = list->next;
		free(list->content);
		free(list);
		list = tmp;
	}
}*/
