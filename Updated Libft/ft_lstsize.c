/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:05:15 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/12 13:05:17 by sthinnes         ###   ########.fr       */
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

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

/*int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	
	// Create 3 nodes
	node1 = ft_lstnew("First");
	node2 = ft_lstnew("Second");
	node3 = ft_lstnew("Third");
	
	// Link them together
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	
	// Test ft_lstsize
	printf("List size: %d\n", ft_lstsize(node1));
	printf("Empty list size: %d\n", ft_lstsize(NULL));
	free(node1);
	free(node2);
	free(node3);
}*/
