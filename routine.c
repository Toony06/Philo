/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:21:47 by toroman           #+#    #+#             */
/*   Updated: 2025/05/14 18:05:02 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc (sizeof(t_philo) * data->nb_of_philo);
	data->fork_mutex = malloc(sizeof(pthread_mutex_t) * data->nb_of_philo);
	while (i < data->nb_of_philo)
	{
		data->philo[i].philosophe = i + 1;
		data->philo[i].fork_left = i;
		data->philo[i].fork_right = (i + 1) % data->nb_of_philo;
		data->philo[i].has_eating = false;
		pthread_mutex_init(&data->fork_mutex[i], NULL);
		data->philo[i].left_mutex = &data->fork_mutex[i];
		data->philo[i].right_mutex = &data->fork_mutex[(i + 1)
			% data->nb_of_philo];
		i++;
	}
}

void	ft_routine(t_data *data)
{
	int	i;
	//pthread_create();
	i = 0;
	while (1)
	{
		pthread_mutex_lock(data->philo[i].left_mutex);
		printf("the philo num %d take left fork\n", data->philo->philosophe);
		pthread_mutex_lock(data->philo[i].right_mutex);
		printf("the philo num %d take right fork\n", data->philo->philosophe);
		printf("the philo num %d has eating\n", data->philo->philosophe);
		data->philo->has_eating = true;
		pthread_mutex_unlock(data->philo[i].left_mutex);
		pthread_mutex_unlock(data->philo[i].right_mutex);
		//i++;
	}
}
