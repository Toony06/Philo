/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:21:47 by toroman           #+#    #+#             */
/*   Updated: 2025/05/13 14:51:01 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc (sizeof(t_philo) * data->nb_of_philo);
	while (i < data->nb_of_philo)
	{
		data->philo[i].philosophe = i + 1;
		data->philo[i].fork_left = i;
		data->philo[i].fork_right = (i + 1) % data->nb_of_philo;
		data->philo[i].has_eating = false;
		pthread_mutex_init(&data->fork_mutex[i], NULL);
		i++;
	}
}

void	ft_routine(t_data *data)
{
	while(1)
	{
		pthread_mutex_lock(&data->fork_mutex[data->philo->fork_left]);
		printf("%d has taken left fork\n", data->philo->philosophe);
	}
}
