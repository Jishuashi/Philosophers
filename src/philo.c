/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:36:25 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/23 03:24:53 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int ac, char *av[])
{
	t_data	data;

	check_arg(ac, av);
	int_data(av, &data);
	printf("%zu\n", data.st_time.tv_sec);
}
