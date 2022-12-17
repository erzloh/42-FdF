/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:32:23 by eholzer           #+#    #+#             */
/*   Updated: 2022/12/17 14:52:31 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_vertical_line(t_mlx mlxd, t_point p1, t_point p2)
{
	t_point		p;

	p.x = p1.x;
	p.y = p1.y;
	if (p2.y < p1.y)
		ft_swap(&p1.y, &p2.y);
	while (p.y <= p2.y)
	{
		mlx_pixel_put(mlxd.mlx_ptr, mlxd.win_ptr, p.x, p.y, 0xFFFFFF);
		p.y++;
	}
}

void	draw_gentle_slope(t_mlx mlxd, t_point p1, t_point p2, t_line_data ld)
{
	t_point		p;

	p.x = p1.x;
	p.y = p1.y;
	ld.slope = f_abs(ld.slope);
	if (p2.x < p1.x)
	{
		ft_swap(&p1.x, &p2.x);
		p.y = p2.y;
	}
	while (p.x <= p2.x)
	{
		mlx_pixel_put(mlxd.mlx_ptr, mlxd.win_ptr, p.x, p.y, 0xFFFFFF);
		ld.offset += ld.slope;
		if (ld.offset >= 0.5)
		{
			p.y += ld.sign;
			ld.offset -= 1;
		}
		p.x++;
	}
}

void	draw_steep_slope(t_mlx mlxd, t_point p1, t_point p2, t_line_data ld)
{
	t_point		p;

	p.x = p1.x;
	p.y = p1.y;
	ld.slope = 1 / ld.slope;
	if (p2.y < p1.y)
	{
		ft_swap(&p1.y, &p2.y);
		p.x = p2.x;
	}
	while (p.y < p2.y)
	{
		mlx_pixel_put(mlxd.mlx_ptr, mlxd.win_ptr, p.x, p.y, 0xFFFFFF);
		ld.offset += ld.slope;
		if (ld.offset >= 0.5)
		{
			p.x += ld.sign;
			ld.offset -= 1;
		}
		p.y++;
	}
}

// Draw a line using Bresenham's line algorithm
void	draw_line(t_mlx mlxd, t_point p1, t_point p2)
{
	t_point		p;
	t_line_data	ld;

	ld.dx = p2.x - p1.x;
	ld.dy = p2.y - p1.y;
	p.x = p1.x;
	p.y = p1.y;
	if (ld.dx == 0)
	{
		draw_vertical_line(mlxd, p1, p2);
		return ;
	}
	ld.slope = (float)ld.dy / (float)ld.dx;
	ld.offset = 0;
	ld.sign = 1;
	if (ld.slope < 0)
		ld.sign = -1;
	if (ld.slope <= 1 && ld.slope >= -1)
		draw_gentle_slope(mlxd, p1, p2, ld);
	else
		draw_steep_slope(mlxd, p1, p2, ld);
}
