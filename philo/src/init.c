/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:38:23 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/12 16:05:33 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	create_forks(t_data *data)
{
	int		id;

	id = 0;
	data->forks = malloc(data->philo_count * sizeof(t_fork) + 1);
	while (++id <= data->philo_count)
	{
		data->forks[id].id = id;
		if (pthread_mutex_init(&data->forks[id].fork, NULL) != 0)
			return (1);
	}
	return (0);
}

static int	create_philos(t_data *data)
{
	int id;

	id = 0;
	data->philos = malloc(data->philo_count * sizeof(t_philo) + 1);
	while (++id <= data->philo_count)
	{
		data->philos[id].id = id;
		data->philos[id].time = 0;
		data->philos[id].alive = 1;
		data->philos[id].data = data;
		data->philos[id].last_meal = 0;
		data->philos[id].right = &data->forks[id];
		data->philos[id].time_to_eat = data->time_to_eat;
		data->philos[id].time_to_die = data->time_to_die;
		data->philos[id].times_to_eat = data->times_to_eat;
		data->philos[id].time_to_sleep = data->time_to_sleep;
		if (pthread_mutex_init(&data->philos[id].lock, NULL) != 0)
			return (1);
		if (id == 1)
			data->philos[id].left = &data->forks[data->philo_count];
		else
			data->philos[id].left = &data->forks[id - 1];
	}
	return (0);
}

int	init(int argc, char **argv, t_data *data)
{
	if (argc != 5 || argc != 6)
	{
		data->time = 0;
		data->someone_dead = 0;
		data->philo_count = ft_atoi(argv[1]);
		data->time_to_die = ft_atoi(argv[2]);
		data->time_to_eat = ft_atoi(argv[3]);
		data->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			data->times_to_eat = ft_atoi(argv[5]);
		else
			data->times_to_eat = INT_MAX;
		if (check_values(data) != 0)
			return (1);
		if (create_forks(data) != 0)
			return (1);
		if (create_philos(data) != 0)
			return (1);
		if (pthread_mutex_init(&data->t_lock, NULL) != 0)
			return (1);
		if (pthread_mutex_init(&data->pulse, NULL) != 0)
			return (1);
		return (0);
	}
	return (1);
}