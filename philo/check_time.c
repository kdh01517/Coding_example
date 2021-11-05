/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:46:47 by donghyki          #+#    #+#             */
/*   Updated: 2021/11/01 20:30:05 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	check_time_die(t_philo_info *philo)
{
	long	time;

	gettimeofday(&(philo->now), NULL);
	time = (philo->now.tv_sec - philo->last.tv_sec) * 1000 \
	+ (philo->now.tv_usec - philo->last.tv_usec) / 1000;
	return (time);
}

long	check_time_spend(t_philo_info *philo)
{
	long	time;

	gettimeofday(&(philo->now), NULL);
	time = (philo->now.tv_sec - philo->start.tv_sec) * 1000 \
	+ (philo->now.tv_usec - philo->start.tv_usec) / 1000;
	return (time);
}
