#include "push_swap.h"
#include <stdlib.h>

t_node *build_stack_from_array(t_stack *stackA, int count, char **arr)
{
    t_node *temp;
    t_node *prev;

    stackA->size = count;
    stackA->bottom = ft_lstnew(ft_atoi(arr[count - 1]), count - 1);
    prev = stackA->bottom;
    while (count > 1)
    {
        temp = ft_lstnew(ft_atoi(arr[count - 2]), count - 2);
        ft_lstadd_front(&prev, temp);
        prev = temp;
        count--;
    }
    stackA->top = prev;
    return (prev);
}

int count_split_args(char **argv_split)
{
    int i;

    i = 0;
    while (argv_split && argv_split[i])
        i++;
    return (i);
}

int parse_and_build_stack(t_stack *stackA, int argc, char *argv[])
{
    char **argv_split;
    int count;

    if (argc == 2)
    {
        argv_split = ft_split(argv[1], ' ');
        count = count_split_args(argv_split);
        if (input_checker(count, argv_split) == -1)
        {
            error(argv_split, count);
            return (-1);
        }
        build_stack_from_array(stackA, count, argv_split);
        error(argv_split, count);
        return (0);
    }
    if (input_checker(argc - 1, &argv[1]) == -1)
        return (-1);
    build_stack_from_array(stackA, argc - 1, &argv[1]);
    return (0);
}

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

int handle_small_sorts(t_stack *stackA)
{
    if (stackA->size == 2 && is_sorted(stackA) == -1)
    {
        sa(stackA);
        return (1);
    }
    if (stackA->size == 3 && is_sorted(stackA) == -1)
    {
        sort3(stackA);
        return (1);
    }
    return (0);
}

void free_stack_nodes(t_stack *stack)
{
    t_node *cur;
    t_node *next;

    if (!stack)
        return;
    cur = stack->top;
    while (cur)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
}

int init_stacks(t_stack **stackA, t_stack **stackB)
{
    *stackA = (t_stack *)malloc(sizeof(t_stack));
    *stackB = (t_stack *)malloc(sizeof(t_stack));
    if (!(*stackA) || !(*stackB))
        return (-1);
    (*stackA)->top = NULL;
    (*stackA)->bottom = NULL;
    (*stackA)->size = 0;
    (*stackB)->top = NULL;
    (*stackB)->bottom = NULL;
    (*stackB)->size = 0;
    return (0);
}

int main(int argc, char *argv[])
{
    t_stack *stackA;
    t_stack *stackB;

    if (argc < 2)
        return (0);
    if (init_stacks(&stackA, &stackB) == -1)
        return (0);
    if (parse_and_build_stack(stackA, argc, argv) == -1)
        return (0);
    if (is_sorted(stackA) == 1)
        return (0);
    if (handle_small_sorts(stackA) == 1)
        return (0);
    sort(stackA, stackB);
    free_stack_nodes(stackA);
    free_stack_nodes(stackB);
    free(stackA);
    free(stackB);
    return (0);
}
