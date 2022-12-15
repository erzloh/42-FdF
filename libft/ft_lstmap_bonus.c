/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:17:22 by eric              #+#    #+#             */
/*   Updated: 2022/11/03 10:50:25 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res_lst_node;
	t_list	*res_lst_first_node;

	res_lst_first_node = NULL;
	(void) del;
	while (lst)
	{
		res_lst_node = ft_lstnew((*f)(lst->content));
		if (!res_lst_node)
			return (NULL);
		ft_lstadd_back(&res_lst_first_node, res_lst_node);
		lst = lst->next;
	}
	return (res_lst_first_node);
}
