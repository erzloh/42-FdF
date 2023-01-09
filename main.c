/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:45:15 by eholzer           #+#    #+#             */
/*   Updated: 2023/01/09 11:43:46 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_mlxd(t_mlx *mlxd, char **av)
{
	mlxd->mlx_ptr = mlx_init();
	if (!mlxd->mlx_ptr)
		return (1);
	mlxd->win_ptr = mlx_new_window(mlxd->mlx_ptr, WIN_W, WIN_H, "FdF");
	if (!mlxd->win_ptr)
		return (1);
	mlxd->scaler = 2;
	mlxd->og_x = 500;
	mlxd->og_y = 250;
	mlxd->tile_w = TILE_WIDTH;
	mlxd->tile_h = TILE_HEIGHT;
	mlxd->map_path = av[1];
	mlxd->img.mlx_img = mlx_new_image(mlxd->mlx_ptr, WIN_W, WIN_H);
	mlxd->img.addr = mlx_get_data_addr(mlxd->img.mlx_img,
			&mlxd->img.bpp, &mlxd->img.line_len, &mlxd->img.endian);
	mlxd->map.tab_2d = NULL;
	mlxd->map.x_len = 0;
	mlxd->map.y_len = 0;
	return (0);
}

int	handle_map_errors(int map_error)
{
	if (map_error == OPEN_ERROR)
	{
		ft_printf("An error occured when the file was being opened.\n");
		return (1);
	}
	else if (map_error == CLOSE_ERROR)
	{
		ft_printf("An error occured when the file was being closed.\n");
		return (1);
	}
	else if (map_error == MALLOC_ERROR)
	{
		ft_printf("An error occured when trying to ");
		ft_printf("malloc an array of the map.\n");
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlxd;
	int		map_error;

	if (ac != 2)
	{
		ft_printf("Error: you must enter one argument.");
		return (1);
	}
	if (init_mlxd(&mlxd, av) == 1)
		return (1);
	map_error = set_map(mlxd.map_path, &mlxd.map);
	handle_map_errors(map_error);
	mlx_loop_hook(mlxd.mlx_ptr, &render, &mlxd);
	mlx_key_hook(mlxd.win_ptr, handle_input, &mlxd);
	mlx_loop(mlxd.mlx_ptr);
	free(mlxd.mlx_ptr);
	return (0);
}

/* int	main(void)
{
	t_map map;
	set_map("test_maps/20-60.fdf", &map);
} */
