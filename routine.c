/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:07:53 by rgirondo          #+#    #+#             */
/*   Updated: 2021/12/04 20:59:40 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	take_forks(t_philo *a)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&a->fork);
	i = thread_display("takes fork 1", a, get_current_time());
	if (!i)
		return ;
	if (a->first == 0 && a->status != 0 && a->nop != 1)
		pthread_mutex_lock(a->slot);
	else
		a->first = 0;
	if (a->nop == 1)
		usleep((a->ttd + 1) * 1000);
	i = thread_display("takes fork 2", a, get_current_time());
	if (!i)
		return ;
}

void	philo_sleep(t_philo *a)
{
	int	i;

	i = 0;
	i = thread_display("sleeps", a, get_current_time());
	if (!i)
		return ;
	mysleep(a->tts);
}

void	philo_eat(t_philo *a)
{
	int	i;

	i = 0;
	a->last_eat = get_current_time();
	a->status = 2;
	i = thread_display("eats", a, get_current_time());
	if (!i)
	{
		pthread_mutex_unlock(a->slot);
		pthread_mutex_unlock(&a->fork);
		a->status = 0;
		return ;
	}
	mysleep(a->tte);
	a->status = 1;
	pthread_mutex_unlock(a->slot);
	pthread_mutex_unlock(&a->fork);
	if (*a->one_died)
		a->noe -= 1;
}
