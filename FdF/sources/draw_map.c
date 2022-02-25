/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:20:09 by margaritaso       #+#    #+#             */
/*   Updated: 2022/02/23 19:44:38 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* * * * * * * *
*
*	Bresenham's line algorithm
*
*	(x0, y0) - start coordinate; (x1, y1) - finish coordinate;
*
*	(y - y0)/(y1 - y0) = (x - x0)/(x1 - x0)
*	y = ((y1 - y0))/(x1 - x0)) * (x - x0) + y0
*
*	s - slope
*	s = (y2 - y1) / (x2 - x1)
*
* * * * */

void	pixel_put(t_fdf *params, int x, int y, int color)
{
	int	i;

	i = 0;
	if (x < WIN_X && y < WIN_Y && x > 0)
	{
		i = y * params->line_length + x * (params->bits_per_pixel / 8);
		params->addr[i] = color;
		params->addr[++i] = color >> 8;
		params->addr[++i] = color >> 16;
	}
	return ;
}

static void	get_delta_sign(t_value pnt0, t_value pnt1, int *sign, int *delta)
{
	delta[0] = ft_abs(pnt1.x - pnt0.x);
	delta[1] = ft_abs(pnt1.y - pnt0.y);
	if (pnt0.x < pnt1.x)
		sign[0] = 1;
	else
		sign[0] = -1;
	if (pnt0.y < pnt1.y)
		sign[1] = 1;
	else
		sign[1] = -1;
	return ;
}

void	draw_line(t_value pnt0, t_value pnt1, t_fdf *params)
{
	int	d[2];
	int	sign[2];
	int	err[2];
	int	xy[2];

	get_delta_sign(pnt0, pnt1, sign, d);
	err[0] = d[0] - d[1];
	xy[0] = pnt0.x;
	xy[1] = pnt0.y;
	pixel_put(params, pnt1.x, pnt1.y, pnt1.color);
	while (xy[0] != pnt1.x || xy[1] != pnt1.y)
	{
		pixel_put(params, xy[0], xy[1], pnt1.color);
		err[1] = err[0] * 2;
		if (err[1] > -d[1])
		{
			err[0] -= d[1];
			xy[0] += sign[0];
		}
		if (err[1] < d[0])
		{
			err[0] += d[0];
			xy[1] += sign[1];
		}
	}
}

static void	image_initialize(t_fdf *params)
{
	params->mlx_img = mlx_new_image(params->mlx_ptr, WIN_X, WIN_Y);
	params->addr = mlx_get_data_addr(params->mlx_img, &params->bits_per_pixel, \
		&params->line_length, &params->endian);
	draw_background(params);
	return ;
}

void	draw_map(t_map *map, t_fdf *params)
{
	int	i;
	int	j;

	i = 0;
	image_initialize(params);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (i != map->height - 1)
				draw_line(map_project(map, &map->value[i][j]), \
					map_project(map, &map->value[i + 1][j]), params);
			if (j != map->width - 1)
				draw_line(map_project(map, &map->value[i][j]), \
				map_project(map, &map->value[i][j + 1]), params);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(params->mlx_img, params->mlx_win, \
		params->mlx_img, 0, 0);
	return ;
}
