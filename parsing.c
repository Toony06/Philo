/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:33:34 by toroman           #+#    #+#             */
/*   Updated: 2025/05/14 16:20:12 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_num(char **str)
{
	int i;
	int	j;

	i = 1;
	while(str[i])
	{
		j = 0;
		while(str[i][j])
		{
			if (str[i][j] >= '0' && str[i][j] <= '9')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}


int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	signe;

	i = 0;
	result = 0;
	signe = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	return (result * signe);
}

int	ft_parsing(int	ac, char **av, t_data *data)
{
	if (ac != 5 && ac != 6)
	{
		printf("Error no argument valid\n");
		return (1);
	}
	if (ft_num(av))
		{
			printf("Error it not digit\n");
			return (1);
		}
	data->nb_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->must_to_eat = ft_atoi(av[5]);
	init_philo(data);
	ft_routine(data);
	return (0);
}
