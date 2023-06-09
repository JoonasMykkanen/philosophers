/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:19:04 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/03 10:04:22 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	check_numbers(t_data *data)
{
	if (data->time_to_die <= 0)
		return (ERROR);
	if (data->time_to_eat <= 0)
		return (ERROR);
	if (data->time_to_sleep <= 0)
		return (ERROR);
	if (data->times_to_eat <= 0)
		return (NO_SIM);
	return (OK);
}

int	check_values(t_data *data)
{
	int	ret;
	
	if (data->philo_count <= 0)
	{
		printf("Error\n");
		return (ERROR);
	}
	if (data->philo_count == 1)
		return (one_philo(data));
	if (data->times_to_eat == 0)
	{
		return (NO_SIM);
	}
	ret = check_numbers(data);
	if (ret == 1)
	{
		printf("Error\n");
		return (ERROR);
	}
	else if (ret == -1)
		return (ERROR);
	return (OK);
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
	pthread_mutex_destroy(&data->s_lock);
	pthread_mutex_destroy(&data->t_lock);
	pthread_mutex_destroy(&data->d_lock);
}

int	handle_problem(t_data *data)
{
	int	idx;

	idx = 0;
	pthread_mutex_lock(&data->s_lock);
	data->done = 1;
	pthread_mutex_unlock(&data->s_lock);
	pthread_mutex_lock(&data->d_lock);
	data->someone_dead = 1;
	pthread_mutex_unlock(&data->d_lock);
	while (++idx <= data->thread_count)
		pthread_join(data->philos[idx].thread, NULL);
	if (data->monitor_created == 1)
		pthread_join(data->monitor, NULL);
	clean_exit(data);
	return (ERROR);
}
