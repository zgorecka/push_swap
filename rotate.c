#include "push_swap.h"

void rotate(t_stack *stack)
{
    t_node *first;
    t_node *last;

    first = stack->top;
    stack->top = first->next;
    stack->top->prev = NULL;
    first->next = NULL;

    last = ft_lstlast(stack->top);
    last->next = first;
    first->prev = last;
    stack->bottom = first;
}

void ra(t_stack *stackA)
{
    rotate(stackA);
    write(1, "ra\n", 3);
}

void rb(t_stack *stackB)
{
    rotate(stackB);
    write(1, "rb\n", 3);
}

void rr(t_stack *stackA, t_stack *stackB)
{
    rotate(stackA);
    rotate(stackB);
    write(1, "rr\n", 3);
}