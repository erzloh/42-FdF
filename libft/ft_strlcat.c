/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:47:32 by eric              #+#    #+#             */
/*   Updated: 2022/10/27 13:54:08 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	initial_dst_strlen;

	i = 0;
	j = 0;
	initial_dst_strlen = ft_strlen(dst);
	if (!dstsize || dstsize < initial_dst_strlen)
		return (dstsize + ft_strlen(src));
	while (dst[i])
		i++;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (initial_dst_strlen + ft_strlen(src));
}
