/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:38:23 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/10 13:25:39 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	create_forks(t_data *data)
{
	pthread_mutex_t	fork;
	int		id;

	id = 0;
	data->forks = malloc(data->philo_count * sizeof(t_fork) + 1);
	while (++id <= data->philo_count)
	{
		data->forks[id].fork = *(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		data->forks[id].fork = fork;
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
		data->philos[id].ate = 0;
		data->philos[id].id = id;
		data->philos[id].alive = 1;
		data->philos[id].right = &data->forks[id];
		data->philos[id].data = data;
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
		data->someone_dead = 0;
		data->philo_count = ft_atoi(argv[1]);
		data->time_to_die = ft_atoi(argv[2]) * 1000;
		data->time_to_eat = ft_atoi(argv[3]) * 1000;
		data->time_to_sleep = ft_atoi(argv[4]) * 1000;
		if (argc == 6)
			data->times_to_eat = ft_atoi(argv[5]);
		if (check_values(data) != 0)
			return (1);
		if (create_forks(data) != 0)
			return (1);
		if (create_philos(data) != 0)
			return (1);
		return (0);
	}
	return (1);
}