/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:07:05 by toroman           #+#    #+#             */
/*   Updated: 2025/04/03 11:43:44 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
//int	main()
//{
//	t_list *str = malloc(sizeof(t_list));
//	str->content = malloc(sizeof(int));
//	*(int *)(str->content) = 10;
//	str->next = malloc(sizeof(t_list));
//	str->next->content = malloc(sizeof(int));
//	*(int *)(str->next->content) = 20;
//	str->next->next = NULL;

//	int	size = ft_lstsize(str);
//	printf("%d\n", size);
//	free(str->next);
//	free(str);
//	return (0);
//}
