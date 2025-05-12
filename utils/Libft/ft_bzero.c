/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:40:01 by tony              #+#    #+#             */
/*   Updated: 2025/04/03 11:43:44 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

// int main()
// {
//     char str[] = "Hello World";
//     ft_bzero(str, 9);
// 	int i;
//     i = 0;
//     while (i <= 10) {
//         if (str[i] == '\0') 
// 		{
//             write (1, "0 ", 2);
//         } 
// 		else 
// 		{
//             printf("%c", str[i]);
//         }
//         i++;
//     }
//     return 0;
// }
