/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 10:12:40 by donghyki          #+#    #+#             */
/*   Updated: 2021/11/01 21:30:58 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init_information(t_data *data, t_philo *philo, int argc, char **argv)
{
	philo->fork = 0;
	philo->data = data;
	philo->philo_info = 0;
	philo->thread = 0;
	philo->finish = 0;
	data->dead = 0;
	data->state = 0;
	data->msg_print = 0;
	data->howlong_eat = -1;
	if (argc > 4)
	{
		data->philo_num = ft_atoi(argv[1]);
		data->time_to_die = ft_atoi(argv[2]);
		data->time_to_eat = ft_atoi(argv[3]);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	philo;

	if (argc < 5)
	{
		print_error("You have to write at least 4 arguments\n", &philo);
		return (-1);
	}
	else
	{
		if (check_valid(argv) == -1)
		{
			print_error("You have to write positive decimal number argument\n"\
			, &philo);
			return (-1);
		}
		init_information(&data, &philo, argc, argv);
		return (create_philosopher(&data, &philo));
	}
}
