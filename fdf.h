/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:30:18 by eholzer           #+#    #+#             */
/*   Updated: 2022/12/19 18:23:22 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"

# define WIN_W 500
# define WIN_H 500
# define RAY_SIZE 50
# define ORIGIN_X 50
# define ORIGIN_Y 50

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

#endif