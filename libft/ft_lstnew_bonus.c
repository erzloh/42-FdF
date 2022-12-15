/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:58:07 by eholzer           #+#    #+#             */
/*   Updated: 2022/11/01 16:31:12 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node_ptr;

	node_ptr = malloc(sizeof(t_list));
	if (!node_ptr)
		return (NULL);
	node_ptr->content = content;
	node_ptr->next = NULL;
	return (node_ptr);
}
