/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:41:28 by donghyki          #+#    #+#             */
/*   Updated: 2021/11/01 20:33:09 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*create_ph(void *data)
{
	t_philo_info	*philo;

	philo = (t_philo_info *)data;
	if (philo->data->dead == 1)
		return (0);
	if (philo->philo_index % 2 == 1)
		philo->data->state[philo->philo_index] = 1;
	while (philo->limit == -1 || philo->limit != 0)
	{
		if (philo->data->dead == 1)
			return (0);
		t_think(philo);
		pickup(philo);
		t_eat(philo);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		philo->data->state[philo->right_philosopher] += 1;
		t_sleep(philo);
		if (philo->limit > 0)
			philo->limit -= 1;
	}
	return (0);
}

void	pickup(t_philo_info *philo)
{
	if (philo->data->dead == 1)
		return ;
	philo->data->state[philo->philo_index] -= 1;
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "left has taken a fork\n", 0);
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "right has taken a fork\n", 0);
}

void	t_think(void *data)
{
	t_philo_info	*philo;

	philo = (t_philo_info *)data;
	if (philo->data->dead == 1)
		return ;
	print_status(philo, "is thinking\n", 0);
	gettimeofday(&(philo->start), NULL);
	while ((check_time_die(philo)) < philo->data->time_to_die)
	{
		if (philo->data->state[philo->philo_index] == 1)
			return ;
		if (philo->data->dead == 1)
			return ;
		usleep(500);
	}
	print_status(philo, "died\n", 0);
}

void	t_sleep(void *data)
{
	t_philo_info	*philo;

	philo = (t_philo_info *)data;
	if (philo->data->dead == 1)
		return ;
	print_status(philo, "is sleeping\n", philo->data->time_to_sleep);
}

void	t_eat(void *data)
{
	t_philo_info	*philo;

	philo = (t_philo_info *)data;
	if (philo->data->dead == 1)
		return ;
	gettimeofday(&(philo->last), NULL);
	print_status(philo, "is eating\n", philo->data->time_to_eat);
}
