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
    t_node *temp2;
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
	printf("stackA--------\n");
	rotate(stackA);
	i = 0;
	temp = (stackA)->top;
	while (i < 3)
	{
		printf("content A: %d\n", temp->content);
		printf("index A: %d\n", temp->index);
		temp = temp->next;
        i++;
	}
    /*
	i = 0;
	temp = stackB->top;
    printf("stackB--------\n");
	while (i < 2)
	{
		printf("content B: %d\n", temp->content);
		printf("index B: %d\n", temp->index);
		temp = temp->next;
        i++;
	}
        */
    temp = stackA->top;
    while(temp != NULL)
    {
        temp2 = temp2->next;
        free(temp);
        temp = temp2;
    }
	free(stackA);
    free(stackB);
	return (0);
}