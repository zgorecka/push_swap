/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgorecka <zgorecka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:42:46 by zgorecka          #+#    #+#             */
/*   Updated: 2026/02/04 21:03:24 by zgorecka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
	int				index;
	bool			cheapest;
	bool			above_median;
	int				push_cost;
	struct s_node	*target_node;
}					t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
	int				size;
}					t_stack;

t_node				*ft_lstnew(int content, int index);
void				ft_lstadd_front(t_node **alst, t_node *new);
int					ft_isdigit(int c);
long				ft_atoi(char *str);
void				ft_lstdelone(t_node *lst);
void				push(t_stack *stackA, t_stack *stackB);
void				ft_lstadd_back(t_node **lst, t_node *new);
void				rotate(t_stack *stack);
t_node				*ft_lstlast(t_node *lst);
int					input_checker(int argc, char *argv[]);
int					is_args_num(char *argv[]);
void				reverse_rotate(t_stack *stack);
void				swap(t_stack *stack);
void				sa(t_stack *StackA);
void				sb(t_stack *StackB);
void				ss(t_stack *stackA, t_stack *stackB);
void				pa(t_stack *stackA, t_stack *stackB);
void				pb(t_stack *stackA, t_stack *stackB);
void				ra(t_stack *stackA);
void				rb(t_stack *stackB);
void				rr(t_stack *stackA, t_stack *stackB);
void				rra(t_stack *stackA);
void				rrb(t_stack *stackB);
void				rrr(t_stack *stackA, t_stack *stackB);
void				sort3(t_stack *stackA);
void				sort(t_stack *stackA, t_stack *stackB);
void				print_stack(t_stack *stackA);
char				**ft_split(char *s, char c);
char				**error(char **res, int j);
int					ft_atoi_safe(const char *str, int *out);
void				set_target_nodes(t_stack *stackA, t_stack *stackB);
void				set_target_nodes_b(t_stack *stackA, t_stack *stackB);
void				set_index(t_stack *stack);
t_node				*find_cheapest(t_stack *stackA);
void				min_to_top(t_stack *stackA);
void				move_a_to_b_helper(t_stack *stackA, t_stack *stackB);
void				move_a_to_b(t_stack *stackA, t_stack *stackB);
void				move_b_to_a_helper(t_stack *stackA, t_stack *stackB);
void				move_b_to_a(t_stack *stackA, t_stack *stackB);
void				push_cost(t_stack *stackA, t_stack *stackB);
t_node				*build_stack_from_array(t_stack *stackA, int count,
						char **arr);
int					parse_and_build_stack(t_stack *stackA, int argc,
						char *argv[]);
int					init_stacks(t_stack **stackA, t_stack **stackB);
void				free_stack_nodes(t_stack *stack);
int					calculate_rotation_cost(t_node *node, int stack_size);
int					calculate_combined_cost(int cost_a, int cost_b,
						bool both_above, bool both_below);
void				push_cost(t_stack *stackA, t_stack *stackB);
t_node				*max_node(t_stack *stack);
t_node				*min_node(t_stack *stack);

#endif