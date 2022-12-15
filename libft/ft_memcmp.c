/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:09:14 by eric              #+#    #+#             */
/*   Updated: 2022/10/26 12:11:37 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*uchar_s1;
	const unsigned char	*uchar_s2;
	size_t				i;

	uchar_s1 = (const unsigned char *)s1;
	uchar_s2 = (const unsigned char *)s2;
	i = 0;
	if (!n)
		return (0);
	while (uchar_s1[i] == uchar_s2[i] && i < n - 1)
		i++;
	return (uchar_s1[i] - uchar_s2[i]);
}
