/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:32:38 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/23 03:27:19 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "utils.h"
# include <sys/time.h>

typedef struct s_data
{
	struct timeval		st_time;
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_of_times_each_philo_must_eat;
}	t_data;

void	check_arg(int ac, char *av[]);
void	int_data(char *av[], t_data *data);

#endif