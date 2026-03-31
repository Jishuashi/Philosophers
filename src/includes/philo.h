/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:32:38 by hchartie          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/03/27 04:25:48 by hchartie         ###   ########.fr       */
=======
/*   Updated: 2026/03/24 19:25:05 by hchartie         ###   ########.fr       */
>>>>>>> 14d7b34c8f5b1743603952c15c441673c4fed0ae
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

typedef struct s_philo	t_philo;

typedef struct s_data
{
	struct timeval		st_time;
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_of_times_each_philo_must_eat;
	int					sim_sp;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		dead_lock;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		*forks;
	t_philo				*philos;
}	t_data;

typedef struct s_philo
{
	t_data			*data;
	int				id;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	long long		last_meal;
}	t_philo;

void	check_arg(int ac, char *av[]);
void	int_data(char *av[], t_data *data);
void	*routine(void *arg);
<<<<<<< HEAD
int		check_sim(t_data *data);
=======
>>>>>>> 14d7b34c8f5b1743603952c15c441673c4fed0ae

#endif