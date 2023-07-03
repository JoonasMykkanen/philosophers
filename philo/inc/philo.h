/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmykkane <jmykkane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:14:42 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/07/03 09:48:47 by jmykkane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

# define OK 0
# define NO_SIM -1
# define ERROR 1

typedef struct s_philo	t_philo;

typedef struct s_fork	t_fork;

typedef struct s_data
{
	pthread_mutex_t	t_lock;
	pthread_mutex_t	d_lock;
	pthread_mutex_t	s_lock;
	pthread_t		monitor;
	pthread_t		clock;
	t_philo			*philos;
	t_fork			*forks;
	int				done;
	int				time;
	int				philo_count;
	int				monitor_created;
	int				thread_count;
	int				fork_count;
	int				lock_count;
	int				time_to_die;
	int				time_to_eat;
	int				times_to_eat;
	int				someone_dead;
	int				time_to_sleep;
}				t_data;

typedef struct s_philo
{
	pthread_mutex_t	lock;
	pthread_t		thread;
	int				last_meal;
	int				philo_count;
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
}					t_philo;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				id;
}				t_fork;

int		end(t_data *data);
void	*monitor(void *arg);
int		start(t_data *data);
void	*routine(void *arg);
int		death(t_philo *philo);
int		get_time(t_data *data);
int		one_philo(t_data *data);
void	clean_exit(t_data *data);
int		ft_atoi(const char *str);
int		start_clock(t_data *data);
void	*internal_clock(void *arg);
int		grab_forks(t_philo *philo);
int		check_values(t_data *data);
void	relase_forks(t_philo *philo);
int		someone_dead(t_philo *philo);
int		handle_problem(t_data *data);
int		rest(t_philo *philo, int time);
int		feast(t_philo *philo, int time);
int		think(t_philo *philo, int time);
int		checkup(t_philo *philo, int time);
int		am_i_dead(t_philo *philo, int time);
void	*ft_calloc(size_t count, size_t size);
void	corrected_sleep(int dur, t_data *data);
int		init(int argc, char **argv, t_data *data);
void	ft_printer(t_data *data, int time, int id, char *msg);

#endif