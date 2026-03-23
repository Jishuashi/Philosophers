/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 05:07:05 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/23 05:21:03 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}
