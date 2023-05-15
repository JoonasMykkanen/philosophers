/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:56:47 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/15 12:14:37 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	corrected_sleep(int	dur, t_data *data)
{
	int	start;
	int	end;
	int	cur;

	start = get_time(data);
	end = start + dur;
	while (get_time(data) < end)
	{
		usleep(100);
	}
}

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
	if (data->someone_dead == 1)
	{
		if (data->done == 1)
		{
			pthread_mutex_unlock(&data->s_lock);
			return (1);
		}
	}
	pthread_mutex_unlock(&data->s_lock);
	return (0);
}

void	*internal_clock(void *arg)
{
	struct	timeval	current_t;
	int				usec_delta;
	int				usec_start;
	t_data			*data;

	data = (t_data *)arg;
	gettimeofday(&current_t, NULL);
	usec_start = current_t.tv_usec;
	while (1)
	{
		gettimeofday(&current_t, NULL);
		usec_delta = current_t.tv_usec;
		if (usec_delta - usec_start <= 0)
			usec_start = 0;
		else if (usec_delta - usec_start >= 1000)
		{
			pthread_mutex_lock(&data->t_lock);
			data->time += 1;
			pthread_mutex_unlock(&data->t_lock);
			usec_start = usec_delta;
			usec_delta = 0;
		}
		usleep(333);
		if (stop(data) == 1)
			break ;
	}
	return (data);
}
