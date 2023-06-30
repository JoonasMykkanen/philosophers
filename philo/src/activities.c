/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:51:07 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/06/30 07:31:21 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	feast(t_philo *philo, int time)
{
	if (grab_forks(philo) != 0)
		return (ERROR);
	if (someone_dead(philo) == 0)
	{
		time = get_time(philo->data);
		philo->last_meal = time;
		ft_printer(philo->data, time, philo->id, "is eating");
		corrected_sleep(philo->time_to_eat, philo->data);
		relase_forks(philo);
		philo->times_to_eat -= 1;
		return (OK);
	}
	relase_forks(philo);
	return (ERROR);
}

int	rest(t_philo *philo, int time)
{
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

	pthread_mutex_lock(&philo->data->d_lock);
	if (philo->data->someone_dead == 0)
	{
		philo->data->someone_dead = 1;
		pthread_mutex_unlock(&philo->data->d_lock);
		philo->alive = 0;
		time_of_death = philo->last_meal + philo->time_to_die;
		printf("%d %d died\n", time_of_death, philo->id);
	}
	else
		pthread_mutex_unlock(&philo->data->d_lock);
	return (ERROR);
}
