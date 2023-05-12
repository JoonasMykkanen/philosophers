/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:18:27 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/12 15:45:47 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	do_stuff(t_philo *philo, int (*activity) (t_philo *, int))
{
	int	exit_status;
	int	time;

	time = get_time(philo->data);
	if (check_pulse(philo) != 1)
	{
		philo->alive = 0;
		exit_status = 1;
	}
	else
	{
		if (philo->times_to_eat > 0)
			exit_status = activity(philo, time);
		else
			exit_status = 1;
	}
	return (exit_status);
}

void	*routine(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	while (42)
	{
		if (do_stuff(philo, &feast) == 1)
			break ;
		if (do_stuff(philo, &rest) == 1)
			break ;
		if (do_stuff(philo, &think) == 1)
			break ;
	}
	return (philo);
}
