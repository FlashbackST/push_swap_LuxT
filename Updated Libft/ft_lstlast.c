/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:05:43 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/12 13:05:46 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
	{
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/*int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*last;

	// Create nodes
	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	node3 = malloc(sizeof(t_list));

	// Set content
	node1->content = "First";
	node2->content = "Second";
	node3->content = "Third";

	// Link nodes
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	// Test ft_lstlast
	last = ft_lstlast(node1);
	printf("Last node content: %s\n", (char *)last->content);

	// Test with NULL
	last = ft_lstlast(NULL);
	if (last == NULL)
		printf("NULL list returns NULL: OK\n");

	// Free memory
	free(node1);
	free(node2);
	free(node3);
}*/
