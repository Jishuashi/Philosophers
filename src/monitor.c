/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:51:33 by hchartie          #+#    #+#             */
/*   Updated: 2026/05/12 14:46:06 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static int	check_mon(t_data *data, int idx);
static void	stop_sim(t_data *data);
static int	check_nb_eat(t_data *data);
static int	check_philo_status(t_data *data);

static void	stop_sim(t_data *data)
{
	pthread_mutex_lock(&data->dead_lock);
	data->sim_sp = 1;
	pthread_mutex_unlock(&data->dead_lock);
}

static int	check_nb_eat(t_data *data)
{
	int		i;
	int		count;
	t_philo	current;

	i = 0;
	count = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_lock(&data->meal_lock);
		current = data->philos[i];
		pthread_mutex_unlock(&data->meal_lock);
		if (current.nb_meal >= data->nb_must_eat)
			count++;
		i++;
	}
	return (count);
}

static int	check_philo_status(t_data *data)
{
	int		i;
	t_philo	current;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_lock(&data->meal_lock);
		current = data->philos[i];
		pthread_mutex_unlock(&data->meal_lock);
		if (check_mon(data, i))
		{
			ft_print(data, current.id, 'd');
			return (1);
		}
		i++;
	}
	return (0);
}

void	monitor(t_data *data)
{
	while (check_sim(data))
	{
		if (check_philo_status(data))
		{
			stop_sim(data);
			return ;
		}
		if (data->nb_must_eat != -1
			&& check_nb_eat(data) == data->nb_philo)
		{
			stop_sim(data);
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
