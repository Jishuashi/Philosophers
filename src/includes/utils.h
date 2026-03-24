/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchartie <hchartie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 17:37:23 by hchartie          #+#    #+#             */
/*   Updated: 2026/03/24 16:53:49 by hchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data	t_data;
int			ft_atoi(const char *str);
void		print_err(char *str);
long long	get_ms_time(long sec, long micro);
void		ft_init_mutex(t_data *data);
void		ft_clean(t_data *data);
long long	get_elapsed_time(t_data data);

#endif