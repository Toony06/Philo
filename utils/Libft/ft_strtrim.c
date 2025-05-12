/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:42:33 by toroman           #+#    #+#             */
/*   Updated: 2025/04/03 11:43:44 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	n;

	if (!s1)
		return (NULL);
	if (!set || *set == '\0')
		return (ft_strdup(s1));
	i = 0;
	n = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	if (s1[i])
	{
		while (s1[n] && ft_strchr(set, s1[n]))
			n--;
	}
	str = ft_substr(s1, i, n - i + 1);
	return (str);
}
//int	main()
//{
//	char	*s1 = "xxxwrTony es laxxxxxwr";
//	char	*set = "xwr";
//	char	*trimed = ft_strtrim(s1, set);
//	printf("%s\n", trimed);
//	free (trimed);
//	return (0);
//}
