/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:19:04 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/18 16:32:51 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	am_i_dead(t_philo *philo, int time)
{
	if (philo->times_to_eat <= 0)
		return (1);
	if ((time - philo->last_meal) < philo->time_to_die)
		return (0);
	else		
		return (death(philo));
}

int	not_hungry(t_philo *philo)
{
	if (philo->times_to_eat <= 0)
		return (1);
	else
		return (0);
}

int	someone_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->s_lock);
	if (philo->data->someone_dead == 1)
	{
		pthread_mutex_unlock(&philo->data->s_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->s_lock);
	return (0);
}

int	check_values(t_data *data)
{
	if (data->philo_count == 0)
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
	clean_exit(data);
}
