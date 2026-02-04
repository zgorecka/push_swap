/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgorecka <zgorecka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:42:39 by zgorecka          #+#    #+#             */
/*   Updated: 2026/02/04 18:49:38 by zgorecka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	last = ft_lstlast(stack->top);
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = stack->top;
	stack->top->prev = last;
	stack->top = last;
	stack->bottom = second_last;
}

void	rra(t_stack *stackA)
{
	reverse_rotate(stackA);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stackB)
{
	reverse_rotate(stackB);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stackA, t_stack *stackB)
{
	reverse_rotate(stackA);
	reverse_rotate(stackB);
	write(1, "rrr\n", 4);
}
