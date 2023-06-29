/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:21:14 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/06/29 17:51:39 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	wait_philos(t_data *data)
{
	int	id;

	id = 0;
	while (++id <= data->philo_count)
	{
		if (pthread_join(data->philos[id].thread, NULL) != 0)
			handle_problem(data);
	}
	pthread_mutex_lock(&data->s_lock);
	data->done = 1;
	pthread_mutex_unlock(&data->s_lock);
}

int	end(t_data *data)
{
	if (pthread_join(data->monitor, NULL) != 0)
		handle_problem(data);
	wait_philos(data);
	if (pthread_join(data->clock, NULL) != 0)
		handle_problem(data);
	clean_exit(data);
	return (0);
}
