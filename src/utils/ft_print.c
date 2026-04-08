/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 12:49:36 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/31 13:45:35 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print(t_data *data, int id, char name)
{
	pthread_mutex_lock(&data->print_lock);
	if (name == 'd' && check_sim(data))
	{
		printf("%lld %d died\n", get_elapsed_time(data), id);
		pthread_mutex_lock(&data->dead_lock);
		data->sim_sp = 1;
		pthread_mutex_unlock(&data->dead_lock);
	}
	else if (check_sim(data))
	{
		if (name == 'e')
			printf("%lld %d is eating\n", get_elapsed_time(data), id);
		if (name == 's')
			printf("%lld %d is sleeping\n", get_elapsed_time(data), id);
		if (name == 'f')
			printf("%lld %d has taken a fork\n", get_elapsed_time(data), id);
		if (name == 't')
			printf("%lld %d is thinking\n", get_elapsed_time(data), id);
	}
	pthread_mutex_unlock(&data->print_lock);
}
