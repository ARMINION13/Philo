/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:15:07 by rgirondo          #+#    #+#             */
/*   Updated: 2021/12/06 16:05:15 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	free_all(t_philo **a)
{
	int	i;

	i = a[0]->nop - 1;
	free(a[0]->text);
	a[0]->text = NULL;
	while (i >= 0)
	{
		pthread_detach(a[i]->status_thread);
		pthread_mutex_destroy(&a[i]->fork);
		pthread_detach(a[i]->philo_thread);
		free(a[i]);
		i--;
	}
	free(a);
}

void	ft_create_threads(t_philo **a)
{
	int			i;
	pthread_t	observer;
	int			some_died;
	int			*ptr;

	ptr = malloc(sizeof(int));
	some_died = 1;
	*ptr = some_died;
	i = 0;
	while (i != a[0]->nop)
	{
		a[i]->one_died = ptr;
		pthread_create(&a[i]->philo_thread, NULL, ft_philo_eat, a[i]);
		i++;
	}
	pthread_create(&observer, NULL, ft_observer, a);
	i = 0;
	while (i != a[0]->nop)
		pthread_join(a[i++]->philo_thread, NULL);
	pthread_join(observer, NULL);
	pthread_detach(observer);
	free(ptr);
	free_all(a);
}

void	ft_link_forks(t_philo **a)
{
	int				i;
	pthread_mutex_t	*text;

	text = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(text, NULL);
	i = 1;
	a[0]->slot = &a[a[0]->nop - 1]->fork;
	a[0]->text = text;
	while (i <= (a[0]->nop - 1))
	{
		a[i]->slot = &a[i - 1]->fork;
		a[i]->text = text;
		i++;
	}
}

void	ft_init_philo(t_philo *a, int argc, char **argv, int name)
{
	a->nop = ft_atoi(argv[1]);
	a->ttd = ft_atoi(argv[2]);
	a->tte = ft_atoi(argv[3]);
	a->tts = ft_atoi(argv[4]);
	a->name = name + 1;
	a->first = 0;
	a->status = 1;
	if (argc == 6)
		a->noe = ft_atoi(argv[5]);
	else
		a->noe = -1;
	pthread_mutex_init(&a->fork, NULL);
}

void leaks(void)
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	int		i;
	t_philo	**philo;

	i = 1;
	philo = 0;
	atexit(leaks);
	while (argv[i] && ft_isnbr(argv[i]) != -1)
		i++;
	if (i-- != argc || (argc != 5 && argc != 6))
		return (-1);
	philo = (t_philo **)malloc((sizeof(t_philo *) * ft_atoi(argv[1])));
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philo[i] = (t_philo *)malloc(sizeof(t_philo));
		ft_init_philo(philo[i], argc, argv, i);
		i++;
	}
	give_premium_pass(philo);
	ft_link_forks(philo);
	ft_create_threads(philo);
	return (0);
}
