/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:14:42 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/10 13:48:55 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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
	t_philo 		*philos;
	t_fork 			*forks;
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				times_to_eat;
	int				someone_dead;
	int				time_to_think;
	int				time_to_sleep;
}				t_data;

typedef struct	s_philo
{
	pthread_mutex_t	lock;
	pthread_t	clock;
	pthread_t	thread;
	t_fork		*right;
	t_fork		*left;
	t_data		*data;
	int			alive;
	int			time;
	int			ate;  
	int			id;
}				t_philo;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				id;
}				t_fork;

void	*internal_clock(void *arg);
int	get_time(t_philo *philo);

int		end(t_data *data);
int		start(t_data *data);
void	*routine(void *arg);
void	clean_exit(t_data *data);
int		ft_atoi(const char *str);
int		start_clock(t_data *data);
int		check_values(t_data *data);
void	handle_problem(t_data *data);
int		init(int argc, char **argv, t_data *data);

#endif