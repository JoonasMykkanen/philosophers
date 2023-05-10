/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 01:17:12 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/09 12:34:58 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (init(argc, argv, &data) != 0)
		return (1);
	if (start(&data) != 0)
		return (1);
	if (end(&data) != 0)
		return (1);
	return (0);
}