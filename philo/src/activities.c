/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:51:07 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/06/29 17:51:36 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
			return (OK);
		}
	}
	pthread_mutex_unlock(&philo->right->fork);
	pthread_mutex_unlock(&philo->left->fork);
	return (ERROR);
}

int	rest(t_philo *philo, int time)
{
	if (will_i_die_sleeping(philo, time) == 1)
		return (ERROR);
	ft_printer(philo->data, time, philo->id, "is sleeping");
	corrected_sleep(philo->time_to_sleep, philo->data);
	return (OK);
}

int	think(t_philo *philo, int time)
{
	ft_printer(philo->data, time, philo->id, "is thinking");
	return (OK);
}

int	death(t_philo *philo)
{
	int	time_of_death;

	philo->alive = 0;
	time_of_death = philo->last_meal + philo->time_to_die;
	pthread_mutex_lock(&philo->data->d_lock);
	if (philo->data->someone_dead == 0)
	{
		pthread_mutex_unlock(&philo->data->d_lock);
		philo->data->someone_dead = 1;
		corrected_sleep(philo->time_to_sleep, philo->data);
		printf("%d %d died\n", time_of_death, philo->id);
	}
	else
		pthread_mutex_unlock(&philo->data->d_lock);
	return (ERROR);
}
