/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:55:25 by eholzer           #+#    #+#             */
/*   Updated: 2023/02/20 15:57:34 by eholzer          ###   ########.fr       */
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

void	set_tab_x(char *line, t_tab_x *tab)
{
	while (line[tab->i])
	{
		if (line[tab->i] != ' ')
		{
			if (line[tab->i + 1] != ' ' && line[tab->i + 1])
				tab->n_len++;
			else
			{
				if (tab->n_len > 1)
				{
					tab->tmp_str = ft_substr(line,
							tab->i - tab->n_len + 1, tab->n_len);
					tab->tab[tab->j] = ft_atoi(tab->tmp_str);
					free(tab->tmp_str);
					tab->n_len = 1;
				}
				else
					tab->tab[tab->j] = line[tab->i] - '0';
				tab->j++;
			}
		}
		tab->i++;
	}
}

int	*get_tab_x(char *line)
{
	t_tab_x	tab;

	tab.i = 0;
	tab.j = 0;
	tab.n_len = 1;
	tab.size = get_tab_x_size(line);
	tab.tab = malloc(sizeof(int) * tab.size);
	if (!tab.tab)
		exit(1);
		//return (NULL);
	set_tab_x(line, &tab);
	return (tab.tab);
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
		return (OPEN_ERROR);
	while (char_read)
	{
		char_read = read(fd, buf, 100);
		buf[char_read] = '\0';
		i = -1;
		while (buf[++i])
			if (buf[i] == '\n')
				size++;
	}
	if (close(fd) == -1)
		return (CLOSE_ERROR);
	return (size);
}

int	**create_tab_2d(t_map *map, int fd)
{
	int		i;
	char	*line;
	char	got_tab_x_size;
	int		*tab_x;
	int		**tab_2d;

	got_tab_x_size = 0;
	i = -1;
	tab_2d = malloc(sizeof(int *) * (map->y_len + 1));
	if (!tab_2d)
		return (NULL);
	while (++i < map->y_len)
	{
		line = get_next_line(fd);
		if (!got_tab_x_size)
		{
			map->x_len = get_tab_x_size(line);
			got_tab_x_size = 1;
		}
		tab_x = get_tab_x(line);
		tab_2d[i] = tab_x;
		free(line);
	}
	tab_2d[i] = NULL;
	return (tab_2d);
}
