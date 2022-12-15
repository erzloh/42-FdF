/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:28:50 by eric              #+#    #+#             */
/*   Updated: 2022/10/27 15:52:01 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{	
	unsigned char	*uchar_b;

	uchar_b = (unsigned char *)b;
	while (len--)
		*(uchar_b++) = (unsigned char)c;
	return (b);
}
