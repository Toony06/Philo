/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base16_lowercase.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:04:23 by toroman           #+#    #+#             */
/*   Updated: 2024/11/20 20:08:45 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_base16_lowercase(unsigned int nb)
{
	int		count;
	char	*ptr;

	count = 0;
	ptr = "0123456789abcdef";
	if (nb >= 16)
		count += ft_base16_lowercase(nb / 16);
	ft_putchar(ptr[nb % 16]);
	count++;
	return (count);
}
