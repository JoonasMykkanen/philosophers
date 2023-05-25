/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:06:05 by joonasmykka       #+#    #+#             */
/*   Updated: 2023/05/23 09:11:54 by joonasmykka      ###   ########.fr       */
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

	// if (ft_isnum(str) != 0)
	// 	return (NULL);
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

static void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		*((char *)s + i) = '\0';
		n--;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	len;
	void	*ptr;

	if (count == 0 || size == 0)
		return (NULL);
	len = count * size;
	if (len / size != count)
		return (NULL);
	ptr = malloc(len);
	if (ptr)
	{
		ft_bzero(ptr, len);
		return (ptr);
	}
	return (NULL);
}

// static int	ft_isnum(char *str)
// {
// 	int	idx;

// 	if (!str)
// 		return (1);
// 	idx = 0;
// 	while(str[idx] != '\0')
// 	{
// 		if (str[idx] == 45 && idx == 0)
// 			idx++;
// 		else if (str[idx] >= 48 && str[idx] <= 57)
// 			idx++;
// 		else
// 			return (1);
// 	}
// 	if (idx == 0)
// 		return (1);
// 	return (0);
// }
