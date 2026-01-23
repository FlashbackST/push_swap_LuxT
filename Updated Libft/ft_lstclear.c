/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:07:48 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/12 13:07:52 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	del2(void *content)
{
	free(content);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

/*int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	// Create nodes with allocated content
	node1 = malloc(sizeof(t_list));
	node1->content = strdup("First");
	node2 = malloc(sizeof(t_list));
	node2->content = strdup("Second");
	node3 = malloc(sizeof(t_list));
	node3->content = strdup("Third");

	// Link them
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	head = node1;

	// Print before clearing
	printf("Before clear: %s -> %s -> %s\n", 
			(char *)node1->content, 
			(char *)node2->content, 
			(char *)node3->content);

	// Clear the list
	ft_lstclear(&head, del2);

	// Check if cleared
	if (head == NULL)
		printf("List successfully cleared!\n");
}*/
