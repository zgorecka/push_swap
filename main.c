#include "push_swap.h"
#include <stdio.h>

t_node	*make_stack(t_stack *stackA, int argc, char *argv[])
{
	t_node	*temp;
	t_node	*prev;

	stackA->size = argc - 1;
	prev = ft_lstnew(ft_atoi(argv[argc - 1]), argc-1);
	while (argc > 2)
	{
		temp = ft_lstnew(ft_atoi(argv[argc - 2]), argc-2);
		ft_lstadd_front(prev, temp);
		prev = temp;
		argc--;
	}
	stackA->top = prev;
	return (prev);
}

int	main(int argc, char *argv[])
{
	int i;
	t_node *temp;
	t_stack *stackA;
	t_stack *stackB;

	stackA = NULL;
	stackB = NULL;

	i = 0;
	stackA = malloc(sizeof(t_stack));
	stackB = malloc(sizeof(t_stack));
	temp = make_stack(stackA, argc, argv);
	while (++i < argc)
	{
		printf("content: %d\n", temp->content);
		printf("index: %d\n", temp->index);
		temp = temp->next;
	}
	printf("--------\n");
	push(stackA, stackB);
	i = 0;
	temp = stackA->top;
	while (++i < argc)
	{
		printf("content A: %d\n", temp->content);
		printf("index A: %d\n", temp->index);
		temp = temp->next;
	}
	i = 0;
	temp = stackA->top;
	while (++i < argc)
	{
		printf("content A: %d\n", temp->content);
		printf("index A: %d\n", temp->index);
		temp = temp->next;
	}
	free(stackA);

	return (0);
}