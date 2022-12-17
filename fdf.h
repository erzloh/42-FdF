/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:30:18 by eholzer           #+#    #+#             */
/*   Updated: 2022/12/17 11:32:51 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"

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

// Draw functions
void	draw_line(t_mlx mlxd, t_point p1, t_point p2);

// Utils functions
int		abs(int n);
float	f_abs(float n);
void	ft_swap(int *a, int *b);

#endif