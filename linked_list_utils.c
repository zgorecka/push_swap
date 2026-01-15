#include "push_swap.h"

void	ft_lstadd_front(t_list *alst, t_list *new)
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

t_list	*ft_lstnew(int content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}