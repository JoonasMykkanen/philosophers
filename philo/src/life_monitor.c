/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:07:12 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/06/08 23:29:12 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	checkup(t_philo *philo, int time)
{
	if (time - philo->last_meal > philo->time_to_die)
		return (1);
	return (0);
}

void	*monitor(void *arg)
{
	t_data *data;
	int		time;
	int		idx;

	idx = -1;
	data = (t_data *)arg;
	while (++idx < data->philo_count)
	{
		time = get_time(data);
		if (checkup(&data->philos[idx], time) == 1)
			break ;
		usleep(8);
	}
	pthread_mutex_lock(&data->d_lock);
	data->someone_dead = 1;
	pthread_mutex_unlock(&data->d_lock);
	pthread_mutex_lock(&data->s_lock);
	data->done = 1;
	pthread_mutex_unlock(&data->s_lock);
}
