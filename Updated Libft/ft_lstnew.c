/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:03:41 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/12 13:03:48 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

t_list	*ft_lstnew(void *content)
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
}

/*int	main(void)
{
	t_list	*node;
	char	*str = "Hello, World!";
	int		num = 42;

	// Test 1: Create a node with a string
	printf("=== Test 1: String content ===\n");
	node = ft_lstnew(str);
	if (node)
	{
		printf("Node created successfully\n");
		printf("Content: %s\n", (char *)node->content);
		printf("Next: %p\n", (void *)node->next);
		free(node);
	}
	else
		printf("Failed to create node\n");

	// Test 2: Create a node with an integer
	printf("\n=== Test 2: Integer content ===\n");
	node = ft_lstnew(&num);
	if (node)
	{
		printf("Node created successfully\n");
		printf("Content: %d\n", *(int *)node->content);
		printf("Next: %p\n", (void *)node->next);
		free(node);
	}
	else
		printf("Failed to create node\n");

	// Test 3: Create a node with NULL content
	printf("\n=== Test 3: NULL content ===\n");
	node = ft_lstnew(NULL);
	if (node)
	{
		printf("Node created successfully\n");
		printf("Content: %p\n", node->content);
		printf("Next: %p\n", (void *)node->next);
		free(node);
	}
	else
		printf("Failed to create node\n");
}*/
