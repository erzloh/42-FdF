/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:54:21 by eholzer           #+#    #+#             */
/*   Updated: 2023/01/09 11:43:52 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	handle_movement(int key, t_mlx *mlxd)
{
	if (key == K_W)
		mlxd->og_y -= MOVE_DISTANCE;
	if (key == K_S)
		mlxd->og_y += MOVE_DISTANCE;
	if (key == K_A)
		mlxd->og_x -= MOVE_DISTANCE;
	if (key == K_D)
		mlxd->og_x += MOVE_DISTANCE;
}

static void	handle_zoom(int key, t_mlx *mlxd)
{
	if (key == K_K)
	{
		mlxd->tile_w += ZOOM_DISTANCE;
		mlxd->tile_h += ZOOM_DISTANCE;
	}
	if (key == K_L)
	{
		mlxd->tile_w -= ZOOM_DISTANCE;
		mlxd->tile_h -= ZOOM_DISTANCE;
	}
	if (key == K_UP)
		mlxd->tile_h -= ZOOM_DISTANCE;
	if (key == K_DOWN)
		mlxd->tile_h += ZOOM_DISTANCE;
	if (key == K_LEFT)
		mlxd->tile_w -= ZOOM_DISTANCE;
	if (key == K_RIGHT)
		mlxd->tile_w += ZOOM_DISTANCE;
}

static void	handle_reset(int key, t_mlx *mlxd)
{
	if (key == K_R)
	{
		mlxd->tile_w = TILE_WIDTH;
		mlxd->tile_h = TILE_HEIGHT;
		mlxd->og_x = ORIGIN_X_ISO;
		mlxd->og_y = ORIGIN_Y_ISO;
	}
}

int	handle_input(int key, t_mlx *mlxd)
{
	(void) mlxd;
	if (key == K_ESC)
	{
		mlx_destroy_window(mlxd->mlx_ptr, mlxd->win_ptr);
		mlxd->win_ptr = NULL;
		free(mlxd->mlx_ptr);
		exit(0);
	}
	if (key == K_O)
		mlxd->scaler++;
	if (key == K_P)
		mlxd->scaler--;
	handle_movement(key, mlxd);
	handle_zoom(key, mlxd);
	handle_reset(key, mlxd);
	return (0);
}
