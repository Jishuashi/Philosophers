/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 17:10:52 by hchartie          #+#    #+#             */
/*   Updated: 2026/05/11 13:09:47 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

static void	init_philo(t_data *data, int id);
static void	check_alloc(t_data *data);

void	int_data(char *av[], t_data *data)
{
	int	i;

	gettimeofday(&data->st_time, 0);
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->sim_sp = 0;
	if (av[5])
		data->nb_must_eat = ft_atoi(av[5]);
	else
		data->nb_must_eat = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->nb_philo);
	check_alloc(data);
	ft_init_mutex(data);
	i = 0;
	while (i < data->nb_philo)
	{
		init_philo(data, i);
		i++;
	}
}

static void	init_philo(t_data *data, int id)
{
	data->philos[(id)].id = (id + 1);
	data->philos[id].r_fork = &data->forks[((id) % data->nb_philo)];
	data->philos[id].l_fork = &data->forks[((id + 1) % data->nb_philo)];
	data->philos[id].data = data;
	data->philos[id].last_meal = get_ms_time(data->st_time.tv_sec,
			data->st_time.tv_usec);
	data->philos[id].nb_meal = 0;
}

static	void	check_alloc(t_data *data)
{
	if (!data->forks || !data->philos)
	{
		free(data->philos);
		print_err("Error: Memory alloction failed");
		exit(1);
	}
	if (!data->philos)
	{
		free(data->forks);
		print_err("Error: Memory alloction failed");
		exit(1);
	}
}
