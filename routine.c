/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:21:47 by toroman           #+#    #+#             */
/*   Updated: 2025/05/22 15:30:27 by toroman          ###   ########.fr       */
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
		data->philo[i].last_meal_time = get_time();
		pthread_create(&data->philo[i].thread1, NULL,
				ft_routine, &data->philo[i]);
		i++;
	}
	pthread_create(&data->philo->check_monitor, NULL,
			monitor, &data);
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
	pthread_mutex_init(&data->meal_check_mutex, NULL);
	pthread_mutex_init(&data->is_dead_mutex, NULL);
}

void	*ft_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	
	if (philo->philosophe % 2 == 0)
		usleep(5000);
	while (1)
	{	pthread_mutex_lock(&philo->data->is_dead_mutex);
		if (philo->data->is_dead)
		{
			pthread_mutex_unlock(&philo->data->is_dead_mutex);
			break;
		}
		pthread_mutex_unlock(&philo->data->is_dead_mutex);
		routine_eat(philo);
	}
	return (NULL);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void routine_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork_mutex[philo->fork_left]);
	printf("the philo num %d take left fork\n", philo->philosophe);
	pthread_mutex_lock(&philo->data->fork_mutex[philo->fork_right]);
	printf("the philo num %d take right fork\n", philo->philosophe);
	pthread_mutex_lock(&philo->data->meal_check_mutex);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->data->meal_check_mutex);
	printf("the philo num %d has eating\n", philo->philosophe);
	philo->eat_count++;
	usleep(philo->data->time_to_eat * 5000);
	pthread_mutex_unlock(&philo->data->fork_mutex[philo->fork_left]);
	pthread_mutex_unlock(&philo->data->fork_mutex[philo->fork_right]);
	printf("philo %d is sleeping\n", philo->philosophe);
	usleep(philo->data->time_to_sleep * 5000);
	printf("philo %d is thinking\n", philo->philosophe);
}

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
				return (NULL);
			}
			pthread_mutex_unlock(&data->meal_check_mutex);
			i++;
		}
		usleep(5000);
	}
	return (NULL);
}
