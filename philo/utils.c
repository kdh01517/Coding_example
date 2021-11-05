/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:23:29 by donghyki          #+#    #+#             */
/*   Updated: 2021/11/01 20:27:58 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_atoi(char *str)
{
	long	minus;
	long	num;

	minus = 1;
	num = 0;
	while (*str && (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' \
		|| *str == '\f' || *str == '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (*str - '0') + (num * 10);
		str++;
	}
	if (*str != 0)
	{
		return (-1);
	}
	return (minus * num);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	print_error(char *str, t_philo *philo)
{
	if (philo->data->msg_print)
	{
		pthread_mutex_lock(philo->data->msg_print);
		printf("%s", str);
		pthread_mutex_unlock(philo->data->msg_print);
	}
	philosopher_free(philo);
	philo->finish = 1;
}

void	print_status(t_philo_info *philo, char *str, long ms)
{
	long	time;

	gettimeofday(&(philo->start), NULL);
	time = (long)(philo->start.tv_sec - philo->data->start.tv_sec)*1000 \
	+ (philo->start.tv_usec - philo->data->start.tv_usec) / 1000;
	pthread_mutex_lock(philo->data->msg_print);
	if (philo->data->dead == 0)
		printf("# %5ldms : %d %s", time, philo->philo_index + 1, str);
	if (*str == 'd')
		philo->data->dead = 1;
	pthread_mutex_unlock(philo->data->msg_print);
	if (ms)
	{
		time = check_time_spend(philo);
		while (philo->data->dead == 0 && ms > time)
		{
			time = check_time_die(philo);
			if (time > philo->data->time_to_die)
				print_status(philo, "died\n", 0);
			usleep(100);
			time = check_time_spend(philo);
		}
	}
}
