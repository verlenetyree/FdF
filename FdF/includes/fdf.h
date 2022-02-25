/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margaritasoldatkina <margaritasoldatkin    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:25:05 by vtyree            #+#    #+#             */
/*   Updated: 2022/02/23 23:58:37 by margaritaso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef enum bool
{
	false,
	true
}	t_bool;

/* * * *
* 	Data types
*	x - horizontal; y - vertical
*/
# define BACKGROUND_COLOR 0x1d1d1d
# define DEFAULT_COLOR 0xf5f5f5
# define TRUE_ISO 0.523599
# define ISO 0.46373398
# define WIN_X 1000
# define WIN_Y 600

typedef struct fdf_value
{
	int		x;
	int		y;
	int		z_value;
	int		color;
}		t_value;

typedef struct fdf_map
{
	int			width;
	int			height;
	int			xy_scale;
	int			z_scale;
	int			x_shift;
	int			y_shift;
	double		angle;
	t_value		**value;
}				t_map;

typedef struct fdf_params
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map	*map;
}				t_fdf;

/* * * *
* 	FdF Utils
*/
t_bool	check_extension(const char *filename);
void	map_init(t_map *map);
void	free_t_array(int height, t_value **arr);
int		close_map(t_fdf *params);

/* * * *
* 	Read Map
*/
void	read_map(char *file_name, t_map *map);
void	get_params(char *file_name, t_map *map);
void	fill_values(int fd, t_value *value);

/* * * *
* 	Draw Map
*/
void	draw_map(t_map *map, t_fdf *params);
void	draw_background(t_fdf *params);
void	draw_line(t_value pnt0, t_value pnt1, t_fdf *params);
void	pixel_put(t_fdf *params, int x, int y, int color);

/* * * *
* 	Project Map
*/
t_value	map_project(t_map *map, t_value *pnt);

/* * * *
* 	Manage Map
*/
int		manage_hook(int key, t_fdf *params);
void	manage_zoom(int key, t_fdf *params);
void	manage_move(int key, t_fdf *params);
void	manage_scale(int key, t_fdf *params);
void	manage_projection(int key, t_fdf *params);

#endif
