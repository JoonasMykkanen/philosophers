/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:19:04 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/15 11:52:53 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	am_i_dead(t_philo *philo, int time)
{
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
	return (0);
}


void	clean_exit(t_data *data)
{

}

void	handle_problem(t_data *data)
{
	
}
