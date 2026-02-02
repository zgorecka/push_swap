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

t_node	*make_stack_split(t_stack *stackA, int argc, char **argv)
{
    t_node	*temp;
    t_node	*prev;

    stackA->size = argc;
    stackA->bottom = ft_lstnew(ft_atoi(argv[argc - 1]), argc-1);
    prev = stackA->bottom;
    while (argc > 1)
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

    if (!stackA->top)
        return (-1);

    prev = stackA->top;
    temp = stackA->top->next;

    while(temp)
    {
        if (prev->content >= temp->content)
            return (-1);
        prev = temp;
        temp = temp->next;
    }
    return (1);
}
void print_stack(t_stack *stackA)
{
    t_node *temp;
    temp = stackA->top;
    while (temp)
    {
        printf("content A: %d\n", temp->content);
        printf("index A: %d\n", temp->index);
        printf("--------\n");
        temp = temp->next;
    }
}

int	main(int argc, char *argv[])
{
    int i;
    char **argv_split;
    t_node *temp;
    t_node *temp2;
    t_stack *stackA;
    t_stack *stackB;

    stackA = NULL;
    stackB = NULL;
    stackA = malloc(sizeof(t_stack));
    stackB = malloc(sizeof(t_stack));
    stackB->size = 0;


    i = 0;
    if (argc < 2)
    {
        //write(2, "Error\n", 6);
        return (0);
    }
    
    if (argc == 2)
    {
		
        argv_split = ft_split(argv[1], ' ');
		while(argv_split[i])
            i++;
        if (input_checker(i, argv_split) == -1)
        {
            error(argv_split, i);
            return (0);
        }
        temp = make_stack_split(stackA, i, argv_split);
        error(argv_split, i);
    }
    else 
    {
        if (input_checker(argc - 1, &argv[1]) == -1)
            return (0);
        temp = make_stack(stackA, argc, argv);
    }
	//printf("stack size %d\n", stackA->size);
    
	if (is_sorted(stackA) == 1)
		return (0);
    if (stackA->size == 2 && is_sorted(stackA) == -1)
    {
        sa(stackA);
        return (0);
    }
    else if (stackA->size == 3 && is_sorted(stackA) == -1)
    {
        sort3(stackA);
        return (0);
    }
    sort(stackA, stackB);
    
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
