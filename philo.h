/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:16:32 by rgirondo          #+#    #+#             */
/*   Updated: 2021/12/04 20:23:37 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_philo
{
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				noe;
	int				name;
	int				first;
	int				status;
	int				*one_died;
	uint64_t		start;
	uint64_t		last_eat;
	pthread_mutex_t	*text;
	pthread_mutex_t	fork;
	pthread_t		status_thread;
	pthread_mutex_t	*slot;
	pthread_t		philo_thread;
}				t_philo;

int			ft_atoi(const char *str);
char		*ft_strchr(const char *str, int c);
int			ft_isnbr(char *str);
void		*ft_philo_eat(void *arg);
void		take_forks(t_philo *a);
void		give_premium_pass(t_philo **a);
void		*ft_status(void *arg);
void		*ft_observer(void *arg);
void		philo_sleep(t_philo *a);
void		free_all(t_philo **a);
void		philo_eat(t_philo *a);
uint64_t	get_current_time(void);
int			end_reunion(t_philo **a);
uint64_t	mysleep(int time_to);
int			thread_display(char *str, t_philo *philo, uint64_t current);

#endif
