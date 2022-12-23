/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:45:15 by eholzer           #+#    #+#             */
/*   Updated: 2022/12/23 15:55:55 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_grid(int *x, int *scaler, int speed)
{
	int	scaler_spd;

	scaler_spd = 2;
	if (*x >= WIN_W)
		*x = 0;
	*x += speed;

	if (*scaler >= 20)
	{
		scaler_spd *= -1;
		*scaler = 9;
	}
	if (*scaler <= -20)
	{
		scaler_spd *= -1;
		*scaler = -9;
	}
	*scaler += scaler_spd;
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
	if (key == K_W)
		mlxd->og_y -= MOVE_DISTANCE;
	if (key == K_S)
		mlxd->og_y += MOVE_DISTANCE;
	if (key == K_A)
		mlxd->og_x -= MOVE_DISTANCE;
	if (key == K_D)
		mlxd->og_x += MOVE_DISTANCE;
	// printf("%d\n", key);
	return (0);
}

int	render(t_mlx *mlxd)
{
	t_map	map;

	map.tab_2d = NULL;
	map.x_len = 0;
	map.y_len = 0;
	set_map("test_maps/42.fdf", &map);
	if (mlxd->win_ptr != NULL)
	{
		render_background(&mlxd->img, BLACK);
		draw_iso_grid(*mlxd, map);
		mlx_put_image_to_window(mlxd->mlx_ptr, mlxd->win_ptr,
			mlxd->img.mlx_img, 0, 0);
	}
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
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
			img_pix_put(img, j, i, color);
			i++;
		}
		j++;
	}
}

int	main(void)
{
	t_mlx	mlxd;
	// t_mapTR	map;
	// int		x = 0;
	// int		y = 0;
	// t_point	p1;
	// t_point p2;

	// p1.x = 24;
	// p1.y = 28;
	// p2.x = 0;
	// p2.y = 0;
	// ---------------------- test -----------------------------------
	// map.tab_2d = NULL;
	// map.x_len = 0;
	// map.y_len = 0;
	// set_map("test_maps/42.fdf", &map);
	// printf("map.y_len = %d\n", map.y_len);
	// printf("map.x_len = %d\n", map.x_len);
	// while (y < map.y_len)
	// {
	// 	x = 0;
	// 	while (x < map.x_len)
	// 	{
	// 		printf("%02d ", map.tab_2d[y][x]);
	// 		x++;
	// 	}
	// 	printf("\n");
	// 	y++;
	// }
	// ---------------------- test -----------------------------------

	mlxd.mlx_ptr = mlx_init();
	if (!mlxd.mlx_ptr)
		return (1);
	mlxd.win_ptr = mlx_new_window(mlxd.mlx_ptr, WIN_W, WIN_H, "FdF");
	if (!mlxd.win_ptr)
		return (1);
	mlxd.scaler = 2;
	mlxd.og_x = 500;
	mlxd.og_y = 250;
	// draw_line(mlxd, p1, p2);
	// draw_grid(mlxd, map);
	// draw_iso_grid(mlxd, map);

	mlxd.img.mlx_img = mlx_new_image(mlxd.mlx_ptr, WIN_W, WIN_H);
	mlxd.img.addr = mlx_get_data_addr(mlxd.img.mlx_img, &mlxd.img.bpp, &mlxd.img.line_len, &mlxd.img.endian);

	mlx_loop_hook(mlxd.mlx_ptr, &render, &mlxd);
	mlx_key_hook(mlxd.win_ptr, handle_input, &mlxd);
	mlx_loop(mlxd.mlx_ptr);
	// mlx_destroy_display(mlxd.mlx_ptr);
	free(mlxd.mlx_ptr);
	return (0);
}

/* int	main(void)
{
	float	a;

	a = 9.f / 4.f;
	printf("float = %f", a);
} */
