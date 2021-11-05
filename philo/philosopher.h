/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 10:15:20 by donghyki          #+#    #+#             */
/*   Updated: 2021/11/01 20:32:37 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_data
{
	int					philo_num;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				howlong_eat;
	int					count_eat;
	int					*state;
	int					dead;
	struct timeval		start;
	pthread_mutex_t		*msg_print;
}	t_data;

typedef struct s_philo_info
{
	pthread_t			*thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_data				*data;
	int					philo_index;
	long				limit;
	int					right_philosopher;
	struct timeval		start;
	struct timeval		now;
	struct timeval		last;
}	t_philo_info;

typedef struct s_philo
{
	t_philo_info		*philo_info;
	pthread_t			*thread;
	pthread_mutex_t		*fork;
	t_data				*data;
	int					finish;
}	t_philo;

/* 			using utills function	 		*/
int						ft_atoi(char *str);
int						ft_isdigit(int c);
void					print_error(char *str, t_philo *philo);
/* 			check valid for arguments	 		*/
int						check_valid(char **argv);
/* 			check valid time for arguments	 		*/
long					check_time_die(t_philo_info *philo);
long					check_time_spend(t_philo_info *philo);
/* 			create and handle philosopher	 		*/
int						create_philosopher(t_data *data, t_philo *philo);
/* 			free philosopher	 		*/
void					philosopher_free(t_philo *philo);
/* 			action philosopher	 		*/
void					*create_ph(void *data);
void					pickup(t_philo_info *philo);
void					t_think(void *data);
void					t_sleep(void *data);
void					t_eat(void *data);
/* 			print philosopher status	 		*/
void					print_status(t_philo_info *philo, char *str, long ms);
#endif