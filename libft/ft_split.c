/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:33:14 by eric              #+#    #+#             */
/*   Updated: 2022/10/31 08:33:50 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns the number of (char c) characters to 
skip to get to the start of a word */
static int	char_to_word_start(char const *s, char c, char *ptr_end_of_str)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	if (!s[i])
		*ptr_end_of_str = 1;
	return (i);
}

// Returns the number of characters to skip to get to the end of a word
static int	char_to_word_end(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	get_word_nb(char const *s, char c)
{
	int		i;
	int		word_nb;
	char	end_of_str;
	char	*ptr_end_of_str;

	i = 0;
	word_nb = 0;
	end_of_str = 0;
	ptr_end_of_str = &end_of_str;
	while (s[i])
	{
		i += char_to_word_start(s + i, c, ptr_end_of_str);
		if (end_of_str)
			break ;
		i += char_to_word_end(s + i, c);
		word_nb++;
	}
	return (word_nb);
}

static int	get_word_size(char const *s, char c, int n, int *ptr_word_start)
{
	int		word_size;
	char	end_of_str;
	char	*ptr_end_of_str;
	int		i;

	word_size = 0;
	end_of_str = 0;
	ptr_end_of_str = &end_of_str;
	i = 0;
	while (s[i] && n--)
	{
		i += char_to_word_start(s + i, c, ptr_end_of_str);
		if (end_of_str)
			return (word_size);
		i += char_to_word_end(s + i, c);
	}
	i += char_to_word_start(s + i, c, ptr_end_of_str);
	*ptr_word_start = i;
	while (s[i] && s[i++] != c)
		word_size++;
	return (word_size);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**strs;
	int		word_start;
	int		*ptr_word_start;
	int		word_size;

	ptr_word_start = &word_start;
	i = 0;
	strs = malloc(sizeof(char *) * (get_word_nb(s, c) + 1));
	if (!strs)
		return (NULL);
	while (i < get_word_nb(s, c))
	{
		word_size = get_word_size(s, c, i, ptr_word_start);
		strs[i] = malloc(sizeof(char) * (word_size + 1));
		if (!strs[i])
			return (NULL);
		ft_memcpy(strs[i], s + word_start, word_size);
		strs[i][word_size] = '\0';
		i++;
	}
	strs[get_word_nb(s, c)] = NULL;
	return (strs);
}
