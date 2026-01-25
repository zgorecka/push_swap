#include "push_swap.h"
#include <stdio.h>

void sort3(t_stack *stackA)
{
    int a = stackA->top->content;
    int b = stackA->top->next->content;
    int c = stackA->top->next->next->content;

    if (a > b && b > c)
    {
        ra(stackA);
        sa(stackA);
    }
    else if (a > b && b < c && a > c)
        ra(stackA);
    else if (a < b && b > c && a < c)
    {
        reverse_rotate(stackA);
        sa(stackA);
    }
    else if (a > b && b < c && a < c)
        sa(stackA);
    else if(a < b && b > c && a > c)
        reverse_rotate(stackA);
    
}
t_node *max_node(t_stack *stack)
{
    t_node *temp;
    t_node *max;

    temp = stack->top;
    max = stack->top;
    while (temp)
    {
        if(temp->content > max->content)
            max = temp; 
        temp = temp->next;
    }
    return (max);
}

void set_target_nodes(t_stack *stackA, t_stack *stackB)
{
    t_node *c_a;
    t_node *c_b;

    c_a = stackA->top;
    while (c_a)
    {
        c_a->target_node = NULL;
        c_b = stackB->top;
        while(c_b)
        {
            if (c_a->target_node == NULL && c_a->content > c_b->content)
            {
                c_a->target_node = c_b; 
            }
            else if (c_a->content > c_b->content && c_a->target_node->content < c_b->content)
            {
                c_a->target_node = c_b; 
            }
            c_b = c_b->next;
        }
        if (c_a->target_node == NULL)
        {
            c_a->target_node = max_node(stackB); 
        }
        c_a = c_a->next;
    }
}

void sort(t_stack *stackA, t_stack *stackB)
{
    if (stackA->size == 4)
        pb(stackA, stackB);
    else if (stackA->size > 4)
    {
        pb(stackA, stackB);
        pb(stackA, stackB);
        pb(stackA, stackB);
    }
    //pb(stackA, stackB);
    //pb(stackA, stackB);
    set_target_nodes(stackA, stackB);


}

