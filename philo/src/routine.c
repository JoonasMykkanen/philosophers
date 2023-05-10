/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:18:27 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/10 13:50:35 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	feast(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->left->fork) != 0)
	if (pthread_mutex_lock(&philo->right->fork) != 0)
		pthread_mutex_unlock(&philo->left->fork);
	printf("%d %d has taken fork\n", get_time(philo), philo->id);
	printf("%d %d is eating\n", get_time(philo), philo->id);
	usleep(philo->data->time_to_eat);
	philo->ate += 1;
	pthread_mutex_unlock(&philo->right->fork);
	pthread_mutex_unlock(&philo->left->fork);
}

static void	rest(t_philo *philo)
{
	printf("%d %d is sleeping\n", get_time(philo), philo->id);
	usleep(philo->data->time_to_sleep);
}

static void	think(t_philo *philo)
{
	printf("%d %d is thinking\n", get_time(philo), philo->id);
}

void	*routine(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	pthread_mutex_init(&philo->lock, NULL);
	if (pthread_create(&philo->clock, NULL, &internal_clock, philo) != 0)
		exit(1);
	while (42)
	{
		feast(philo);
		rest(philo);
		think(philo);
	}
	if (pthread_join(philo->clock, NULL) != 0)
		exit(1);
	pthread_mutex_unlock(&philo->lock);
	return (arg);
}
