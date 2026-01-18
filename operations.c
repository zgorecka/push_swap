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

void push(t_stack *stackA, t_stack *stackB)
{
    t_node *temp;

    if (stackB->top != NULL)
    {
        temp = stackA->top;
        stackA->top = stackA->top->next;
        temp->next = stackB->top;
        stackB->top = temp;
    }
    else
    {
        stackB->top = stackA->top;
        stackA->top = stackA->top->next;
        stackB->top->next = NULL;
    }
}

void rotate(t_stack *stack)
{
    t_node *first;
    t_node *last;

    first = stack->top;
    stack->top = first->next;
    first->next = NULL;

    last = ft_lstlast(stack->top);
    last->next = first;
}
