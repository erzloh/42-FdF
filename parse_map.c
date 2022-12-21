/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:55:25 by eholzer           #+#    #+#             */
/*   Updated: 2022/12/21 11:49:17 by eholzer          ###   ########.fr       */
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

void	set_map(char *map_path, t_map *map)
{
	int		fd;
	int		i;
	char	*line;
	char	got_tab_x_size;
	int		**tab_2d;
	int		*tab_x;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return ;
	got_tab_x_size = 0;
	map->y_len = get_tab_y_size(map_path);
	tab_2d = malloc(sizeof(int *) * (map->y_len + 1));
	if (!tab_2d)
		return ;
	i = 0;
	while (i < map->y_len)
	{
		line = get_next_line(fd);
		if (!got_tab_x_size)
		{
			map->x_len = get_tab_x_size(line);
			got_tab_x_size = 1;
		}
		tab_x = get_tab_x(line);
		tab_2d[i] = tab_x;
		i++;
	}
	tab_2d[i] = NULL;

	if (close(fd) == -1)
		return ;
	map->tab_2d = tab_2d;
}
