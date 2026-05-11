/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:36:25 by hchartie          #+#    #+#             */
/*   Updated: 2026/05/11 13:06:06 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

static void	take_fork(t_philo *philo);
static void	drop_fork(t_philo *philo);
static void	update_meal(t_philo *philo);

int	main(int ac, char *av[])
{
	int		i;
	t_data	data;

	check_arg(ac, av);
	int_data(av, &data);
	i = 0;
	while (i < (data.nb_philo))
	{
		pthread_create(&data.philos[i].id_t, NULL, routine, &data.philos[i]);
		i++;
	}
	monitor(&data);
	i = 0;
	while (i < (data.nb_philo))
	{
		pthread_join(data.philos[i].id_t, NULL);
		i++;
	}
	ft_clean(&data);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 1)
		usleep(1000);
	while (check_sim(philo->data))
	{
		take_fork(philo);
		if (philo->data->nb_philo == 1)
			break ;
		update_meal(philo);
		ft_print(philo->data, philo->id, 'e');
		ft_usleep(philo->data->time_to_eat, philo->data);
		drop_fork(philo);
		if (philo->data->nb_must_eat != -1 
			&& philo->nb_meal >= philo->data->nb_must_eat)
			break ;
		ft_print(philo->data, philo->id, 's');
		ft_usleep(philo->data->time_to_sleep, philo->data);
		ft_print(philo->data, philo->id, 't');
	}
	return (NULL);
}

static void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	ft_print(philo->data, philo->id, 'f');
	if (philo->data->nb_philo == 1)
	{
		ft_usleep(philo->data->time_to_die + 10, philo->data);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	ft_print(philo->data, philo->id, 'f');
}

static void	drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

static void	update_meal(t_philo *philo)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->last_meal = get_ms_time(current.tv_sec, current.tv_usec);
	philo->nb_meal++;
	pthread_mutex_unlock(&philo->data->meal_lock);
}
