/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 18:22:49 by eric              #+#    #+#             */
/*   Updated: 2022/12/24 18:41:20 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Draw a basic 2D grid
/* void	draw_grid(t_mlx mlxd, t_map map)
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
} */

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

void	draw_grid_lines(t_mlx mlxd, t_map map, t_grid_data g)
{
	t_point	p1;
	t_point	p2;

	p1.x = mlxd.og_x + (g.i - g.j) * (mlxd.tile_w / 2);
	p1.y = mlxd.og_y + (g.i + g.j) * (mlxd.tile_h / 2);
	p1.y -= (map.tab_2d[g.j][g.i] * g.scaler);
	if (g.i + 1 < map.x_len)
	{
		p2.x = mlxd.og_x + ((g.i + 1) - g.j) * (mlxd.tile_w / 2);
		p2.y = mlxd.og_y + ((g.i + 1) + g.j) * (mlxd.tile_h / 2);
		p2.y -= (map.tab_2d[g.j][g.i + 1] * g.scaler);
		draw_line(mlxd, p1, p2);
	}
	if (g.j + 1 < map.y_len)
	{
		p2.x = mlxd.og_x + (g.i - (g.j + 1)) * (mlxd.tile_w / 2);
		p2.y = mlxd.og_y + (g.i + (g.j + 1)) * (mlxd.tile_h / 2);
		p2.y -= (map.tab_2d[g.j + 1][g.i] * g.scaler);
		draw_line(mlxd, p1, p2);
	}
}

void	draw_iso_grid(t_mlx mlxd, t_map map)
{
	t_grid_data	g;

	g.scaler = mlxd.scaler;
	g.j = 0;
	while (g.j < map.y_len)
	{
		g.i = 0;
		while (g.i < map.x_len)
		{
			draw_grid_lines(mlxd, map, g);
			g.i++;
		}
		g.j++;
	}
}
