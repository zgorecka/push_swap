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
        stackA->top->prev = NULL;
        temp->next = stackB->top;
        temp->next->prev = temp;
        stackB->top = temp;
    }
    else
    {
        stackB->top = stackA->top;
        stackA->top = stackA->top->next;
        stackA->top->prev = NULL;
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

void reverse_rotate(t_stack *stack)
{
    //t_node *first;
    t_node *last;
    t_node *temp;

    last = ft_lstlast(stack->top);
    last->next = stack->top;
    stack->top = last;
    temp = stack->top;
    while (temp->next != stack->top)
        temp = temp->next;
    temp->next = NULL;
    
}
