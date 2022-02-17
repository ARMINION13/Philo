/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:05:51 by rgirondo          #+#    #+#             */
/*   Updated: 2021/12/04 20:03:23 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;
	int		a;

	ptr = (char *)str;
	a = 0;
	while (ptr[a] != c && ptr[a] != 0)
		a++;
	if (ptr[a] == c)
		return (ptr + a);
	return (NULL);
}
