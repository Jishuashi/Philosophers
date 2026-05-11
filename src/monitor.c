/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:51:33 by hchartie          #+#    #+#             */
/*   Updated: 2026/05/11 13:06:06 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static int	check_mon(t_data *data, int idx);

void	monitor(t_data *data)
{
	int		i;
	int		finished_eating;
	t_philo	current;

	while (check_sim(data))
	{
		i = 0;
		finished_eating = 0;
		while (i < data->nb_philo)
		{
			pthread_mutex_lock(&data->meal_lock);
			current = data->philos[i];
			pthread_mutex_unlock(&data->meal_lock);
			if (data->nb_must_eat != -1
				&& current.nb_meal >= data->nb_must_eat)
				finished_eating++;
			else if (check_mon(data, i))
			{
				ft_print(data, current.id, 'd');
				return ;
			}
			i++;
		}
		if (data->nb_must_eat != -1 && finished_eating == data->nb_philo)
		{
			pthread_mutex_lock(&data->dead_lock);
			data->sim_sp = 1;
			pthread_mutex_unlock(&data->dead_lock);
			return ;
		}
		usleep(1000);
	}
}

static int	check_mon(t_data *data, int idx)
{
	struct timeval		current;
	long long			lastmeal;

	gettimeofday(&current, 0);
	pthread_mutex_lock(&data->meal_lock);
	lastmeal = data->philos[idx].last_meal;
	pthread_mutex_unlock(&data->meal_lock);
	if (get_ms_time(current.tv_sec, current.tv_usec)
		- lastmeal > data->time_to_die)
		return (1);
	return (0);
}
