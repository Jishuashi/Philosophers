/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 17:37:23 by hchartie          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/03/31 10:49:26 by hchartie         ###   ########.fr       */
=======
/*   Updated: 2026/03/24 19:24:17 by hchartie         ###   ########.fr       */
>>>>>>> 14d7b34c8f5b1743603952c15c441673c4fed0ae
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;
int			ft_atoi(const char *str);
void		print_err(char *str);
long long	get_ms_time(long sec, long micro);
void		ft_init_mutex(t_data *data);
void		ft_clean(t_data *data);
<<<<<<< HEAD
long long	get_elapsed_time(t_data *data);
=======
long long	get_elapsed_time(t_data data);
>>>>>>> 14d7b34c8f5b1743603952c15c441673c4fed0ae
void		init_last_meal_time(t_philo *philo);

#endif