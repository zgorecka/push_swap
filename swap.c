#include "push_swap.h"
#include <stdio.h>

void swap(t_stack *stack)
{
    t_node *first;
    t_node *second;
    int tmp_content;
    int tmp_index;

    first = stack->top;
    second = stack->top->next;

    tmp_content = first->content;
    tmp_index = first->index;
    first->content = second->content;
    first->index = second->index;
    second->content = tmp_content;
    second->index = tmp_index;
}
void sa(t_stack *stackA)
{
    swap(stackA);
    write(1, "sa\n", 3);
}

void sb(t_stack *stackB)
{
    swap(stackB);
    write(1, "sb\n", 3);
}

void ss(t_stack *stackA, t_stack *stackB)
{
    swap(stackA);
    swap(stackB);
    write(1, "ss\n", 3);
}

