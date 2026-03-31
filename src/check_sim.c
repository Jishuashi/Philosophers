/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 04:14:26 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/27 04:31:32 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	check_sim(t_data *data)
{
	int	check;

	pthread_mutex_lock(&data->dead_lock);
	check = data->sim_sp;
	pthread_mutex_unlock(&data->dead_lock);
	if (check == 1)
		return (0);
	return (1);
}
