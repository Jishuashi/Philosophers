/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:36:25 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/23 03:53:26 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int ac, char *av[])
{
	struct timeval	tv;
	t_data			data;

	check_arg(ac, av);
	int_data(av, &data);
	usleep(10000);
	gettimeofday(&tv, NULL);
	printf("%lld\n", (get_ms_time(tv.tv_sec, tv.tv_usec)
	- get_ms_time(data.st_time.tv_sec, data.st_time.tv_usec)));
}
