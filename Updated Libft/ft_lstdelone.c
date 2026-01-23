/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:06:56 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/12 13:06:58 by sthinnes         ###   ########.fr       */
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

void	del(void *content)
{
	free(content);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
	{
		return ;
	}
	del(lst->content);
	free(lst);
}

/*int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	char	*str;
	int		*num;

	// Test 1: Delete node with string content
	printf("Test 1: Deleting node with string\n");
	str = strdup("Hello, World!");
	node1 = ft_lstnew(str);
	printf("Before delete: content = %s\n", (char *)node1->content);
	ft_lstdelone(node1, del);
	printf("Node deleted successfully!\n\n");

	// Test 2: Delete node with integer content
	printf("Test 2: Deleting node with integer\n");
	num = (int *)malloc(sizeof(int));
	*num = 42;
	node2 = ft_lstnew(num);
	printf("Before delete: content = %d\n", *(int *)node2->content);
	ft_lstdelone(node2, del);
	printf("Node deleted successfully!\n\n");

	// Test 3: Try to delete NULL node (should do nothing)
	printf("Test 3: Deleting NULL node\n");
	ft_lstdelone(NULL, del);
	printf("NULL node handled safely!\n\n");

	// Test 4: Try with NULL del function (should do nothing)
	printf("Test 4: Using NULL del function\n");
	node3 = ft_lstnew(strdup("Test"));
	ft_lstdelone(node3, NULL);
	printf("NULL del function handled safely!\n");
	// Clean up manually since del wasn't called
	free(node3->content);
	free(node3);
	printf("\nAll tests completed!\n");
}*/
