/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:51:07 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/06/08 23:34:49 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	feast(t_philo *philo, int time)
{
	pthread_mutex_lock(&philo->left->fork);
	if (am_i_dead(philo, get_time(philo->data) == 0))
		ft_printer(philo->data, time, philo->id, "has taken fork");
	if (pthread_mutex_lock(&philo->right->fork) != 0)
		pthread_mutex_unlock(&philo->left->fork);
	time = get_time(philo->data);
	if (someone_dead(philo) == 0 && am_i_dead(philo, time) == 0)
	{
		time = get_time(philo->data);
		ft_printer(philo->data, time, philo->id, "has taken fork");
		ft_printer(philo->data, time, philo->id, "is eating");
		if (am_i_dead(philo, get_time(philo->data)) == 0)
		{
			philo->times_to_eat -= 1;
			philo->last_meal = time;
			corrected_sleep (philo->time_to_eat, philo->data);
			pthread_mutex_unlock(&philo->right->fork);
			pthread_mutex_unlock(&philo->left->fork);
			return (0);
		}
	}
	pthread_mutex_unlock(&philo->right->fork);
	pthread_mutex_unlock(&philo->left->fork);
	return (1);
}

int	rest(t_philo *philo, int time)
{
	if (will_i_die_sleeping(philo, time) == 1)
		return (1);
	ft_printer(philo->data, time, philo->id, "is sleeping");
	corrected_sleep(philo->time_to_sleep, philo->data);
	return (0);
}

int	think(t_philo *philo, int time)
{
	ft_printer(philo->data, time, philo->id, "is thinking");
	return (0);
}

int	death(t_philo *philo)
{
	int time_of_death;

	philo->alive = 0;
	time_of_death = philo->last_meal + philo->time_to_die;
	pthread_mutex_lock(&philo->data->d_lock);
	if (philo->data->someone_dead == 0)
	{
		pthread_mutex_unlock(&philo->data->d_lock);
		pthread_mutex_lock(&philo->data->d_lock);
		philo->data->someone_dead = 1;
		pthread_mutex_unlock(&philo->data->d_lock);
	}
	pthread_mutex_unlock(&philo->data->d_lock);
	corrected_sleep(philo->time_to_sleep, philo->data);
	ft_printer(philo->data, time_of_death, philo->id, "died");
	return (1);
}
