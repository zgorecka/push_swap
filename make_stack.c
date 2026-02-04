#include "push_swap.h"

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