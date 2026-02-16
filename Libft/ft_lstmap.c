/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthinnes <sthinnes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:08:47 by sthinnes          #+#    #+#             */
/*   Updated: 2026/01/12 13:08:54 by sthinnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/*
// Example 1: Double integer values
void	*double_int(void *content)
{
	int	*new_num;
	int	*old_num;

	old_num = (int *)content;
	new_num = (int *)malloc(sizeof(int));
	if (!new_num)
		return (NULL);
	*new_num = (*old_num) * 2;
	return (new_num);
}

// Example 2: Convert string to uppercase
void	*str_to_upper(void *content)
{
	char	*str;
	char	*new_str;
	int		i;

	str = (char *)content;
	new_str = (char *)malloc(strlen(str) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			new_str[i] = str[i] - 32;
		else
			new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// Example 3: Add prefix to string
void	*add_prefix(void *content)
{
	char	*str;
	char	*new_str;
	char	*prefix;

	prefix = ">> ";
	str = (char *)content;
	new_str = (char *)malloc(strlen(prefix) + strlen(str) + 1);
	if (!new_str)
		return (NULL);
	strcpy(new_str, prefix);
	strcat(new_str, str);
	return (new_str);
}

// Delete function for integers
void	del_int(void *content)
{
	free(content);
}

// Delete function for strings
void	del_str(void *content)
{
	free(content);
}

// Helper function to print integer list
void	print_int_list(t_list *lst, const char *title)
{
	printf("\n%s:\n", title);
	while (lst)
	{
		printf("%d ", *(int *)lst->content);
		lst = lst->next;
	}
	printf("\n");
}

// Helper function to print string list
void	print_str_list(t_list *lst, const char *title)
{
	printf("\n%s:\n", title);
	while (lst)
	{
		printf("'%s' ", (char *)lst->content);
		lst = lst->next;
	}
	printf("\n");
}

int	main(void)
{
	t_list	*int_list;
	t_list	*str_list;
	t_list	*mapped_list;
	int		*num;
	char	*str;
	int		i;

	printf("=================================================\n");
	printf("FT_LSTMAP DEMONSTRATION\n");
	printf("=================================================\n");

	// Example 1: Doubling integers
	printf("\n--- EXAMPLE 1: Doubling Integers ---\n");
	
	int_list = NULL;
	int values[] = {1, 2, 3, 4, 5};
	
	// Create original list
	for (i = 0; i < 5; i++)
	{
		num = (int *)malloc(sizeof(int));
		*num = values[i];
		ft_lstadd_back(&int_list, ft_lstnew(num));
	}
	
	print_int_list(int_list, "Original list");
	
	// Apply ft_lstmap to double the values
	mapped_list = ft_lstmap(int_list, double_int, del_int);
	print_int_list(mapped_list, "Mapped list (doubled)");
	
	// Cleanup
	ft_lstclear(&int_list, del_int);
	ft_lstclear(&mapped_list, del_int);

	// Example 2: Converting strings to uppercase
	printf("\n--- EXAMPLE 2: Converting to Uppercase ---\n");
	
	str_list = NULL;
	char *words[] = {"hello", "world", "this", "is", "ft_lstmap"};
	
	// Create original list
	for (i = 0; i < 5; i++)
	{
		str = (char *)malloc(strlen(words[i]) + 1);
		strcpy(str, words[i]);
		ft_lstadd_back(&str_list, ft_lstnew(str));
	}
	
	print_str_list(str_list, "Original list");
	
	// Apply ft_lstmap to convert to uppercase
	mapped_list = ft_lstmap(str_list, str_to_upper, del_str);
	print_str_list(mapped_list, "Mapped list (uppercase)");
	
	// Cleanup
	ft_lstclear(&str_list, del_str);
	ft_lstclear(&mapped_list, del_str);

	// Example 3: Adding prefix to strings
	printf("\n--- EXAMPLE 3: Adding Prefix to Strings ---\n");
	
	str_list = NULL;
	char *messages[] = {"first", "second", "third"};
	
	// Create original list
	for (i = 0; i < 3; i++)
	{
		str = (char *)malloc(strlen(messages[i]) + 1);
		strcpy(str, messages[i]);
		ft_lstadd_back(&str_list, ft_lstnew(str));
	}
	
	print_str_list(str_list, "Original list");
	
	// Apply ft_lstmap to add prefix
	mapped_list = ft_lstmap(str_list, add_prefix, del_str);
	print_str_list(mapped_list, "Mapped list (with prefix)");
	
	// Cleanup
	ft_lstclear(&str_list, del_str);
	ft_lstclear(&mapped_list, del_str);

	printf("\n=================================================\n");
	printf("All tests completed successfully!\n");
	printf("=================================================\n\n");
}
*/
