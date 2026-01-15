#include "push_swap.h"

void	ft_lstadd_front(t_node *alst, t_node *new)
{
	if (!new)
		return ;
	if (!alst)
	{
		alst = new;
		return ;
	}
	new->next = alst;
	alst = new;
}

t_node	*ft_lstnew(int content, int index)
{
	t_node *list;

	list = malloc(sizeof(t_node));
	if (!list)
		return (NULL);
	list->content = content;
	list->index = index;
	list->next = NULL;
	return (list);
}

void	ft_lstdelone(t_node *lst)
{
	if (!lst)
		return ;
	free(lst);
}