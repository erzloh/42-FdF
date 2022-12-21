/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:22:49 by eric              #+#    #+#             */
/*   Updated: 2022/12/21 17:29:30 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Draw a basic 2D grid
void	draw_grid(t_mlx mlxd, t_map map)
{
	int		i;
	int		j;
	t_point	p1;
	t_point	p2;

	j = 0;
	while (j < map.y_len)
	{
		i = 0;
		while (i < map.x_len)
		{
			p1.x = ORIGIN_X + (i * RAY_SIZE);
			p1.y = ORIGIN_Y + (j * RAY_SIZE);
			if (map.tab_2d[j][i + 1])
			{
				p2.x = p1.x + RAY_SIZE;
				p2.y = p1.y;
				draw_line(mlxd, p1, p2);
			}
			if (map.tab_2d[j + 1] && map.tab_2d[j + 1][i])
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

void	draw_point(t_mlx mlxd, t_point p, int color)
{
	mlx_pixel_put(mlxd.mlx_ptr, mlxd.win_ptr, p.x, p.y, color);
	mlx_pixel_put(mlxd.mlx_ptr, mlxd.win_ptr, p.x + 1, p.y, color);
	mlx_pixel_put(mlxd.mlx_ptr, mlxd.win_ptr, p.x + 2, p.y, color);
	mlx_pixel_put(mlxd.mlx_ptr, mlxd.win_ptr, p.x - 1, p.y, color);
	mlx_pixel_put(mlxd.mlx_ptr, mlxd.win_ptr, p.x - 2, p.y, color);
	mlx_pixel_put(mlxd.mlx_ptr, mlxd.win_ptr, p.x, p.y + 1, color);
	mlx_pixel_put(mlxd.mlx_ptr, mlxd.win_ptr, p.x, p.y + 2, color);
	mlx_pixel_put(mlxd.mlx_ptr, mlxd.win_ptr, p.x, p.y - 1, color);
	mlx_pixel_put(mlxd.mlx_ptr, mlxd.win_ptr, p.x, p.y - 2, color);
}

void	draw_iso_grid(t_mlx mlxd, t_map map)
{
	int		i;
	int		j;
	t_point	p1;
	t_point	p2;
	int		scaler;

	scaler = 2;
	j = 0;
	while (j < map.y_len)
	{
		i = 0;
		while (i < map.x_len)
		{
			p1.x = ORIGIN_X_ISO + (i - j) * (TILE_WIDTH / 2);
			p1.y = ORIGIN_Y_ISO + (i + j) * (TILE_HEIGHT / 2) - (map.tab_2d[j][i] * scaler);
			// mlx_pixel_put(mlxd.mlx_ptr, mlxd.win_ptr, p1.x, p1.y, 0xFF0000);
			if (map.tab_2d[j][i])
				draw_point(mlxd, p1, 0xFF0000);
			if (i + 1 < map.x_len)
			{
				p2.x = ORIGIN_X_ISO + ((i + 1) - j) * (TILE_WIDTH / 2);
				p2.y = ORIGIN_Y_ISO + ((i + 1) + j) * (TILE_HEIGHT / 2) - (map.tab_2d[j][i + 1] * scaler);
				draw_line(mlxd, p1, p2);
				//draw_point(mlxd, p2, 0xFF0000);
			}
			if (j + 1 < map.y_len)
			{
				p2.x = ORIGIN_X_ISO + (i - (j + 1)) * (TILE_WIDTH / 2);
				p2.y = ORIGIN_Y_ISO + (i + (j + 1)) * (TILE_HEIGHT / 2) - (map.tab_2d[j + 1][i] * scaler);
				draw_line(mlxd, p1, p2);
				// draw_point(mlxd, p2, 0x00FF00);
			}
			i++;
		}
		j++;
	}
}
