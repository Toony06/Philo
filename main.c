/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:51:33 by toroman           #+#    #+#             */
/*   Updated: 2025/05/13 18:11:59 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data *data;

	if (ac)
	{
		data = malloc(sizeof(t_data));
		ft_parsing(ac, av, data);
	}
}
