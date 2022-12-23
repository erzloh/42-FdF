/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:30:18 by eholzer           #+#    #+#             */
/*   Updated: 2022/12/23 14:57:15 by eholzer          ###   ########.fr       */
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
# define MOVE_DISTANCE 10

// Key symbols
# define K_ESC 53
# define K_O 31
# define K_P 35
# define K_W 13
# define K_S 1
# define K_A 0
# define K_D 2

// Colors
# define WHITE 0xFFFFFF
# define BLACK 0x000000

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

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		scaler;
	t_img	img;
	int		og_x;
	int		og_y;
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

// Render functions
void	img_pix_put(t_img *img, int x, int y, int color);
int		render(t_mlx *mlxd);
void	render_background(t_img *img, int color);

// Input functions
int		handle_input(int key, t_mlx *mlxd);

#endif