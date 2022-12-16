/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:45:15 by eholzer           #+#    #+#             */
/*   Updated: 2022/12/16 16:35:31 by eholzer          ###   ########.fr       */
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

int	abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

float	f_abs(float n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	draw_line(void *mlx_ptr, void *win_ptr, t_point p1, t_point p2)
{
	t_point		p;
	t_line_data	ld;
	int			dx;
	int			dy;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	p.x = p1.x;
	p.y = p1.y;
	if (dx == 0) // Checks if the line is vertical
	{
		if (p2.y < p1.y)
			ft_swap(&p1.y, &p2.y);
		while (p1.y <= p2.y)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, p.x, p.y, 0xFFFFFF);
			p1.y++;
		}
		return ;
	}
	ld.slope = (float)dy / (float)dx;
	printf("ld.slope = %f\n", ld.slope);
	ld.offset = 0;
	ld.adjust = 1;
	if (ld.slope < 0)
		ld.adjust = -1;
	if (ld.slope <= 1 && ld.slope >= -1)
	{
		ld.slope = f_abs(ld.slope);
		if (p2.x < p1.x)
		{
			ft_swap(&p1.x, &p2.x);
			p.y = p2.y;
		}
		while (p.x <= p2.x)
		{
			printf("ld.offset = %f\n", ld.offset);
			printf("p.x = %d\n", p.x);
			printf("p.y = %d\n", p.y);
			mlx_pixel_put(mlx_ptr, win_ptr, p.x, p.y, 0xFFFFFF);
			ld.offset += ld.slope;
			if (ld.offset >= 0.5)
			{
				p.y += ld.adjust;
				ld.offset -= 1;
			}
			p.x++;
		}
	}
	else
	{
		ld.slope = 1 / ld.slope;
		if (p2.y < p1.y)
		{
			ft_swap(&p1.y, &p2.y);
			p.x = p2.x;
		}
		while (p.y < p2.y)
		{
			printf("ld.offset = %f\n", ld.offset);
			printf("p.x = %d\n", p.x);
			printf("p.y = %d\n", p.y);
			mlx_pixel_put(mlx_ptr, win_ptr, p.x, p.y, 0xFFFFFF);
			ld.offset += ld.slope;
			if (ld.offset >= 0.5)
			{
				p.x += ld.adjust;
				ld.offset -= 1;
			}
			p.y++;
		}
	}
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_point	p1;
	t_point	p2;

	p1.x = 0;
	p1.y = 0;
	p2.x = 500;
	p2.y = 50;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "FdF");
	draw_line(mlx_ptr, win_ptr, p1, p2);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}

/* int	main(void)
{
	float	a;

	a = 9.f / 4.f;
	printf("float = %f", a);
} */