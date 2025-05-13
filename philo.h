/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:51:14 by toroman           #+#    #+#             */
/*   Updated: 2025/05/13 19:02:32 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef	struct s_data
{
	int	nb_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_to_eat;
	struct s_philo *philo;
	pthread_mutex_t *fork_mutex;
}		t_data;

typedef struct s_philo
{
	int	fork_right;
	int	fork_left;
	int	philosophe;
	bool	has_eating;
	bool	has_thinking;
	pthread_mutex_t	*left_mutex;
	pthread_mutex_t	*right_mutex;

}		t_philo;

int	ft_num(char **str);
int	ft_atoi(const char *nptr);
int	ft_parsing(int	ac, char **av, t_data *data);
void	init_philo(t_data *data);
void	ft_routine(t_data *data);
int	main(int ac, char **av);
#endif
