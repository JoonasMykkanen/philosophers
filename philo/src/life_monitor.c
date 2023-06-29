/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:07:12 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/06/29 19:35:43 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	checkup(t_philo *philo, int time)
{
	if (time - philo->last_meal > philo->time_to_die)
	{
		pthread_mutex_lock(&philo->data->d_lock);
		if (philo->data->someone_dead == 1)
		{
			pthread_mutex_unlock(&philo->data->d_lock);
			return (1);
		}
		else
		{
			pthread_mutex_unlock(&philo->data->d_lock);
			return (death(philo));
		}
	}
	return (0);
}

static void	set_simulation_finished(t_data *data)
{
	pthread_mutex_lock(&data->d_lock);
	data->someone_dead = 1;
	pthread_mutex_unlock(&data->d_lock);
	pthread_mutex_lock(&data->s_lock);
	data->done = 1;
	pthread_mutex_unlock(&data->s_lock);
}

static void	reset(int *idx, int *eaten, int	count)
{
	if (*idx >= count)
	{
		*idx = 0;
		*eaten = 0;
	}
	usleep(5);
}

void	*monitor(void *arg)
{
	t_data	*data;
	int		all_philos_eaten;
	int		idx;

	idx = 0;
	all_philos_eaten = 0;
	data = (t_data *)arg;
	while (++idx <= data->philo_count)
	{
		if (data->philos[idx].times_to_eat <= 0)
			all_philos_eaten++;
		if (all_philos_eaten == data->philo_count)
			break ;
		if (checkup(&data->philos[idx], get_time(data)) != 0)
			break ;
		reset(&idx, &all_philos_eaten, data->philo_count);
	}
	set_simulation_finished(data);
	return (arg);
}
