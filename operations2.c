#include "push_swap.h"
#include <stdlib.h>

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

void pa(t_stack *stackA, t_stack *stackB)
{
    push(stackB, stackA);
    write(1, "pa\n", 3);
}

void pb(t_stack *stackA, t_stack *stackB)
{
    push(stackA, stackB);
    write(1, "pb\n", 3);
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

void rra(t_stack *stackA)
{
    reverse_rotate(stackA);
    write(1, "rra\n", 3);
}

void rrb(t_stack *stackB)
{
    reverse_rotate(stackB);
    write(1, "rrb\n", 3);
}

void rrr(t_stack *stackA, t_stack *stackB)
{
    reverse_rotate(stackA);
    reverse_rotate(stackB);
    write(1, "rrr\n", 3);
}