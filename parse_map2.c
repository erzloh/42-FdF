/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:51:01 by eholzer           #+#    #+#             */
/*   Updated: 2023/01/09 11:43:50 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	set_map(char *map_path, t_map *map)
{
	int		fd;
	int		**tab_2d;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (OPEN_ERROR);
	map->y_len = get_tab_y_size(map_path);
	if (map->y_len == OPEN_ERROR)
		return (OPEN_ERROR);
	if (map->y_len == CLOSE_ERROR)
		return (CLOSE_ERROR);
	tab_2d = create_tab_2d(map, fd);
	if (!tab_2d)
		return (MALLOC_ERROR);
	if (close(fd) == -1)
		return (CLOSE_ERROR);
	map->tab_2d = tab_2d;
	return (0);
}
