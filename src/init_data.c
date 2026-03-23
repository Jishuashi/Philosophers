/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 17:10:52 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/23 03:17:04 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

void	int_data(char *av[], t_data *data)
{
	gettimeofday(&data->st_time, 0);
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->nb_of_times_each_philo_must_eat = ft_atoi(av[5]);
	else
		data->nb_of_times_each_philo_must_eat = -1;
}
