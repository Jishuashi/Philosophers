/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:36:25 by hchartie          #+#    #+#             */
/*   Updated: 2026/04/08 12:59:56 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static void	take_fork(t_philo *philo);
static void drop_fork(t_philo *philo);
static void update_meal(t_philo *philo);

int	main(int ac, char *av[])
{
	t_data			data;

	check_arg(ac, av);
	int_data(av, &data);
	ft_clean(&data);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->meal_lock);
	init_last_meal_time(philo);
	pthread_mutex_unlock(&philo->data->meal_lock);
	while (check_sim(philo->data))
	{
		take_fork(philo);
		update_meal(philo);
		ft_print(philo->data, philo->id, 'e');
		ft_usleep(philo->data->time_to_eat, philo->data);
		drop_fork(philo);
		ft_print(philo->data, philo->id, 's');
		ft_usleep(philo->data->time_to_sleep, philo->data);
		ft_print(philo->data, philo->id, 't');
	}
	return (NULL);
}

static void take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	ft_print(philo->data, philo->id, 'f');
	if (philo->data->nb_philo == 1)
		ft_usleep(philo->data->time_to_die, philo->data);
	pthread_mutex_lock(philo->r_fork);
	ft_print(philo->data, philo->id, 'f');	
}

static void drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);	
	pthread_mutex_unlock(philo->r_fork);	
}

static void update_meal(t_philo *philo)
{
	struct timeval current;
	
	gettimeofday(&current, NULL);
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->last_meal = get_ms_time(current.tv_sec, current.tv_usec);
	pthread_mutex_unlock(&philo->data->meal_lock);
}
