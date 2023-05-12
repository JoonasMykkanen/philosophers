/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:51:07 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/12 15:48:14 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	feast(t_philo *philo, int time)
{
	pthread_mutex_lock(&philo->left->fork);
	if (pthread_mutex_lock(&philo->right->fork) != 0)
		pthread_mutex_unlock(&philo->left->fork);
	if (check_pulse(philo) == 1)
	{
		time = get_time(philo->data);
		printf("%d %d has taken fork\n", time, philo->id);
		printf("%d %d is eating\n", time, philo->id);
		corrected_sleep(philo->time_to_eat, philo->data);
		philo->times_to_eat -= 1;
		philo->last_meal = time + philo->time_to_eat;
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

int	death(t_philo *philo, int time)
{
	printf("%d %d died\n",time, philo->id);
	return (1);
}
