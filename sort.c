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
        rra(stackA);
        sa(stackA);
    }
    else if (a > b && b < c && a < c)
        sa(stackA);
    else if(a < b && b > c && a > c)
        rra(stackA);
    
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
void set_target_nodes_b(t_stack *stackA, t_stack *stackB)
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
                c_b->target_node = c_a; 
            else if (c_b->content < c_a->content && c_b->target_node->content > c_a->content)
                c_b->target_node = c_a; 
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
    int cost_a;
    int cost_b;

    temp = stackA->top;
    while (temp)
    {
        if (temp->above_median)
            cost_a = temp->index;
        else
            cost_a = stackA->size - temp->index;
        if (temp->target_node->above_median)
            cost_b = temp->target_node->index;
        else
            cost_b = stackB->size - temp->target_node->index;
        if (temp->above_median && temp->target_node->above_median)
            if (cost_a > cost_b)
                temp->push_cost = cost_a;
            else
                temp->push_cost = cost_b;
        else if (!temp->above_median && !temp->target_node->above_median)
            if (cost_a > cost_b)
                temp->push_cost = cost_a;
            else
                temp->push_cost = cost_b;
        else
            temp->push_cost = cost_a + cost_b;
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
    int     a_val;
    int     b_val;

    cheapest = find_cheapest(stackA);
    a_val = cheapest->content;
    b_val = cheapest->target_node->content;
    if (cheapest->above_median && cheapest->target_node->above_median)
        while (stackA->top->content != a_val && stackB->top->content != b_val)
            rr(stackA, stackB);
    else if (!cheapest->above_median && !cheapest->target_node->above_median)
        while (stackA->top->content != a_val && stackB->top->content != b_val)
            rrr(stackA, stackB);
    if (cheapest->above_median)
        while (stackA->top->content != a_val)
            ra(stackA);
    else
        while (stackA->top->content != a_val)
            rra(stackA);
    if (cheapest->target_node->above_median)
        while (stackB->top->content != b_val)
            rb(stackB);
    else
        while (stackB->top->content != b_val)
            rrb(stackB);
    pb(stackA, stackB);
}

void move_b_to_a(t_stack *stackA, t_stack *stackB)
{
    t_node *cheapest;
    int     a_val;
    int     b_val;

    cheapest = find_cheapest(stackB);
    a_val = cheapest->target_node->content;
    b_val = cheapest->content;
    if (cheapest->above_median && cheapest->target_node->above_median)
        while (stackB->top->content != b_val && stackA->top->content != a_val)
            rr(stackA, stackB);
    else if (!cheapest->above_median && !cheapest->target_node->above_median)
        while (stackB->top->content != b_val && stackA->top->content != a_val)
            rrr(stackA, stackB);
    if (cheapest->above_median)
        while (stackB->top->content != b_val)
            rb(stackB);
    else
        while (stackB->top->content != b_val)
            rrb(stackB);
    if (cheapest->target_node->above_median)
        while (stackA->top->content != a_val)
            ra(stackA);
    else
        while (stackA->top->content != a_val)
            rra(stackA);
    pa(stackA, stackB);
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
        move_b_to_a(stackA, stackB);
    }
    min_to_top(stackA);
}

