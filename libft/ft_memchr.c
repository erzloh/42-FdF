/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:58:55 by eric              #+#    #+#             */
/*   Updated: 2022/10/25 15:55:03 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*uchar_s;
	unsigned char		uchar_c;

	uchar_s = (const unsigned char *)s;
	uchar_c = (unsigned char)c;
	while (n--)
		if (*uchar_s++ == uchar_c)
			return ((void *)--uchar_s);
	return (NULL);
}
