/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base16_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:04:37 by toroman           #+#    #+#             */
/*   Updated: 2025/04/03 11:44:32 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_base16_ptr(unsigned long long nb)
{
	int		count;
	char	*ptr;

	count = 0;
	ptr = "0123456789abcdef";
	if (nb >= 16)
		count += ft_base16_ptr(nb / 16);
	ft_putchar(ptr[nb % 16]);
	count++;
	return (count);
}
