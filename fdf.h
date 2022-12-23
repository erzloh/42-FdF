/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:30:18 by eholzer           #+#    #+#             */
/*   Updated: 2022/12/23 10:28:53 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"

# define WIN_W 1000
# define WIN_H 1000
# define RAY_SIZE 50
# define TILE_WIDTH 48
# define TILE_HEIGHT 36
# define ORIGIN_X 50
# define ORIGIN_Y 500
# define ORIGIN_X_ISO 500
# define ORIGIN_Y_ISO 250

// KEY SYMBOLS
# define K_ESC 53
# define K_O 31
# define K_P 35

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
	int		scaler;
}	t_mlx;

typedef struct s_map
{
	int	**tab_2d;
	int	x_len;
	int	y_len;
}	t_map;

typedef struct s_grid_data
{
	int	i;
	int	j;
	int	scaler;
}	t_grid_data;

// Utils functions
int		abs(int n);
float	f_abs(float n);
void	ft_swap(int *a, int *b);

// Draw functions
void	draw_line(t_mlx mlxd, t_point p1, t_point p2);
void	draw_grid(t_mlx mlxd, t_map map);
void	draw_iso_grid(t_mlx mlxd, t_map map);

// Parsing functions
int		get_tab_x_size(char *line);
int		*get_tab_x(char *line);
int		get_tab_y_size(char *fdf_map);
void	set_map(char *map_path, t_map *map);

#endif