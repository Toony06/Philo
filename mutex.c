/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:04:41 by toroman           #+#    #+#             */
/*   Updated: 2025/05/24 17:05:02 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *ptr)
{
	t_data *data;
	int	i;

	data = (t_data *)ptr;
	while(1)
	{
		i = 0;
		while (i < data->nb_of_philo)
		{
			pthread_mutex_lock(&data->meal_check_mutex);
			if (get_time() - data->philo[i].last_meal_time > data->time_to_die)
			{
				pthread_mutex_unlock(&data->meal_check_mutex);
				pthread_mutex_lock(&data->is_dead_mutex);
				data->is_dead = true;
				pthread_mutex_unlock(&data->is_dead_mutex);
				printf("Philo num %d its dead\n", data->philo[i].philosophe);
				return (NULL);
			}
			pthread_mutex_unlock(&data->meal_check_mutex);
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

int	check_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->is_dead_mutex);
	if (philo->data->is_dead == true)
	{
		pthread_mutex_unlock(&philo->data->is_dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->is_dead_mutex);
	return (0);
}

void	check_alone(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork_mutex[philo->fork_left]);
	printf("the philo num %d take left fork\n", philo->philosophe);
	usleep(philo->data->time_to_die * 1000);
	pthread_mutex_unlock(&philo->data->fork_mutex[philo->fork_left]);
}

int	take_fork(t_philo *philo)
{
	if (check_die(philo) == 1)
		return (1);
	pthread_mutex_lock(&philo->data->fork_mutex[philo->fork_left]);
	printf("the philo num %d take left fork\n", philo->philosophe);
	if (check_die(philo) == 1)
	{
		pthread_mutex_unlock(&philo->data->fork_mutex[philo->fork_left]);
		return (1);
	}
	pthread_mutex_lock(&philo->data->fork_mutex[philo->fork_right]);
	printf("the philo num %d take right fork\n", philo->philosophe);
	if (check_die(philo) == 1)
	{
		pthread_mutex_unlock(&philo->data->fork_mutex[philo->fork_right]);
		pthread_mutex_unlock(&philo->data->fork_mutex[philo->fork_left]);
		return (1);
	}
	return (0);
}

void	release_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->fork_mutex[philo->fork_left]);
	pthread_mutex_unlock(&philo->data->fork_mutex[philo->fork_right]);
}
