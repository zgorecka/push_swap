/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgorecka <zgorecka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:42:42 by zgorecka          #+#    #+#             */
/*   Updated: 2026/02/04 18:42:43 by zgorecka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	pa(t_stack *stackA, t_stack *stackB)
{
	push(stackB, stackA);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stackA, t_stack *stackB)
{
	push(stackA, stackB);
	write(1, "pb\n", 3);
}

void	push(t_stack *stackA, t_stack *stackB)
{
	t_node	*temp;

	if (stackB->top != NULL)
	{
		temp = stackA->top;
		stackA->top = stackA->top->next;
		if (temp->next != NULL)
			stackA->top->prev = NULL;
		temp->next = stackB->top;
		temp->next->prev = temp;
		stackB->top = temp;
	}
	else
	{
		stackB->top = stackA->top;
		stackB->bottom = stackA->top;
		stackA->top = stackA->top->next;
		stackA->top->prev = NULL;
		stackB->top->next = NULL;
	}
	stackA->size = stackA->size - 1;
	stackB->size = stackB->size + 1;
}
