/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:45:15 by eholzer           #+#    #+#             */
/*   Updated: 2022/12/20 14:27:23 by eholzer          ###   ########.fr       */
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
	char	*test;
	int		*tab_x;
	int		tab_size;
	int		i;

	// ---------------------- test -----------------------------------
	test = "0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0";
	tab_size = get_tab_size(test);
	printf("size: %d\n", tab_size);
	tab_x = get_tab_x(test);
	i = 0;
	while (i < tab_size)
	{
		printf("tab_x[%d] = %d\n", i, tab_x[i]);
		i++;
	}
	// ---------------------- test -----------------------------------

	map = ft_split("0000 0100 0000", ' ');
	p1.x = 250;
	p1.y = 0;
	p2.x = 50;
	p2.y = 30;
	mlxd.mlx_ptr = mlx_init();
	mlxd.win_ptr = mlx_new_window(mlxd.mlx_ptr, WIN_W, WIN_H, "FdF");
	//  draw_line(mlxd, p1, p2);
	draw_grid(mlxd, map);
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