#include "push_swap.h"
#include <stdio.h>

t_node	*make_stack(t_stack *stackA, int argc, char *argv[])
{
	t_node	*temp;
	t_node	*prev;

	stackA->size = argc - 1;
	stackA->bottom = ft_lstnew(ft_atoi(argv[argc - 1]), argc-1);
    prev = stackA->bottom;
	while (argc > 2)
	{
		temp = ft_lstnew(ft_atoi(argv[argc - 2]), argc-2);
		ft_lstadd_front(&prev, temp);
		prev = temp;
		argc--;
	}
	stackA->top = prev;
	return (prev);
}

int is_sorted(t_stack *stackA)
{
	t_node *prev;
	t_node *temp;

	prev = stackA->top;
	temp = stackA->top->next;

	while(temp->next != NULL)
	{
		if (prev->content >= temp->content)
			return (-1);
		prev = temp;
		temp = temp->next;
	}
	return (1);
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
	if (input_checker(argc, argv) == -1 || is_args_num(argv) == -1)
		return 0;
	stackA = malloc(sizeof(t_stack));
	stackB = malloc(sizeof(t_stack));
	temp = make_stack(stackA, argc, argv);
	if (argc == 3 && is_sorted(stackA) == -1)
	{
		sa(stackA);
		return ;
	}
	else if (argc == 4 && is_sorted(stackA) == -1)
	{
		sort3(stackA);
		return ;
	}
		
	temp = stackA->top;
	while (++i < argc)
	{
		printf("content: %d\n", temp->content);
		printf("index: %d\n", temp->index);
		temp = temp->next;
	}
	printf("stackA--------\n");
	sort(stackA, stackB);

	i = 0;
	temp = stackA->top;
	while (i < 3)
	{
		printf("content A: %d\n", temp->content);
		printf("index A: %d\n", temp->index);
		printf("content of target: %d\n", temp->target_node->content);
		temp = temp->next;
        i++;
	}
	printf("is sorted: %d\n", is_sorted(stackA));
    /*
	i = 0;
	temp = stackB->bottom;
    printf("stackB--------\n");
	while (i < 1)
	{
		printf("content B: %d\n", temp->content);
		printf("index B: %d\n", temp->index);
		temp = temp->prev;
        i++;
	}
      */  
    temp = stackA->top;
    while(temp != NULL)
    {
        temp2 = temp->next;
        free(temp);
        temp = temp2;
    }
	free(stackA);
    free(stackB);
	return (0);
}