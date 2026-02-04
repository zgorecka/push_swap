/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgorecka <zgorecka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:24:43 by zgorecka          #+#    #+#             */
/*   Updated: 2026/02/04 21:03:52 by zgorecka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_rotation_cost(t_node *node, int stack_size)
{
	if (node->above_median)
		return (node->index);
	else
		return (stack_size - node->index);
}

int	calculate_combined_cost(int cost_a, int cost_b, bool both_above,
		bool both_below)
{
	if (both_above || both_below)
	{
		if (cost_a > cost_b)
			return (cost_a);
		else
			return (cost_b);
	}
	else
		return (cost_a + cost_b);
}

void	push_cost(t_stack *stackA, t_stack *stackB)
{
	t_node	*temp;
	int		cost_a;
	int		cost_b;
	bool	both_above;
	bool	both_below;

	temp = stackA->top;
	while (temp)
	{
		cost_a = calculate_rotation_cost(temp, stackA->size);
		cost_b = calculate_rotation_cost(temp->target_node, stackB->size);
		both_above = temp->above_median && temp->target_node->above_median;
		both_below = !temp->above_median && !temp->target_node->above_median;
		temp->push_cost = calculate_combined_cost(cost_a, cost_b, both_above,
				both_below);
		temp = temp->next;
	}
}
