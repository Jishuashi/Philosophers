/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:36:25 by hchartie          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/03/31 11:02:02 by hchartie         ###   ########.fr       */
=======
/*   Updated: 2026/03/24 19:34:03 by hchartie         ###   ########.fr       */
>>>>>>> 14d7b34c8f5b1743603952c15c441673c4fed0ae
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
<<<<<<< HEAD
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->meal_lock);
	init_last_meal_time(philo);
	pthread_mutex_unlock(&philo->data->meal_lock);
	while (check_sim(philo->data))
	{
		printf("Hello");
	}
=======
	t_philo	*philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->meal_lock);
	init_last_meal_time(philo);
	pthread_mutex_unlock(&philo->data->meal_lock);
>>>>>>> 14d7b34c8f5b1743603952c15c441673c4fed0ae
	return (NULL);
}
