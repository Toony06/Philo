/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:03:50 by tony              #+#    #+#             */
/*   Updated: 2025/04/03 11:43:44 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len_src;

	j = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (n <= j)
	{
		return (n + len_src);
	}
	while (src[i] && j + 1 < n)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (ft_strlen(src + i) + j);
}
// int	main()
// {
// 	char dst[20] = "hello";
// 	const char src[] = "world";
// 	size_t size = 10;

// 	printf("%zu", ft_strlcat(dst, src, size));
// 	return (0);
// }
