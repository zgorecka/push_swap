#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int			content;
	struct s_node	*next;
    int             index;
} t_node;

typedef struct s_stack
{
    struct s_node *top;
    int size;
} t_stack;

t_node	*ft_lstnew(int content, int index);
void	ft_lstadd_front(t_node *alst, t_node *new);
int	ft_isdigit(int c);
int	ft_atoi(char *str);
void sa(t_stack *stackA);
void	ft_lstdelone(t_node *lst);
void push(t_stack *stackA, t_stack *stackB);
void	ft_lstadd_back(t_node *lst, t_node *new);
void rotate(t_stack *stack);
t_node	*ft_lstlast(t_node *lst);


#endif