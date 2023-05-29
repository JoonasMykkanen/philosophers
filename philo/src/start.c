/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:21:23 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/24 09:25:17 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	start(t_data *data)
{
	t_philo	*philo;
	int		id;

	id = 0;
	while (++id <= data->philo_count)
	{
		philo = &data->philos[id];
		if (pthread_create(&philo->thread, NULL, &routine, philo) != 0)
			handle_problem(data);
		data->thread_count++;
		usleep(10);
	}
	if (pthread_create(&data->clock, NULL, &internal_clock, data) != 0)
		handle_problem(data);
	return (0);
}
