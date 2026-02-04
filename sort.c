/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgorecka <zgorecka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:24:10 by zgorecka          #+#    #+#             */
/*   Updated: 2026/02/04 20:27:59 by zgorecka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort3(t_stack *stackA)
{
	int	a;
	int	b;
	int	c;

	a = stackA->top->content;
	b = stackA->top->next->content;
	c = stackA->top->next->next->content;
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
	else if (a < b && b > c && a > c)
		rra(stackA);
}

t_node	*max_node(t_stack *stack)
{
	t_node	*temp;
	t_node	*max;

	temp = stack->top;
	max = stack->top;
	while (temp)
	{
		if (temp->content > max->content)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

t_node	*min_node(t_stack *stack)
{
	t_node	*temp;
	t_node	*max;

	temp = stack->top;
	max = stack->top;
	while (temp)
	{
		if (temp->content < max->content)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

void	sort(t_stack *stackA, t_stack *stackB)
{
	if (stackA->size == 4)
		pb(stackA, stackB);
	else if (stackA->size > 4)
	{
		pb(stackA, stackB);
		pb(stackA, stackB);
	}
	while (stackA->size > 3)
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
