/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:21:23 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/14 11:16:35 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	start(t_data *data)
{
	int	id;

	id = 0;
	pthread_create(&data->clock, NULL, &internal_clock, data);
	while (++id <= data->philo_count)
	{
		if (pthread_create(&data->philos[id].thread, NULL, &routine, &data->philos[id]) != 0)
			return (1);
		usleep(50);
	}
	return (0);
}