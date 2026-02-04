/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgorecka <zgorecka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:43:06 by zgorecka          #+#    #+#             */
/*   Updated: 2026/02/04 20:14:17 by zgorecka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

int	err(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

int	input_checker(int argc, char **argv)
{
	long	a;
	int		i;
	int		j;

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

int	is_args_num(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
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
	}
	return (0);
}
