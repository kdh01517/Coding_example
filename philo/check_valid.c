/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyki <42.4.donghyki@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:33:19 by donghyki          #+#    #+#             */
/*   Updated: 2021/11/01 21:31:04 by donghyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_argv(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_minus(char *str)
{
	if (ft_atoi(str) < 0)
		return (0);
	return (1);
}

int	check_valid(char **argv)
{
	int	i;

	i = 1;
	if (!check_argv(*argv))
	{
		while (argv[i])
		{
			if (!(check_argv(argv[i]) && check_minus(argv[i])))
			{
				return (-1);
			}
			i++;
		}
	}
	return (1);
}
