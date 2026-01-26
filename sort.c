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

t_node *min_node(t_stack *stack)
{
    t_node *temp;
    t_node *max;

    temp = stack->top;
    max = stack->top;
    while (temp)
    {
        if(temp->content < max->content)
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
            c_a->target_node = max_node(stackB); 
        c_a = c_a->next;
    }
}
void set_target_nodes_b(t_stack *stackA, t_stack *stackB) //closest bigger
{
    t_node *c_a;
    t_node *c_b;

    if (!stackA || !stackA->top || !stackB || !stackB->top)
        return;

    c_b = stackB->top;
    while (c_b)
    {
        c_b->target_node = NULL;
        c_a = stackA->top;
        while(c_a)
        {
            if (c_b->target_node == NULL && c_b->content < c_a->content)
            {
                c_b->target_node = c_a; 
            }
            else if (c_b->content < c_a->content && c_b->target_node->content > c_a->content)
            {
                c_b->target_node = c_a; 
            }
            c_a = c_a->next;
        }
        if (c_b->target_node == NULL)
            c_b->target_node = min_node(stackA);
        c_b = c_b->next;
    }
}

void set_index(t_stack *stack)
{
    t_node *temp;
    int i;
    int median;

    i = 0;
    median = stack->size / 2;
    temp = stack->top;
    while (temp)
    {
        temp->index = i;
        if (i <= median)
            temp->above_median = true;
        else
            temp->above_median = false;
        i++;
        temp = temp->next;
    }
}

void push_cost(t_stack *stackA, t_stack *stackB)
{
    t_node *temp;

    if (!stackB || !stackB->top)
        return;

    temp = stackA->top;
    while(temp)
    {
        if (temp->above_median && temp->target_node->above_median)
            temp->push_cost = temp->index + temp->target_node->index;
        else if (temp->above_median && !temp->target_node->above_median)
            temp->push_cost = temp->index + (stackB->size - temp->target_node->index);
        else if (!temp->above_median && temp->target_node->above_median)
            temp->push_cost = stackA->size - temp->index + temp->target_node->index;
        else
            temp->push_cost = stackA->size - temp->index + stackB->size - temp->target_node->index;
        temp = temp->next;
    }
}

t_node *find_cheapest(t_stack *stackA)
{
    t_node *res;
    t_node *temp;

    res = stackA->top;
    temp = stackA->top;
    while(temp)
    {
        if (temp->push_cost == 0)
            return temp;
        else if (temp->push_cost < res->push_cost)
            res = temp;
        temp = temp->next;
    }
    return (res);
}

void move_a_to_b(t_stack *stackA, t_stack *stackB)
{
    t_node *cheapest;

    cheapest = find_cheapest(stackA);
    
    if (cheapest->above_median)
        while (stackA->top->content != cheapest->content)
            ra(stackA);
    else if (!cheapest->above_median)
        while(stackA->top->content != cheapest->content)
            rra(stackA);
    if (cheapest->target_node->above_median)
        while(stackB->top->content != cheapest->target_node->content)
            rb(stackB);
    else if (!cheapest->target_node->above_median)
        while(stackB->top->content != cheapest->target_node->content)
            rrb(stackB);
    
    pb(stackA, stackB);
}

void min_to_top(t_stack *stackA)
{
    t_node *temp;

    set_index(stackA);
    temp = min_node(stackA);
    if (temp->above_median)
        while(stackA->top->content != temp->content)
            ra(stackA);
    else
        while(stackA->top->content != temp->content)
            rra(stackA);
}

void sort(t_stack *stackA, t_stack *stackB)
{
    if (stackA->size == 4)
        pb(stackA, stackB);
    else if (stackA->size > 4)
    {
        pb(stackA, stackB);
        pb(stackA, stackB);
    }
    while(stackA->size > 3)
    {
        set_target_nodes(stackA, stackB);
        set_index(stackA);
        set_index(stackB);
        push_cost(stackA, stackB);
        move_a_to_b(stackA, stackB);
    }
    sort3(stackA);
    while (stackB->size > 0)
    {
        set_target_nodes_b(stackA, stackB);
        set_index(stackA);
        set_index(stackB);
        push_cost(stackB, stackA);
        move_a_to_b(stackB, stackA);
        //printf("dupa test \n");
        //print_stack(stackA);
    }
    min_to_top(stackA);
}

