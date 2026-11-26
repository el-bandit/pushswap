/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfleskes <viktor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 13:10:51 by vfleskes          #+#    #+#             */
/*   Updated: 2026/11/26 14:32:48 by vfleskes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int num)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode->value = num;
	newnode->next = NULL;
	return (newnode);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*curr;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
}

void	ft_lstclear(t_node **lst)
{
	t_node	*curr;
	t_node	*nextnode;

	if (!lst)
		return ;
	curr = *lst;
	while (curr)
	{
		nextnode = curr->next;
		free(curr);
		curr = nextnode;
	}
	*lst = NULL;
}
