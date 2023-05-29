/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:51:07 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/29 13:00:42 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_time_to_slep(int last_meal, int activity_dur, int to_die)
{
	int	elapsed;

	elapsed = last_meal + activity_dur;
	if (elapsed > to_die)
	{
		return (activity_dur - (elapsed - to_die));
	}
	else
		return (activity_dur);
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
		corrected_sleep(
			check_time_to_slep(
			philo->last_meal, 
			philo->time_to_eat, 
			philo->time_to_die), 
			philo->data);
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
	corrected_sleep(
			check_time_to_slep(
			philo->last_meal, 
			philo->time_to_sleep, 
			philo->time_to_die), 
			philo->data);
	return (0);
}

int	think(t_philo *philo, int time)
{
	printf("%d %d is thinking\n", time, philo->id);
	return (0);
}

int	death(t_philo *philo, int time)
{
	// int time_of_death;
	// int	delta;
	
	// delta = time - philo->last_meal;
	// time_of_death = time - delta;
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
