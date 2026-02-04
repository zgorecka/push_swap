/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgorecka <zgorecka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:42:54 by zgorecka          #+#    #+#             */
/*   Updated: 2026/02/04 21:47:51 by zgorecka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int	is_sorted(t_stack *stack_a)
{
	t_node	*prev;
	t_node	*temp;

	if (!stack_a || !stack_a->top)
		return (-1);
	prev = stack_a->top;
	temp = stack_a->top->next;
	while (temp)
	{
		if (prev->content >= temp->content)
			return (-1);
		prev = temp;
		temp = temp->next;
	}
	return (1);
}

int	handle_small_sorts(t_stack *stack_a)
{
	if (stack_a->size == 2 && is_sorted(stack_a) == -1)
	{
		sa(stack_a);
		return (1);
	}
	if (stack_a->size == 3 && is_sorted(stack_a) == -1)
	{
		sort3(stack_a);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (init_stacks(&stack_a, &stack_b) == -1)
		return (0);
	if (parse_and_build_stack(stack_a, argc, argv) == -1)
		return (0);
	if (is_sorted(stack_a) == 1)
		return (0);
	if (handle_small_sorts(stack_a) == 1)
		return (0);
	sort(stack_a, stack_b);
	free_stack_nodes(stack_a);
	free_stack_nodes(stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
