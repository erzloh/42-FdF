/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:22:49 by eric              #+#    #+#             */
/*   Updated: 2022/12/19 22:41:32 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Draw a basic 2D grid
void	draw_grid(t_mlx mlxd, char **map)
{
	int		i;
	int		j;
	t_point	p1;
	t_point	p2;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			p1.x = ORIGIN_X + (i * RAY_SIZE);
			p1.y = ORIGIN_Y + (j * RAY_SIZE);
			if (map[j][i + 1])
			{
				p2.x = p1.x + RAY_SIZE;
				p2.y = p1.y;
				draw_line(mlxd, p1, p2);
			}
			if (map[j + 1] && map[j + 1][i])
			{
				p2.x = p1.x;
				p2.y = p1.y + RAY_SIZE;
				draw_line(mlxd, p1, p2);
			}
			i++;
		}
		j++;
	}
}

void	draw_iso_grid()
{

}
