/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toroman <toroman@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:33:43 by toroman           #+#    #+#             */
/*   Updated: 2025/04/03 11:43:44 by toroman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
//int main() 
//{
//    t_list *node1 = malloc(sizeof(t_list));
//    t_list *node2 = malloc(sizeof(t_list));
//    t_list *node3 = malloc(sizeof(t_list));

//    node1->content = "premier noeud";
//    node2->content = "Second noeud";
//    node3->content = "dernier noeud";

//    node1->next = node2;
//    node2->next = node3;
//    node3->next = NULL;

//    t_list *last = ft_lstlast(node1);
//    if (last)
//        printf("%s\n", (char *)last->content);
//    free(node1);
//    free(node2);
//    free(node3);

//    return 0;
//}
