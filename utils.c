/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:35:55 by rgirondo          #+#    #+#             */
/*   Updated: 2021/12/04 20:40:53 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	ft_isnbr(char *str)
{
	int	a;

	a = 0;
	if (ft_strchr("-+", str[0]) && str[1] != '\0')
		a++;
	else if (!(ft_strchr("0123456789", str[0])))
		return (-1);
	while (str[a])
	{
		if (!(ft_strchr("0123456789", str[a])))
			return (-1);
		a++;
	}
	return (0);
}

uint64_t	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

int	end_reunion(t_philo **a)
{
	int	i;
	int	s;

	s = 0;
	i = 0;
	while (i != a[0]->nop)
	{
		s = s + a[i]->noe;
		i++;
	}
	return (s);
}

int	thread_display(char *str, t_philo *philo, uint64_t current)
{
	uint64_t	time;

	time = 0;
	if (philo->text && *philo->one_died)
	{
		pthread_mutex_lock(philo->text);
		time = current - philo->start;
		if (*philo->one_died)
			ft_printf("[%i] (%i) : %s\n", time, philo->name, str);
		pthread_mutex_unlock(philo->text);
		return (1);
	}
	return (0);
}

uint64_t	mysleep(int time_to)
{
	uint64_t	curr;

	curr = get_current_time();
	while (get_current_time() < (curr + time_to))
	{
		usleep(100);
	}
	return (get_current_time());
}
