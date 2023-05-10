/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:06:05 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/05 16:06:06 by joonasmykka      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_overflow(int neg)
{
	if (neg == 1)
		return (-1);
	if (neg == -1)
		return (0);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			neg;
	long long	sum;

	i = 0;
	sum = 0;
	neg = 1;
	while (((str[i] < 14 && str[i] > 8) || str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		sum = sum * 10 + (str[i] - '0');
		if (sum < 0)
			return (ft_overflow(neg));
		i++;
	}
	return (sum * neg);
}