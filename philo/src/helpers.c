/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:19:04 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/08 19:58:01 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_values(t_data *data)
{
	return (0);
}

void	clean_exit(t_data *data)
{
	if (data->philos)
		free(data->philos);
}