/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:51:33 by hchartie          #+#    #+#             */
/*   Updated: 2026/04/08 11:39:21 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static	int check_mon(t_data *data, int idx);

void	monitor(t_data *data)
{
	int					i;
	
	while (check_sim(data))
	{
		i = 0;
		while (i < data->nb_philo)
		{
			if (check_mon(data, i))
			{
				ft_print(data, data->philos[i].id, 'd');
				break ;
			}
			i++;
		}
		usleep(1000);
	}
}

static	int check_mon(t_data *data, int idx)
{
	struct	timeval		current;
	long long			lastmeal;
	
	gettimeofday(&current, 0);
	pthread_mutex_lock(&data->meal_lock);
	lastmeal = data->philos[idx].last_meal;
	pthread_mutex_unlock(&data->meal_lock);
	if (get_ms_time(current.tv_sec, current.tv_usec)
		- lastmeal > data->time_to_die)
		return	(1);
	return (0);
}
