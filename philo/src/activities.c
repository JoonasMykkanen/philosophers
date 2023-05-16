/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:51:07 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/16 18:03:00 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	handle_forks(t_philo *philo, int time, int mode)
{
	return (0);
}

int	feast(t_philo *philo, int time)
{
	pthread_mutex_lock(&philo->left->fork);
	if (pthread_mutex_lock(&philo->right->fork) != 0)
		pthread_mutex_unlock(&philo->left->fork);
	time = get_time(philo->data);
	if (am_i_dead(philo, time) == 0 && someone_dead(philo) == 0)
	{
		printf("%d %d has taken fork\n", time, philo->id);
		printf("%d %d is eating\n", time, philo->id);
		corrected_sleep(philo->time_to_eat, philo->data);
		philo->times_to_eat -= 1;
		philo->last_meal = time;
		pthread_mutex_unlock(&philo->right->fork);
		pthread_mutex_unlock(&philo->left->fork);
		return (0);
	}
	pthread_mutex_unlock(&philo->right->fork);
	pthread_mutex_unlock(&philo->left->fork);
	return (1);
}

int	rest(t_philo *philo, int time)
{
	printf("%d %d is sleeping\n", time, philo->id);
	corrected_sleep(philo->time_to_sleep, philo->data);
	return (0);
}

int	think(t_philo *philo, int time)
{
	printf("%d %d is thinking\n", time, philo->id);
	return (0);
}

int	death(t_philo *philo)
{
	int	time;
	
	time = get_time(philo->data);
	philo->alive = 0;
	pthread_mutex_lock(&philo->data->s_lock);
	if (philo->data->someone_dead == 0)
	{
		printf("%d %d died\n", time, philo->id);
		philo->data->someone_dead = 1;
	}
	pthread_mutex_unlock(&philo->data->s_lock);
	return (1);
}
