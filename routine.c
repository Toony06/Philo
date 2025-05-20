/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:21:47 by toroman           #+#    #+#             */
/*   Updated: 2025/05/20 16:49:52 by toroman          ###   ########.fr       */
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
		data->philo[i].data = data;
		data->philo[i].eat_count = 0;
		if (pthread_create(&data->philo[i].thread1, NULL, ft_routine, &data->philo[i]))
			printf("Erreur threads %d\n", i + 1);
		i++;
	}
}

void	init_mutex(t_data *data)
{
	int	i;

	data->fork_mutex = malloc(sizeof(pthread_mutex_t) * data->nb_of_philo);
	i = 0;
	while (i < data->nb_of_philo)
	{
		pthread_mutex_init(&data->fork_mutex[i], NULL);
		i++;
	}

}

void	*ft_routine(void *ptr)
{
	t_philo *philo;
	philo = (t_philo *)ptr;
	while (1)
	{
		if (philo->philosophe % 2 == 0)
		{
			pthread_mutex_lock(&philo->data->fork_mutex[philo->fork_right]);
			printf("the philo num %d take right fork\n", philo->philosophe);
			pthread_mutex_lock(&philo->data->fork_mutex[philo->fork_left]);
			printf("the philo num %d take left fork\n", philo->philosophe);
		}
		else
		{
			pthread_mutex_lock(&philo->data->fork_mutex[philo->fork_left]);
			printf("the philo num %d take left fork\n", philo->philosophe);
			pthread_mutex_lock(&philo->data->fork_mutex[philo->fork_right]);
			printf("the philo num %d take right fork\n", philo->philosophe);
		}
		printf("the philo num %d has eating\n", philo->philosophe);
		philo->last_meal_time = get_time();
		philo->eat_count++;
		usleep(philo->data->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->data->fork_mutex[philo->fork_left]);
		pthread_mutex_unlock(&philo->data->fork_mutex[philo->fork_right]);
		usleep(philo->data->time_to_sleep * 1000);
	}
	return (NULL);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
