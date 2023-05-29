/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:19:04 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/23 09:07:24 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_numbers(t_data *data)
{
	if (data->time_to_die == 0)
		return (1);
	if (data->time_to_eat == 0)
		return (1);
	if (data->time_to_sleep == 0)
		return (1);
	if (data->times_to_eat == 0)
		return (1);
	return (0);
}

int	check_values(t_data *data)
{
	if (data->philo_count == 0)
		return (1);
	if (data->philo_count == 1)
		return (one_philo(data));
	if (data->times_to_eat == 0)
		return (1);
	if (check_numbers(data) != 0)
		return (1);
	return (0);
}

void	clean_exit(t_data *data)
{
	int	idx;

	idx = 0;
	while (++idx <= data->fork_count)
		pthread_mutex_destroy(&data->forks[idx].fork);
	idx = 0;
	while (++idx <= data->lock_count)
		pthread_mutex_destroy(&data->philos[idx].lock);
	if (data->forks != NULL)
		free(data->forks);
	if (data->philos != NULL)
		free(data->philos);
}

void	handle_problem(t_data *data)
{
	int	idx;

	idx = 0;
	pthread_mutex_lock(&data->s_lock);
	data->done = 1;
	data->someone_dead = 1;
	pthread_mutex_unlock(&data->s_lock);
	while (++idx <= data->thread_count)
	{
		if (pthread_join(data->philos[idx].thread, NULL) != 0)
			handle_problem(data);
	}
	clean_exit(data);
}
