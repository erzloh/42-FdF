/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:23:01 by eholzer           #+#    #+#             */
/*   Updated: 2022/10/28 14:57:08 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		substr_size;

	if (start + len < ft_strlen(s))
		substr_size = len;
	else if (start > ft_strlen(s) || !len)
		substr_size = 0;
	else
		substr_size = ft_strlen(s) - start;
	substr = malloc(sizeof(char) * (substr_size + 1));
	if (!substr)
		return (NULL);
	if (!len || start > ft_strlen(s))
		*substr = '\0';
	else
		ft_strlcpy(substr, s + start, substr_size + 1);
	return (substr);
}
