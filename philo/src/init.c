/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:38:23 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/06/01 10:34:12 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	create_forks(t_data *data)
{
	t_fork	fork;
	int		id;

	id = 0;
	data->forks = ft_calloc(data->philo_count + 1, sizeof(t_fork));
	if (!data->forks)
		handle_problem(data);
	while (++id <= data->philo_count)
	{
		data->forks[id] = fork;
		data->forks[id].id = id;
		if (pthread_mutex_init(&data->forks[id].fork, NULL) != 0)
			handle_problem(data);
		data->fork_count++;
	}
	return (0);
}

static void	init_philo_struct(t_data *data, t_philo *philo, int id)
{
	data->philos[id] = *philo;
	data->philos[id].id = id;
	data->philos[id].time = 0;
	data->philos[id].alive = 1;
	data->philos[id].data = data;
	data->philos[id].last_meal = 0;
	data->philos[id].right = &data->forks[id];
	data->philos[id].philo_count = data->philo_count;
	data->philos[id].time_to_eat = data->time_to_eat;
	data->philos[id].time_to_die = data->time_to_die;
	data->philos[id].times_to_eat = data->times_to_eat;
	data->philos[id].time_to_sleep = data->time_to_sleep;
}

static int	create_philos(t_data *data)
{
	t_philo	philo;
	int		id;

	id = 0;
	data->philos = ft_calloc(data->philo_count + 1, sizeof(t_philo));
	if (!data->philos)
		handle_problem(data);
	while (++id <= data->philo_count)
	{
		init_philo_struct(data, &philo, id);
		if (pthread_mutex_init(&data->philos[id].lock, NULL) != 0)
			handle_problem(data);
		data->lock_count++;
		if (id == 1)
			data->philos[id].left = &data->forks[data->philo_count];
		else
			data->philos[id].left = &data->forks[id - 1];
	}
	return (0);
}

static void	init_data_struct(t_data *data, int argc, char **argv)
{
	data->time = 0;
	data->done = 0;
	data->forks = NULL;
	data->philos = NULL;
	data->lock_count = 0;
	data->fork_count = 0;
	data->someone_dead = 0;
	data->thread_count = 0;
	data->philo_count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->times_to_eat = ft_atoi(argv[5]);
	else
		data->times_to_eat = INT_MAX;
}

int	init(int argc, char **argv, t_data *data)
{
	if (argc != 5 || argc != 6)
	{
		init_data_struct(data, argc, argv);
		if (check_values(data) != 0)
			return (1);
		if (create_forks(data) != 0)
			handle_problem(data);
		if (create_philos(data) != 0)
			handle_problem(data);
		if (pthread_mutex_init(&data->t_lock, NULL) != 0)
			handle_problem(data);
		if (pthread_mutex_init(&data->s_lock, NULL) != 0)
			handle_problem(data);
		if (pthread_mutex_init(&data->p_lock, NULL) != 0)
			handle_problem(data);
		if (pthread_mutex_init(&data->d_lock, NULL) != 0)
			handle_problem(data);
		return (0);
	}
	return (1);
}
