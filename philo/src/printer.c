/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:25:40 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/06/08 23:41:27 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_printer(t_data *data, int time, int id, char *msg)
{
	pthread_mutex_lock(&data->d_lock);
	if (data->someone_dead == 0)
	{
		pthread_mutex_unlock(&data->d_lock);
		printf("%d %d %s\n", time, id, msg);
	}
	else
	{
		pthread_mutex_unlock(&data->d_lock);
		if (ft_strncmp(msg, "died", 4) == 0)
			printf("%d %d %s\n", time, id, msg);
	}
}
