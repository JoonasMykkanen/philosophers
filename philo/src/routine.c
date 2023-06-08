/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:18:27 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/06/01 11:45:32 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	do_stuff(t_philo *philo, int (*activity) (t_philo *, int), int mode)
{
	int	time;

	if (not_hungry(philo) == 1)
		return (1);
	if (someone_dead(philo) == 1)
		return (1);
	time = get_time(philo->data);
	if (am_i_dead(philo, time) == 1)
		return (1);
	return (activity(philo, time));
}

void	*routine(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		corrected_sleep(philo->time_to_eat - 5, philo->data);
	while (1)
	{
		if (do_stuff(philo, &think, 3) == 1)
			break ;
		if (do_stuff(philo, &feast, 1) == 1)
			break ;
		if (do_stuff(philo, &rest, 2) == 1)
			break ;
		usleep(50);
	}
	return (philo);
}
