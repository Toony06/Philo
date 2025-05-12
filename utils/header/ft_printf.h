/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:20:32 by toroman           #+#    #+#             */
/*   Updated: 2024/11/21 20:08:06 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_printf(const char *s, ...);
int		ft_base16_lowercase(unsigned int nb);
int		ft_base16_uppercase(unsigned int nb);
int		ft_uputnbr(unsigned int nb);
int		ft_putptr(unsigned long long ptr);
int		ft_base16_ptr(unsigned long long nb);

#endif
