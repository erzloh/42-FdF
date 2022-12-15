/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:37:14 by eholzer           #+#    #+#             */
/*   Updated: 2022/10/29 15:15:29 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_start_junk_len(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	char_found;
	int		junk;

	i = 0;
	char_found = 1;
	junk = 0;
	while (s1[i] && char_found)
	{
		j = 0;
		char_found = 0;
		while (set[j])
		{
			if (set[j] == s1[i])
			{
				junk++;
				char_found = 1;
				break ;
			}
			j++;
		}
		i++;
	}
	return (junk);
}

static int	get_end_junk_len(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	char_found;
	int		junk;

	i = ft_strlen(s1) - 1;
	char_found = 1;
	junk = 0;
	while (i >= 0 && char_found)
	{
		j = 0;
		char_found = 0;
		while (set[j])
		{
			if (set[j] == s1[i])
			{
				junk++;
				char_found = 1;
				break ;
			}
			j++;
		}
		i--;
	}
	return (junk);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	int		trimmed_str_len;
	int		start_junk;
	int		end_junk;

	start_junk = get_start_junk_len(s1, set);
	end_junk = get_end_junk_len(s1, set);
	trimmed_str_len = ft_strlen(s1) - start_junk - end_junk;
	if (trimmed_str_len < 0)
		trimmed_str_len = 0;
	trimmed_str = malloc(sizeof(char) * (trimmed_str_len + 1));
	if (!trimmed_str)
		return (NULL);
	ft_memcpy(trimmed_str, s1 + start_junk, trimmed_str_len);
	trimmed_str[trimmed_str_len] = '\0';
	return (trimmed_str);
}

/* int	main()
{
	char	s1[] = "\t\n hello \r";
	char	set[] = " \n\t\r";

	printf("%s", ft_strtrim(s1, set));
} */