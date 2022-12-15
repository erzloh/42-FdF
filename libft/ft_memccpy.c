/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:51:36 by eric              #+#    #+#             */
/*   Updated: 2022/10/25 15:55:04 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*uchar_dst;
	const unsigned char	*uchar_src;
	unsigned char		uchar_c;
	size_t				i;

	uchar_dst = (unsigned char *)dst;
	uchar_src = (const unsigned char *)src;
	uchar_c = (unsigned char)c;
	while (uchar_src[i] && n--)
	{
		uchar_dst[i] = uchar_src[i];
		if (uchar_src[i] == uchar_c)
			return (uchar_dst + i + 1);
		i++;
	}
	return (NULL);
}
