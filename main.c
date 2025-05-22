/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:51:33 by toroman           #+#    #+#             */
/*   Updated: 2025/05/22 15:52:28 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data data;
	int i;

	i = 0;

	if (ac != 5 && ac != 6)
	{
		printf("Error no argument valid\n");
		return (1);
	}
	ft_parsing(ac, av, &data);
	init_mutex(&data);
	init_philo(&data);

	pthread_create(&data.monitor_thread, NULL, monitor, &data);
	pthread_join(data.monitor_thread, NULL);
	while (i < data.nb_of_philo)
	{
		pthread_join(data.philo[i].thread1, NULL);
		i++;
	}
	return (0);
}
