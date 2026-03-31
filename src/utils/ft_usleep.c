/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 10:20:53 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/31 11:06:52 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/philo.h"

void	ft_usleep(int wait, t_data *data)
{
	struct timeval	current;
	struct timeval	start;

	gettimeofday(&current, NULL);
	gettimeofday(&start, NULL);
	while ((get_ms_time(current.tv_sec, current.tv_usec) 
	- get_ms_time(start.tv_sec, start.tv_usec)) < wait)
	{
		if(!check_sim(data))
			break ;
		usleep(500);
		gettimeofday(&current, NULL);
	}
}
