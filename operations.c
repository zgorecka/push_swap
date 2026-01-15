#include "push_swap.h"

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

void push(t_stack *stackA, t_stack *stackB)
{
    t_node *temp;

    if (stackB != NULL)
    {
        temp = stackA->top;
        ft_lstadd_front(stackB->top, temp);
    }
    else
        stackB->top = stackA->top;
    temp = stackA->top->next;
    ft_lstdelone(stackA->top);
    stackA->top = temp;
}