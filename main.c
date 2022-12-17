/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:45:15 by eholzer           #+#    #+#             */
/*   Updated: 2022/12/17 14:54:25 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Draw a grid
void	draw_grid(t_mlx mlxd, char **map)
{
	int		i;
	int		j;
	t_point	p1;
	t_point	p2;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			p1.x = ORIGIN_X + (i * RAY_SIZE);
			p1.y = ORIGIN_Y + (j * RAY_SIZE);
			if (map[j][i + 1])
			{
				p2.x = p1.x + RAY_SIZE;
				p2.y = p1.y;
				draw_line(mlxd, p1, p2);
			}
			if (map[j + 1] && map[j + 1][i])
			{
				p2.x = p1.x;
				p2.y = p1.y + RAY_SIZE;
				draw_line(mlxd, p1, p2);
			}
			i++;
		}
		j++;
	}
}

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