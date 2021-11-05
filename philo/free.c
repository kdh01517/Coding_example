/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 21:07:36 by donghyki          #+#    #+#             */
/*   Updated: 2021/11/01 20:30:50 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	philosopher_free(t_philo *philo)
{
	int	i;

	if (philo->philo_info)
		free(philo->philo_info);
	if (philo->fork)
	{
		i = philo->data->philo_num;
		while (i--)
		{
			pthread_mutex_destroy(philo->fork + i);
		}
		free(philo->fork);
	}
	if (philo->thread)
		free(philo->thread);
	if (philo->data)
	{
		if (philo->data->msg_print)
		{
			pthread_mutex_destroy(philo->data->msg_print);
			free(philo->data->msg_print);
		}
		if (philo->data->state)
			free(philo->data->state);
	}
}
