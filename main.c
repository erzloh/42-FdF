/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:45:15 by eholzer           #+#    #+#             */
/*   Updated: 2022/12/24 21:21:13 by eric             ###   ########.fr       */
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
	if (key == K_R)
	{
		mlxd->tile_w = TILE_WIDTH;
		mlxd->tile_h = TILE_HEIGHT;
		mlxd->og_x = ORIGIN_X_ISO;
		mlxd->og_y = ORIGIN_Y_ISO;
	}
	// printf("%d\n", key);
	return (0);
}

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

void	print_map(t_map map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map.y_len)
	{
		i = 0;
		while (i < map.x_len)
		{
			printf("%d ", map.tab_2d[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
	printf("x_len = %d\n", map.x_len);
	printf("y_len = %d\n", map.y_len);
}

int	main(int ac, char **av)
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
	if (ac != 2)
	{
		ft_printf("Error: you must enter one argument.");
		return (1);
	}
	mlxd.mlx_ptr = mlx_init();
	if (!mlxd.mlx_ptr)
		return (1);
	mlxd.win_ptr = mlx_new_window(mlxd.mlx_ptr, WIN_W, WIN_H, "FdF");
	if (!mlxd.win_ptr)
		return (1);
	mlxd.scaler = 2;
	mlxd.og_x = 500;
	mlxd.og_y = 250;
	mlxd.tile_w = TILE_WIDTH;
	mlxd.tile_h = TILE_HEIGHT;
	mlxd.map_path = av[1];
	// draw_line(mlxd, p1, p2);
	// draw_grid(mlxd, map);
	// draw_iso_grid(mlxd, map);

	mlxd.img.mlx_img = mlx_new_image(mlxd.mlx_ptr, WIN_W, WIN_H);
	mlxd.img.addr = mlx_get_data_addr(mlxd.img.mlx_img, &mlxd.img.bpp, &mlxd.img.line_len, &mlxd.img.endian);

	

	mlxd.map.tab_2d = NULL;
	mlxd.map.x_len = 0;
	mlxd.map.y_len = 0;
	set_map(mlxd.map_path, &mlxd.map);
	print_map(mlxd.map);
	mlx_loop_hook(mlxd.mlx_ptr, &render, &mlxd);
	mlx_key_hook(mlxd.win_ptr, handle_input, &mlxd);
	mlx_loop(mlxd.mlx_ptr);
	// mlx_destroy_display(mlxd.mlx_ptr);
	free(mlxd.mlx_ptr);
	return (0);
}

/* int	main(void)
{
	t_map map;
	set_map("test_maps/20-60.fdf", &map);
} */
