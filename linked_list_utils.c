/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgorecka <zgorecka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:42:59 by zgorecka          #+#    #+#             */
/*   Updated: 2026/02/04 18:46:09 by zgorecka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_node **alst, t_node *new)
{
	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	(*alst)->prev = new;
	new->next = (*alst);
	new->prev = NULL;
	*alst = new;
}

t_node	*ft_lstnew(int content, int index)
{
	t_node	*list;

	list = malloc(sizeof(t_node));
	if (!list)
		return (NULL);
	list->content = content;
	list->index = index;
	list->next = NULL;
	list->prev = NULL;
	list->target_node = NULL;
	return (list);
}

void	ft_lstdelone(t_node *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	last = ft_lstlast(*lst);
	if (last)
	{
		last->next = new;
		new->prev = last;
	}
	else
		*lst = new;
}

t_node	*ft_lstlast(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while ((*lst).next != NULL)
	{
		lst = (*lst).next;
	}
	return (lst);
}
