/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:56:47 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/06/09 13:11:34 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	get_time(t_data *data)
{
	int	time;

	pthread_mutex_lock(&data->t_lock);
	time = data->time;
	pthread_mutex_unlock(&data->t_lock);
	return (time);
}

static int	stop(t_data *data)
{
	pthread_mutex_lock(&data->s_lock);
	if (data->done == 1)
	{
		pthread_mutex_unlock(&data->s_lock);
		return (1);
	}
	pthread_mutex_unlock(&data->s_lock);
	return (0);
}

static void	add_time(t_data *data)
{
	pthread_mutex_lock(&data->t_lock);
	data->time += 1;
	pthread_mutex_unlock(&data->t_lock);
}

void	*internal_clock(void *arg)
{
	struct timeval	current_t;
	int				us_delta;
	int				us_start;

	gettimeofday(&current_t, NULL);
	us_start = current_t.tv_usec;
	while (1)
	{
		gettimeofday(&current_t, NULL);
		us_delta = current_t.tv_usec;
		if (us_delta - us_start <= 0)
			us_start = 0;
		else if (us_delta - us_start >= 1000)
		{
			add_time((t_data *)arg);
			us_start = us_delta;
			us_delta = 0;
		}
		usleep(333);
		if (stop((t_data *)arg) == 1)
			break ;
	}
	return ((t_data *)arg);
}
