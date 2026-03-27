/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:36:25 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/24 19:34:03 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

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
	t_philo	*philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->meal_lock);
	init_last_meal_time(philo);
	pthread_mutex_unlock(&philo->data->meal_lock);
	return (NULL);
}
