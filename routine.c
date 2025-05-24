/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:21:47 by toroman           #+#    #+#             */
/*   Updated: 2025/05/24 17:05:13 by toroman          ###   ########.fr       */
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
	{
		if (check_die(philo) == 1)
			break;
		if (routine_eat(philo) == 1)
			break;
		if (check_die(philo) == 1)
			break;
	}
	return (NULL);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int routine_eat(t_philo *philo)
{
	if (philo->data->nb_of_philo <= 1)
	{
		check_alone(philo);
		return (1);
	}
	if (take_fork(philo) == 1)
		return (1);
	pthread_mutex_lock(&philo->data->meal_check_mutex);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->data->meal_check_mutex);
	printf("the philo num %d has eating\n", philo->philosophe);
	philo->eat_count++;
	usleep(philo->data->time_to_eat * 1000);
	if (check_die(philo) == 1)
	{
		release_fork(philo);
		return (1);
	}
	release_fork(philo);
	printf("philo %d is sleeping\n", philo->philosophe);
	usleep(philo->data->time_to_sleep * 1000);
	if (check_die(philo) == 1)
		return (1);
	printf("philo %d is thinking\n", philo->philosophe);
	return (0);
}
