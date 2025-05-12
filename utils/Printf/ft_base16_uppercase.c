/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base16_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:46:29 by toroman           #+#    #+#             */
/*   Updated: 2025/04/03 11:44:32 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_base16_uppercase(unsigned int nb)
{
	char	*ptr;
	int		count;

	count = 0;
	ptr = "0123456789ABCDEF";
	if (nb >= 16)
		count += ft_base16_uppercase(nb / 16);
	ft_putchar(ptr[nb % 16]);
	count++;
	return (count);
}
