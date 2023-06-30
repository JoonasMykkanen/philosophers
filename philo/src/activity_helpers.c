/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:22:50 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/06/30 06:35:55 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	relase_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->right->fork);
	pthread_mutex_unlock(&philo->left->fork);
}

int	grab_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->right->fork);
	if (am_i_dead(philo, get_time(philo->data)) == 0)
		ft_printer(philo->data, get_time(philo->data), philo->id, "has taken fork");
	else
		return (ERROR);
	pthread_mutex_lock(&philo->left->fork);
	if (am_i_dead(philo, get_time(philo->data)) == 0)
		ft_printer(philo->data, get_time(philo->data), philo->id, "has taken fork");
	else
		return (ERROR);
	return (OK);
}

int	am_i_dead(t_philo *philo, int time)
{
	if ((time - philo->last_meal) < philo->time_to_die)
		return (OK);
	else
		return (death(philo));
}

int	someone_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->d_lock);
	if (philo->data->someone_dead == 1)
	{
		pthread_mutex_unlock(&philo->data->d_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->d_lock);
	return (0);
}

int	one_philo(t_data *data)
{
	printf("%d 1 has taken fork\n", 0);
	printf("%d 1 died\n", data->time_to_die);
	return (1);
}
