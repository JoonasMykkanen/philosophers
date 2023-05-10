/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:56:47 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/10 13:49:29 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	get_time(t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->lock);
	time = philo->time;
	pthread_mutex_unlock(&philo->lock);
	return (time);
}

void	update_philo_clock( int update, int	*time, pthread_mutex_t *lock)
{
	pthread_mutex_lock(lock);
	*time = update;
	pthread_mutex_unlock(lock);
}

void	*internal_clock(void *arg)
{
	pthread_mutex_t	mutex_clock;
	struct	timeval	current_t;
	t_philo			*philo;
	int				usec_start;
	int				usec_delta;		
	int				ms;

	pthread_mutex_init(&mutex_clock, NULL);
	ms = 0;
	philo = (t_philo *)arg;
	gettimeofday(&current_t, NULL);
	usec_start = current_t.tv_usec;
	while (philo->alive == 1)
	{
		gettimeofday(&current_t, NULL);
		usec_delta = current_t.tv_usec;
		if (usec_delta - usec_start <= 0)
			usec_start = 0;
		else if (usec_delta - usec_start >= 1000)
		{
			ms++;
			update_philo_clock(ms, &philo->time, &mutex_clock);
			usec_start = usec_delta;
			usec_delta = 0;
		}
		usleep(500);
	}
	pthread_mutex_destroy(&mutex_clock);
	return (philo);
}
