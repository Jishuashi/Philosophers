/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 03:38:47 by hchartie          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/03/31 10:49:41 by hchartie         ###   ########.fr       */
=======
/*   Updated: 2026/03/24 19:23:53 by hchartie         ###   ########.fr       */
>>>>>>> 14d7b34c8f5b1743603952c15c441673c4fed0ae
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_ms_time(long sec, long micro)
{
	return ((sec * 1000) + (micro / 1000));
}

<<<<<<< HEAD
long long	get_elapsed_time(t_data *data)
=======
long long	get_elapsed_time(t_data data)
>>>>>>> 14d7b34c8f5b1743603952c15c441673c4fed0ae
{
	struct timeval	end;

	gettimeofday(&end, 0);
	return (get_ms_time(end.tv_sec, end.tv_usec)
<<<<<<< HEAD
		- get_ms_time(data->st_time.tv_sec, data->st_time.tv_usec));
=======
		- get_ms_time(data.st_time.tv_sec, data.st_time.tv_usec));
>>>>>>> 14d7b34c8f5b1743603952c15c441673c4fed0ae
}

void	init_last_meal_time(t_philo *philo)
{
	struct timeval	current;

	gettimeofday(&current, 0);
	philo->last_meal = get_ms_time(current.tv_sec, current.tv_usec);
}
