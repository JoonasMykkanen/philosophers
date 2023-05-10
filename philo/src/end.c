/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:21:14 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/08 12:35:18 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	wash_forks(t_data *data)
{
	int	id;

	id = 0;
	while (++id <= data->philo_count)
	{
		if (pthread_mutex_destroy(&data->forks[id].fork) != 0)
			return (1);
		usleep(50);
	}
	return (0);
}

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

int	end(t_data *data)
{
	if (bury_philos(data) != 0)
		return (1);
	if (wash_forks(data) != 0)
		return (1);
	// clean_exit(data);
	return (0);
}