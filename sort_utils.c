/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgorecka <zgorecka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:27:13 by zgorecka          #+#    #+#             */
/*   Updated: 2026/02/04 20:35:49 by zgorecka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_nodes(t_stack *stackA, t_stack *stackB)
{
	t_node	*c_a;
	t_node	*c_b;

	c_a = stackA->top;
	while (c_a)
	{
		c_a->target_node = NULL;
		c_b = stackB->top;
		while (c_b)
		{
			if (c_a->target_node == NULL && c_a->content > c_b->content)
			{
				c_a->target_node = c_b;
			}
			else if (c_a->content > c_b->content
				&& c_a->target_node->content < c_b->content)
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

void	set_target_nodes_b(t_stack *stackA, t_stack *stackB)
{
	t_node	*c_a;
	t_node	*c_b;

	if (!stackA || !stackA->top || !stackB || !stackB->top)
		return ;
	c_b = stackB->top;
	while (c_b)
	{
		c_b->target_node = NULL;
		c_a = stackA->top;
		while (c_a)
		{
			if (c_b->target_node == NULL && c_b->content < c_a->content)
				c_b->target_node = c_a;
			else if (c_b->content < c_a->content
				&& c_b->target_node->content > c_a->content)
				c_b->target_node = c_a;
			c_a = c_a->next;
		}
		if (c_b->target_node == NULL)
			c_b->target_node = min_node(stackA);
		c_b = c_b->next;
	}
}

void	set_index(t_stack *stack)
{
	t_node	*temp;
	int		i;
	int		median;

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

t_node	*find_cheapest(t_stack *stackA)
{
	t_node	*res;
	t_node	*temp;

	res = stackA->top;
	temp = stackA->top;
	while (temp)
	{
		if (temp->push_cost == 0)
			return (temp);
		else if (temp->push_cost < res->push_cost)
			res = temp;
		temp = temp->next;
	}
	return (res);
}

void	min_to_top(t_stack *stackA)
{
	t_node	*temp;

	set_index(stackA);
	temp = min_node(stackA);
	if (temp->above_median)
		while (stackA->top->content != temp->content)
			ra(stackA);
	else
		while (stackA->top->content != temp->content)
			rra(stackA);
}
