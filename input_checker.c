#include "push_swap.h"
#include <stdio.h>

int input_checker(int argc, char *argv[])
{
    int i;
	int j;
	
    i = 1;
    if (!argv || argc == 0)
    {
        printf("Error \n");
        return (-1);
    }
        
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]) || ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483647)
			{
				printf("Error \n");
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
    int i = 1;
    int j;

    while (argv[i])
    {
        j = 0;
        if (argv[i][j] == '-')
            j++;
        if (!argv[i][j])
        {
            printf("Error\n");
            return (-1);
        }
        while (argv[i][j])
        {
            if (!ft_isdigit(argv[i][j]))
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
