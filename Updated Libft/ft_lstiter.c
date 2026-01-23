/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:08:20 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/12 13:08:21 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
	{
		return ;
	}
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

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
}

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

// Simple function 1: Print strings
void	print_content(void *content)
{
	printf("Content: %s\n", (char *)content);
}

// Simple function 2: Print numbers
void	print_number(void *content)
{
	printf("Number: %d\n", *(int *)content);
}

// Simple function 3: Add exclamation to strings
void	add_exclamation(void *content)
{
	char	*str = (char *)content;
	printf("%s!\n", str);
}

int	main(void)
{
	t_list	*list;
	t_list	*node;
	int		*num1, *num2, *num3;

	// Example 1: List of strings
	printf("=== Example 1: List of strings ===\n");
	list = NULL;
	
	ft_lstadd_back(&list, ft_lstnew("Hello"));
	ft_lstadd_back(&list, ft_lstnew("World"));
	ft_lstadd_back(&list, ft_lstnew("42"));
	
	printf("\nUsing print_content:\n");
	ft_lstiter(list, print_content);
	
	printf("\nUsing add_exclamation:\n");
	ft_lstiter(list, add_exclamation);
	
	// Free the string list
	while (list)
	{
		node = list;
		list = list->next;
		free(node);
	}

	// Example 2: List of integers
	printf("\n=== Example 2: List of integers ===\n");
	list = NULL;
	
	num1 = malloc(sizeof(int));
	num2 = malloc(sizeof(int));
	num3 = malloc(sizeof(int));
	*num1 = 10;
	*num2 = 20;
	*num3 = 30;
	
	ft_lstadd_back(&list, ft_lstnew(num1));
	ft_lstadd_back(&list, ft_lstnew(num2));
	ft_lstadd_back(&list, ft_lstnew(num3));
	
	ft_lstiter(list, print_number);
	
	// Free the integer list
	while (list)
	{
		node = list;
		list = list->next;
		free(node->content);
		free(node);
	}
}*/
