/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:28:56 by toroman           #+#    #+#             */
/*   Updated: 2025/04/03 11:44:32 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int	ft_format(va_list args, const char s)
{
	int	len;

	len = 0;
	if (s == 'd' || s == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (s == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (s == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (s == '%')
		len += ft_putchar('%');
	else if (s == 'x')
		len += ft_base16_lowercase(va_arg(args, unsigned int));
	else if (s == 'X')
		len += ft_base16_uppercase(va_arg(args, unsigned int));
	else if (s == 'u')
		len += ft_uputnbr(va_arg(args, unsigned int));
	else if (s == 'p')
		len += ft_putptr(va_arg(args, unsigned long long));
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += ft_format(args, s[i + 1]);
			i++;
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (len);
}
//int	main()
//{
//	printf("salut je m'appelle %s et jai 19 ans\n", "tony");
//	ft_printf("salut je m'appelle %s et j'ai 19 ans", "tony");
//}
