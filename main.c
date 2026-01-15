#include <stdio.h>
#include "push_swap.h"

t_list *make_stack(int argc, char *argv[])
{
	t_list *temp;
	t_list *prev;
	
	while (argv[argc] != '\0')
	{
		printf("test: %s\n", argv[argc]);
		if (!prev)
			prev = ft_lstnew(ft_atoi(argv[argc-1]));
		temp = ft_lstnew(ft_atoi(argv[argc-2]));
		ft_lstadd_front(prev, temp);
		prev = temp;
		argc--;
	}
	return (prev);
}

int	main(int argc, char *argv[])
{
	int i;
	t_list *temp;
	
	i = 0;
	temp = make_stack(argc, argv);
	while (++i <= argc)
	{
			
			printf("content: %d\n", temp->content);
			temp = temp->next;
	}
	return (0);
}