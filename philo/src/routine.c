/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:18:27 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/06/29 18:03:18 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	do_stuff(t_philo *philo, int (*activity) (t_philo *, int))
{
	int	time;

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
	int				round;

	round = 0;
	philo = (t_philo *)arg;
	while (1)
	{
		if (do_stuff(philo, &think) == 1)
			break ;
		if (round == 0)
		{
			if (philo->id % 2)
			{
				corrected_sleep(philo->time_to_eat - 5, philo->data);
			}
		}
		if (do_stuff(philo, &feast) == 1)
			break ;
		if (do_stuff(philo, &rest) == 1)
			break ;
		round++;
		usleep(50);
	}
	return (philo);
}
