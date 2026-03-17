/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:53:41 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/17 16:54:11 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static void	check_value(int ac, char *av[]);

void	check_arg(int ac, char *av[])
{
	if (ac < 5)
	{
		print_err("Not Enough Arguments\n");
		exit(1);
	}
	else if (ac > 6)
	{
		print_err("More than 6 args\n");
		exit(1);
	}
	check_value(ac, av);
}

static void	check_value(int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-')
			{
				print_err("Arguments must be positive int\n");
				exit(1);
			}
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
			{
				print_err("Arguments must be int\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}
