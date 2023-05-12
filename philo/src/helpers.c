/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:19:04 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/12 16:07:16 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


int	check_values(t_data *data)
{
	return (0);
}

int	check_pulse(t_philo *philo)
{
	int	time;

	time = get_time(philo->data);
	if ((time - philo->last_meal) > philo->time_to_die)
	{
		pthread_mutex_lock(&philo->data->pulse);
		philo->data->someone_dead = 1;
		pthread_mutex_unlock(&philo->data->pulse);
		death(philo, time);
		return (0);
	}
	return (1);
}

void	clean_exit(t_data *data)
{

}

void	handle_problem(t_data *data)
{
	
}
