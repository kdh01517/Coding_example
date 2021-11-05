/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:23:31 by donghyki          #+#    #+#             */
/*   Updated: 2021/11/01 21:29:03 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	make_philosophers(t_data *data, t_philo *philo, int i)
{
	while (i--)
	{
		gettimeofday(&((philo->philo_info)[i].last), NULL);
		if (pthread_create(philo->thread + i, NULL, create_ph, \
							(void *)(philo->philo_info + i)) != 0)
		{
			print_error("Pthread_create Error.\n", philo);
			data->dead = 1;
		}
	}
}

void	join_philosopher(t_philo *philo, int i)
{
	while (i--)
		pthread_join(philo->thread[i], NULL);
	philosopher_free(philo);
}

int	main_handler(t_data *data, t_philo *philo)
{
	int	i;

	if (pthread_mutex_init(data->msg_print, NULL) != 0)
	{
		pthread_mutex_lock(data->msg_print);
		print_error("Pthread_mutex_init Error.\n", philo);
		return (-1);
	}
	i = data->philo_num;
	make_philosophers(data, philo, i);
	join_philosopher(philo, i);
	if (philo->finish == 1)
		return (-1);
	return (1);
}

void	define_philosopher(t_data *data, t_philo *philo)
{
	int	i;

	i = data->philo_num;
	while (i--)
	{
		philo->philo_info[i].left_fork = philo->fork + i;
		philo->philo_info[i].right_fork = philo->fork + (i + 1) % \
			data->philo_num;
		philo->philo_info[i].data = data;
		philo->philo_info[i].thread = philo->thread + i;
		(philo->philo_info[i]).philo_index = i;
		*(data->state + i) = 0;
		philo->philo_info[i].limit = data->howlong_eat;
		philo->philo_info[i].right_philosopher = (i + 1 + data->philo_num) % \
			data->philo_num;
	}
}

int	create_philosopher(t_data *data, t_philo *philo)
{
	int	i;

	i = data->philo_num;
	data->msg_print = malloc(sizeof(pthread_mutex_t));
	philo->fork = malloc(sizeof(pthread_mutex_t) * i);
	philo->philo_info = malloc(sizeof(t_philo_info) * i);
	philo->thread = malloc(sizeof(pthread_t) * i);
	data->state = malloc(sizeof(int) * i);
	if (!(data->state && data->msg_print && philo->fork && philo->philo_info \
		&& philo->thread))
	{
		print_error("Malloc Error.\n", philo);
		return (-1);
	}
	define_philosopher(data, philo);
	while (i--)
	{
		if (pthread_mutex_init(philo->fork + i, NULL) != 0)
		{
			print_error("Pthread_mutex_init Error.\n", philo);
			return (-1);
		}
	}
	gettimeofday(&(data->start), NULL);
	return (main_handler(data, philo));
}
