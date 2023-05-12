/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:14:42 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/12 15:37:58 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define MUTEX_ERROR 10
# define THREAD_ERROR 11
# define MALLOC_ERROR 12

# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo	t_philo;

typedef struct s_fork	t_fork;

typedef struct 	s_data
{
	pthread_mutex_t	t_lock;
	pthread_mutex_t	pulse;
	pthread_t		clock;
	t_philo 		*philos;
	t_fork 			*forks;
	int				time;
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				times_to_eat;
	int				someone_dead;
	int				time_to_sleep;
}				t_data;

typedef struct	s_philo
{
	pthread_mutex_t	lock;
	pthread_t		thread;
	int				last_meal;
	int				time_to_sleep;
	int				times_to_eat;
	int				time_to_eat;
	int				time_to_die;
	t_fork			*right;
	t_fork			*left;
	t_data			*data;
	int				alive;
	int				time;
	int				id;
}				t_philo;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				id;
}				t_fork;


int		end(t_data *data);
int		start(t_data *data);
void	*routine(void *arg);
int		get_time(t_data *data);
void	clean_exit(t_data *data);
int		ft_atoi(const char *str);
int		start_clock(t_data *data);
int		finnished(t_philo *philo);
void	*internal_clock(void *arg);
int		check_values(t_data *data);
int		check_pulse(t_philo *philo);
void	*distribute_time(void *arg);
void	handle_problem(t_data *data);
int		rest(t_philo *philo, int time);
int		death(t_philo *philo, int time);
int		feast(t_philo *philo, int time);
int		think(t_philo *philo, int time);
void	corrected_sleep(int	dur, t_data *data);
int		init(int argc, char **argv, t_data *data);

#endif