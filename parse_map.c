/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:55:25 by eholzer           #+#    #+#             */
/*   Updated: 2022/12/21 10:48:05 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_tab_x_size(char *line)
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
	tab_size = get_tab_x_size(line);
	tab_x = malloc(sizeof(int) * tab_size);
	if (!tab_x)
		return (NULL);
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

int	get_tab_y_size(char *map_path)
{
	int		fd;
	char	buf[100 + 1];
	int		char_read;
	int		i;
	int		size;

	char_read = -1;
	size = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (char_read)
	{
		char_read = read(fd, buf, 100);
		buf[char_read] = '\0';
		i = 0;
		while (buf[i])
		{
			if (buf[i] == '\n')
				size++;
			i++;
		}
	}
	if (close(fd) == -1)
		return (-1);
	return (size);
}

int	**parse_map(char *map_path)
{
	int		fd;
	int		i;
	char	*line;
	int		*tab_x;
	int		**map;
	int		tab_y_size;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	tab_y_size = get_tab_y_size(map_path);	
	map = malloc(sizeof(int *) * (tab_y_size + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < tab_y_size)
	{
		line = get_next_line(fd);
		tab_x = get_tab_x(line);
		map[i] = tab_x;
		i++;
	}
	map[i] = NULL;

	if (close(fd) == -1)
		return (NULL);
	return (map);
}
