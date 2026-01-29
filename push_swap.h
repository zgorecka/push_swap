#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdbool.h>


typedef struct s_node
{
	int			content;
	struct s_node	*next;
    struct s_node	*prev;
    int             index;
    bool            cheapest;
    bool            above_median;
    int             push_cost;
    struct s_node   *target_node;
} t_node;

typedef struct s_stack
{
    struct s_node *top;
    struct s_node *bottom;
    int size;
} t_stack;

t_node	*ft_lstnew(int content, int index);
void	ft_lstadd_front(t_node **alst, t_node *new);
int	ft_isdigit(int c);
int	ft_atoi(char *str);
void	ft_lstdelone(t_node *lst);
void push(t_stack *stackA, t_stack *stackB);
void	ft_lstadd_back(t_node **lst, t_node *new);
void rotate(t_stack *stack);
t_node	*ft_lstlast(t_node *lst);
int input_checker(int argc, char *argv[]);
int is_args_num(char *argv[]);
void reverse_rotate(t_stack *stack);
void swap(t_stack *stack);
void sa(t_stack *StackA);
void sb(t_stack *StackB);
void ss(t_stack *stackA, t_stack *stackB);
void pa(t_stack *stackA, t_stack *stackB);
void pb(t_stack *stackA, t_stack *stackB);
void ra(t_stack *stackA);
void rb(t_stack *stackB);
void rr(t_stack *stackA, t_stack *stackB);
void rra(t_stack *stackA);
void rrb(t_stack *stackB);
void rrr(t_stack *stackA, t_stack *stackB);
void sort3(t_stack *stackA);
void sort(t_stack *stackA, t_stack *stackB);
void print_stack(t_stack *stackA);
char	**ft_split(char *s, char c);
char	**error(char **res, int j);

#endif