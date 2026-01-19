#include "push_swap.h"
#include <stdio.h>

int input_checker(int argc, char *argv[])
{
    int i;
	int j;
	
	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				printf("Error\n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int is_args_num(char *argv[])
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (argv[i])
    {
        while(argv[i][j])
        {
            if (ft_isdigit(argv[i][j]) != 0 || argv[i][j] == '-')
                j++;
            else
            {
                printf("Error\n");
			    return (-1);
            }
        }
        i++;
    }
    return (0);
}
