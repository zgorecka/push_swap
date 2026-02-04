#include "push_swap.h"
#include <stdio.h>

int is_sorted(t_stack *stackA)
{
    t_node *prev;
    t_node *temp;

    if (!stackA || !stackA->top)
        return (-1);
    prev = stackA->top;
    temp = stackA->top->next;
    while (temp)
    {
        if (prev->content >= temp->content)
            return (-1);
        prev = temp;
        temp = temp->next;
    }
    return (1);
}

int prep_stack(t_stack *stackA, int argc, char *argv[])
{
    int i;
    t_node *temp;
    char **argv_split;

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
    return (1);
}

int sort_2_3(t_stack *stackA, t_stack *stackB)
{
    t_node *temp;
    t_node *temp2;

    if (stackA->size == 2 && is_sorted(stackA) == -1)
    {
        sa(stackA);
        return (0);
    if (handle_small_sorts(stackA) == 1)
        return (0);
    sort(stackA, stackB);
    temp = stackA->top;
    while(temp != NULL)
    {
        temp2 = temp->next;
        free(temp);
        temp = temp2;
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

    stackA = malloc(sizeof(t_stack));
    stackB = malloc(sizeof(t_stack));
    stackB->size = 0;
    i = 0;
    if (argc < 2)
        return (0);
    if (prep_stack(stackA, argc, argv) == 0)
        return (0);
	if (is_sorted(stackA) == 0)
		return (0);
    if (sort_2_3(stackA, stackB) == 0)
        return (0);
    free(stackA);
    free(stackB);
    return (0);
}
