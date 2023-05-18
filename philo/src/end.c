/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:21:14 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/18 16:32:34 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	wait_philos(t_data *data)
{
	int	id;

	id = 0;
	while (++id <= data->philo_count)
	{
		if (pthread_join(data->philos[id].thread, NULL) != 0)
			handle_problem(data);
		usleep(50);
	}
	pthread_mutex_lock(&data->s_lock);
	data->done = 1;
	pthread_mutex_unlock(&data->s_lock);
	return (0);
}

int	end(t_data *data)
{
	if (wait_philos(data) != 0)
		return (1);
	if (pthread_join(data->clock, NULL) != 0)
		handle_problem(data);
	clean_exit(data);
	return (0);
}