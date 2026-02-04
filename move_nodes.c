/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgorecka <zgorecka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:25:56 by zgorecka          #+#    #+#             */
/*   Updated: 2026/02/04 20:36:19 by zgorecka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b_helper(t_stack *stackA, t_stack *stackB)
{
	t_node	*cheapest;
	int		a_val;
	int		b_val;

	cheapest = find_cheapest(stackA);
	a_val = cheapest->content;
	b_val = cheapest->target_node->content;
	if (cheapest->above_median && cheapest->target_node->above_median)
		while (stackA->top->content != a_val && stackB->top->content != b_val)
			rr(stackA, stackB);
	else if (!cheapest->above_median && !cheapest->target_node->above_median)
		while (stackA->top->content != a_val && stackB->top->content != b_val)
			rrr(stackA, stackB);
}

void	move_a_to_b(t_stack *stackA, t_stack *stackB)
{
	t_node	*cheapest;
	int		a_val;
	int		b_val;

	cheapest = find_cheapest(stackA);
	a_val = cheapest->content;
	b_val = cheapest->target_node->content;
	move_a_to_b_helper(stackA, stackB);
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

void	move_b_to_a_helper(t_stack *stackA, t_stack *stackB)
{
	t_node	*cheapest;
	int		a_val;
	int		b_val;

	cheapest = find_cheapest(stackB);
	a_val = cheapest->target_node->content;
	b_val = cheapest->content;
	if (cheapest->above_median && cheapest->target_node->above_median)
		while (stackB->top->content != b_val && stackA->top->content != a_val)
			rr(stackA, stackB);
	else if (!cheapest->above_median && !cheapest->target_node->above_median)
		while (stackB->top->content != b_val && stackA->top->content != a_val)
			rrr(stackA, stackB);
}

void	move_b_to_a(t_stack *stackA, t_stack *stackB)
{
	t_node	*cheapest;
	int		a_val;
	int		b_val;

	cheapest = find_cheapest(stackB);
	move_b_to_a_helper(stackA, stackB);
	a_val = cheapest->target_node->content;
	b_val = cheapest->content;
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
