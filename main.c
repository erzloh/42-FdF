/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:45:15 by eholzer           #+#    #+#             */
/*   Updated: 2022/12/19 18:23:28 by eric             ###   ########.fr       */
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
	t_point	p1;
	t_point	p2;
	char	**map;

	map = ft_split("000 010 000", ' ');
	p1.x = 0;
	p1.y = 0;
	p2.x = 50;
	p2.y = 30;
	mlxd.mlx_ptr = mlx_init();
	mlxd.win_ptr = mlx_new_window(mlxd.mlx_ptr, WIN_W, WIN_H, "FdF");
	draw_line(mlxd, p1, p2);
	draw_grid(mlxd, map);
	//mlx_key_hook(mlxd.win_ptr, deal_key, (void *)0);
	mlx_loop(mlxd.mlx_ptr);
}

/* int	main(void)
{
	float	a;

	a = 9.f / 4.f;
	printf("float = %f", a);
} */