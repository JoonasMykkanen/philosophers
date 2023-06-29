/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:25:40 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/06/29 17:51:56 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_printer(t_data *data, int time, int id, char *msg)
{
	pthread_mutex_lock(&data->d_lock);
	if (data->someone_dead == 0)
	{
		pthread_mutex_unlock(&data->d_lock);
		printf("%d %d %s\n", time, id, msg);
	}
	else
		pthread_mutex_unlock(&data->d_lock);
}
