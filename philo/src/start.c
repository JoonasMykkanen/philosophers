/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:21:23 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/10 13:13:53 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	birth_philos(t_data *data)
{
	int	id;

	id = 0;
	while (++id <= data->philo_count)
	{
		if (pthread_create(&data->philos[id].thread, NULL, &routine, &data->philos[id]) != 0)
			return (1);
		usleep(50);
	}
	return (0);
}

int	start(t_data *data)
{
	if (birth_philos(data) != 0)	
		return (1);
	return (0);
}