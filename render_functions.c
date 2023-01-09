/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:12:50 by eholzer           #+#    #+#             */
/*   Updated: 2023/01/09 11:43:48 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	render(t_mlx *mlxd)
{
	if (mlxd->win_ptr != NULL)
	{
		render_background(&mlxd->img, BLUE);
		draw_iso_grid(*mlxd, mlxd->map);
		mlx_put_image_to_window(mlxd->mlx_ptr, mlxd->win_ptr,
			mlxd->img.mlx_img, 0, 0);
	}
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= WIN_W || y >= WIN_H || x <= 0 || y <= 0)
		return ;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	if (!pixel)
		printf("%p\n", pixel);
	*(int *)pixel = color;
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < WIN_H)
	{
		i = 0;
		while (i < WIN_W)
		{
			img_pix_put(img, i, j, color);
			i++;
		}
		j++;
	}
}
