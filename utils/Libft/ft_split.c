/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:40:19 by toroman           #+#    #+#             */
/*   Updated: 2025/04/03 11:43:44 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

static int	ft_countword(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			j++;
		while (s[i] != c && s[i])
			i++;
	}
	return (j);
}

static	char	*lenword(char **res, const char *s, char c)
{
	int	len;
	int	i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len > 0)
		{
			res[i] = malloc(len + 1);
			if (res[i] == NULL)
				return (NULL);
			ft_strlcpy(res[i], s - len, len + 1);
			i++;
		}
	}
	return (res[i]);
}

char	**ft_split(char const *s, char c)
{
	int				mot;
	char			**res;

	if (!s)
		return (NULL);
	mot = ft_countword(s, c);
	res = malloc(sizeof(char *) * (mot + 1));
	if (!res)
		return (NULL);
	res[mot] = NULL;
	lenword(res, s, c);
	return (res);
}
//int main(void)
//{
//	char	*str = "xxsaxx ditx xxxxxquoi xsplitxxx xxxyx xxxfaisx xxserrerxx";
//	char	**split = ft_split(str, 'x');
//	while (*split)
//	{
//		printf("%s", *split);
//		split++;
//	}
//	free (*split);
//	return (0);
//}
