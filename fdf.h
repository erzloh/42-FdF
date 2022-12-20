/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:30:18 by eholzer           #+#    #+#             */
/*   Updated: 2022/12/20 10:37:47 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"

# define WIN_W 1000
# define WIN_H 1000
# define RAY_SIZE 50
# define TILE_WIDTH 100
# define TILE_HEIGHT 50
# define ORIGIN_X 50
# define ORIGIN_Y 50
# define ORIGIN_X_ISO (WIN_W / 2)
# define ORIGIN_Y_ISO 50

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_line_data
{
	float	offset;
	float	slope;
	int		sign;
	int		dx;
	int		dy;
}	t_line_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

// Utils functions
int		abs(int n);
float	f_abs(float n);
void	ft_swap(int *a, int *b);

// Draw functions
void	draw_line(t_mlx mlxd, t_point p1, t_point p2);
void	draw_grid(t_mlx mlxd, char **map);
void	draw_iso_grid(t_mlx mlxd, char **map);

#endif