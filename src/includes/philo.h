/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:32:38 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/23 06:46:25 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "utils.h"
# include <sys/time.h>
# include <pthread.h>

typedef	struct s_philo t_philo;

typedef struct s_data
{
	struct timeval		st_time;
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_of_times_each_philo_must_eat;
	pthread_mutex_t		*forks;
	t_philo				*philos;
}	t_data;

typedef	struct s_philo
{
	t_data			*data;
	int				id;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;


void	check_arg(int ac, char *av[]);
void	int_data(char *av[], t_data *data);

#endif