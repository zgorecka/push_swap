#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}		t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list *alst, t_list *new);
int	ft_isdigit(int c);
int	ft_atoi(char *str);


#endif