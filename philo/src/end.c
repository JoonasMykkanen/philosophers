/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:21:14 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/15 11:53:03 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	bury_philos(t_data *data)
{
	int	id;

	id = 0;
	while (++id <= data->philo_count)
	{
		if (pthread_join(data->philos[id].thread, NULL) != 0)
			return (1);
		usleep(50);
	}
	return (0);
}

static int	wash_forks(t_data *data)
{
	int	id;

	id = 0;
	while (++id <= data->philo_count)
	{
		if (pthread_mutex_destroy(&data->forks[id].fork) != 0)
			return (1);
		if (pthread_mutex_destroy(&data->philos[id].lock) != 0)
			return (1);
		usleep(50);
	}
	return (0);
}

int	end(t_data *data)
{
	if (bury_philos(data) != 0)
		return (1);
	// if (wash_forks(data) != 0)
	// 	return (1);
	// pthread_join(data->clock, NULL);
	// pthread_mutex_destroy(&data->t_lock);
	// pthread_mutex_destroy(&data->pulse);
	// if (data->philos)
	// 	free(data->philos);
	// if (data->forks)
	// 	free(data->forks);
	return (0);
}