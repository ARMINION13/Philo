/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 19:50:07 by rgirondo          #+#    #+#             */
/*   Updated: 2021/12/04 21:00:30 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	*ft_status(void *arg)
{
	t_philo		*a;
	uint64_t	time;

	time = 0;
	a = (t_philo *)arg;
	while ((time <= (uint64_t)a->ttd || a->status == 2) && a->one_died)
	{
		time = get_current_time() - a->last_eat;
		usleep(1);
	}
	if (a->noe || *a->one_died == 0)
		a->status = 0;
	if (a->noe)
		*a->one_died = 0;
	return (0);
}

void	*ft_observer(void *arg)
{
	t_philo		**a;
	int			i;
	int			j;
	uint64_t	time;

	j = 0;
	i = 0;
	a = (t_philo **)arg;
	while (a[i]->status > 0)
	{
		if (end_reunion(a) == 0)
			return (0);
		if (i == (a[0]->nop - 1))
			i = 0;
		else
			i++;
	}
	time = get_current_time() - a[i]->start;
	pthread_mutex_lock(a[i]->text);
	ft_printf("[%i] (%i) : has died\n", time, a[i]->name);
	pthread_mutex_unlock(a[i]->text);
	return (0);
}

void	*ft_philo_eat(void *arg)
{
	t_philo	*a;

	a = (t_philo *)arg;
	a->last_eat = get_current_time();
	a->start = get_current_time();
	pthread_create(&a->status_thread, NULL, ft_status, a);
	if (a->first == 1 && a->nop != 1)
		pthread_mutex_lock(a->slot);
	else
		usleep(1);
	while (a->noe && a->status != 0)
	{
		if (a->status && a->one_died)
			take_forks(a);
		if (a->status && a->one_died)
			philo_eat(a);
		if (a->status && a->one_died)
			philo_sleep(a);
		if (a->status && a->noe && a->one_died)
			thread_display("is thinking", a, get_current_time());
	}
	pthread_join(a->status_thread, NULL);
	a->status = 3;
	pthread_detach(a->status_thread);
	return (0);
}
