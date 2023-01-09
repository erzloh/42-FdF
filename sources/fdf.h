/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eholzer <eholzer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:30:18 by eholzer           #+#    #+#             */
/*   Updated: 2023/01/09 14:06:33 by eholzer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"

// # define WIN_W 1366
// # define WIN_H 768
# define WIN_W 1920
# define WIN_H 1200
# define RAY_SIZE 50
# define TILE_WIDTH 4
# define TILE_HEIGHT 4
# define ORIGIN_X 50
# define ORIGIN_Y 500
# define ORIGIN_X_ISO 500
# define ORIGIN_Y_ISO 250
# define MOVE_DISTANCE 40
# define ZOOM_DISTANCE 2

// Key symbols
# define K_ESC 53
# define K_O 31
# define K_P 35
# define K_W 13
# define K_S 1
# define K_A 0
# define K_D 2
# define K_K 40
# define K_L 37
# define K_R 15
# define K_UP 126
# define K_DOWN 125
# define K_RIGHT 124
# define K_LEFT 123

// Colors
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define BLUE 0x021122

// Error numbers
# define OPEN_ERROR -1
# define CLOSE_ERROR -2
# define MALLOC_ERROR -3

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

typedef struct s_map
{
	int	**tab_2d;
	int	x_len;
	int	y_len;
}	t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		scaler;
	int		og_x;
	int		og_y;
	int		tile_w;
	int		tile_h;
	char	*map_path;
	t_map	map;
}	t_mlx;

typedef struct s_grid_data
{
	int	i;
	int	j;
	int	scaler;
}	t_grid_data;

typedef struct s_tab_x
{
	int		i;
	int		j;
	int		n_len;
	int		*tab;
	char	*tmp_str;
	int		size;
}	t_tab_x;

// Utils functions
int		abs(int n);
float	f_abs(float n);
void	ft_swap(int *a, int *b);
void	print_map(t_map map);

// Draw functions
void	draw_vertical_line(t_mlx mlxd, t_point p1, t_point p2);
void	draw_gentle_slope(t_mlx mlxd, t_point p1, t_point p2, t_line_data ld);
void	draw_steep_slope(t_mlx mlxd, t_point p1, t_point p2, t_line_data ld);
void	draw_line(t_mlx mlxd, t_point p1, t_point p2);

void	draw_grid_lines(t_mlx mlxd, t_map map, t_grid_data g);
void	draw_iso_grid(t_mlx mlxd, t_map map);
// void	draw_grid(t_mlx mlxd, t_map map);
// void	draw_point(t_mlx mlxd, t_point p, int color);

// Parsing functions
int		get_tab_x_size(char *line);
void	set_tab_x(char *line, t_tab_x *tab);
int		*get_tab_x(char *line);
int		get_tab_y_size(char *fdf_map);
int		**create_tab_2d(t_map *map, int fd);
int		set_map(char *map_path, t_map *map);

// Render functions
void	img_pix_put(t_img *img, int x, int y, int color);
int		render(t_mlx *mlxd);
void	render_background(t_img *img, int color);

// Input functions
int		handle_input(int key, t_mlx *mlxd);

#endif