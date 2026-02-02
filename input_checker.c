#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

int  err(void)
{
    write(2, "Error\n", 6);
    return (-1);
}

int input_checker(int argc, char **argv)
{
    int i, j;
    long a;

    if (!argv || argc <= 0 || is_args_num(argv) == -1)
        return (-1);
    i = 0;
    while (i < argc)
    {
        a = ft_atoi(argv[i]);
        if (a < INT_MIN || a > INT_MAX)
            return (err());
        j = i + 1;
        while (j < argc)
            if (a == ft_atoi(argv[j++]))
                return (err());
        i++;
    }
    return (0);
}


int is_args_num(char *argv[])
{
    int i = 0;
    int j;

    while (argv[i])
    {
        j = 0;
        if (argv[i][j] == '-' || argv[i][j] == '+')
            j++;
        if (!argv[i][j])
        {
            write(2, "Error\n", 6);
            return (-1);
        }
        while (argv[i][j])
        {
            if (!ft_isdigit(argv[i][j]))
            {
                write(2, "Error\n", 6);
                return (-1);
            }
            j++;
        }
        i++;
    }
    return (0);
}
