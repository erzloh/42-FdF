/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:20:51 by eholzer           #+#    #+#             */
/*   Updated: 2022/11/01 09:00:14 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		s_len;
	char	*res_str;

	i = 0;
	s_len = ft_strlen(s);
	res_str = malloc(sizeof(char) * s_len + 1);
	if (!res_str)
		return (NULL);
	while (i < s_len)
	{
		res_str[i] = (*f)(i, s[i]);
		i++;
	}
	res_str[i] = '\0';
	return (res_str);
}
