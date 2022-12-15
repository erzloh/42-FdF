/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:58:30 by eric              #+#    #+#             */
/*   Updated: 2022/10/28 10:22:33 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*uchar_dst;
	const unsigned char	*uchar_src;
	size_t				i;

	uchar_dst = (unsigned char *)dst;
	uchar_src = (const unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (0);
	if (uchar_dst > uchar_src)
	{
		while (len--)
			uchar_dst[len] = uchar_src[len];
	}
	else
	{
		while (i < len)
		{
			uchar_dst[i] = uchar_src[i];
			i++;
		}
	}
	return (dst);
}
