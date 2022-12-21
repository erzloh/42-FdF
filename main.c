/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:45:15 by eholzer           #+#    #+#             */
/*   Updated: 2022/12/21 17:23:02 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, void *param)
{
	(void) key;
	(void) param;
	ft_printf("Hi");
	return (0);
}

int	main(void)
{
	t_mlx	mlxd;
	t_map	map;
	int		x = 0;
	int		y = 0;
	/* t_point	p1;
	t_point p2;

	p1.x = 24;
	p1.y = 28;
	p2.x = 0;
	p2.y = 0; */
	// ---------------------- test -----------------------------------
	map.tab_2d = NULL;
	map.x_len = 0;
	map.y_len = 0;
	set_map("test_maps/42.fdf", &map);
	printf("map.y_len = %d\n", map.y_len);
	printf("map.x_len = %d\n", map.x_len);
	while (y < map.y_len)
	{
		x = 0;
		while (x < map.x_len)
		{
			printf("%02d ", map.tab_2d[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}

	// ---------------------- test -----------------------------------

	mlxd.mlx_ptr = mlx_init();
	mlxd.win_ptr = mlx_new_window(mlxd.mlx_ptr, WIN_W, WIN_H, "FdF");
	// draw_line(mlxd, p1, p2);
	// draw_grid(mlxd, map);
	draw_iso_grid(mlxd, map);	
	//mlx_key_hook(mlxd.win_ptr, deal_key, (void *)0);
	mlx_loop(mlxd.mlx_ptr);
}

/* int	main(void)
{
	float	a;

	a = 9.f / 4.f;
	printf("float = %f", a);
} */
