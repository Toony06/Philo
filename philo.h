/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:51:14 by toroman           #+#    #+#             */
/*   Updated: 2025/05/24 15:54:57 by toroman          ###   ########.fr       */
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

typedef struct s_data
{
	int				nb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_to_eat;
	struct s_philo	*philo;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	meal_check_mutex;
	bool			is_dead;
	pthread_mutex_t	is_dead_mutex;
	pthread_t	monitor_thread;
}	t_data;

typedef struct s_philo
{
	int				fork_right;
	int				fork_left;
	int				philosophe;
	int				eat_count;
	long			last_meal_time;
	bool			has_eating;
	bool			has_thinking;
	pthread_t		thread1;
	struct s_data	*data;
}	t_philo;

int		ft_num(char **str);
int		ft_atoi(const char *nptr);
int		ft_parsing(int ac, char **av, t_data *data);
void	init_philo(t_data *data);
void	*ft_routine(void *ptr);
int		main(int ac, char **av);
void	init_mutex(t_data *data);
long	get_time(void);
int 	routine_eat(t_philo *philo);
void	*monitor(void *ptr);
int		check_die(t_philo *philo);
void	check_alone(t_philo *philo);
void	release_fork(t_philo *philo);
int		take_fork(t_philo *philo);
#endif
