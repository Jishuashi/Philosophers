/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 03:38:47 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/24 16:24:20 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_ms_time(long sec, long micro)
{
	return ((sec * 1000) + (micro / 1000));
}

long long get_elapsed_time(t_data data)
{
	struct timeval end;
	
	gettimeofday(&end, 0);
	return(get_ms_time(data.st_time.tv_sec, data.st_time.tv_sec)
	- get_ms_time(end.tv_sec, end.tv_usec));
}