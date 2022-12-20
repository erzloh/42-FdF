/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:55:25 by eholzer           #+#    #+#             */
/*   Updated: 2022/12/20 14:23:45 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_tab_size(char *line)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ')
		{
			size++;
			while (line[i] != ' ' && line[i] && line[i] != '\n')
			{
				i++;
			}
			i--;
		}
		i++;
	}
	return (size);
}

int	*get_tab_x(char *line)
{
	int		i;
	int		j;
	int		n_len;
	int		*tab_x;
	char	*tmp_str;
	int		tab_size;

	i = 0;
	j = 0;
	n_len = 1;
	tab_size = get_tab_size(line);
	tab_x = malloc(sizeof(int) * tab_size);
	while (line[i])
	{
		if (line[i] != ' ')
		{
			if (line[i + 1] != ' ' && line[i + 1])
				n_len++;
			else
			{
				if (n_len > 1)
				{
					tmp_str = ft_substr(line, i - n_len + 1, n_len);
					tab_x[j] = ft_atoi(tmp_str);
					free(tmp_str);
					n_len = 1;
				}
				else
					tab_x[j] = line[i] - '0';
				j++;
			}
		}
		i++;
	}
	return (tab_x);
}

/* char	**parse_map(char **fdf_map)
{
	int		fd;
	int		i;
	char	*line;
	int		*tab_x;

	fd = open(fdf_map, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	tab_x = get_tab_x(line);
	if (close(fd) == -1)
		return (NULL);
} */
