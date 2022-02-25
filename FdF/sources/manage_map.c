/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margaritasoldatkina <margaritasoldatkin    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:53:04 by y margarita       #+#    #+#             */
/*   Updated: 2022/02/25 07:47:21 by margaritaso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/fdf_key_macros.h"

void	manage_zoom(int key, t_fdf *params)
{
	mlx_destroy_image(params->mlx_ptr, params->mlx_img);
	if (key == PLUS_KEY)
	{
		params->map->xy_scale++;
		params->map->y_shift += 5;
		params->map->x_shift -= 10;
	}
	else
	{
		params->map->xy_scale--;
		params->map->y_shift -= 5;
		params->map->x_shift += 10;
	}
	if (params->map->xy_scale < 1)
	{
		params->map->xy_scale = 1;
	}
	draw_map(params->map, params);
	return ;
}

void	manage_move(int key, t_fdf *params)
{
	mlx_destroy_image(params->mlx_ptr, params->mlx_img);
	if (key == W_KEY)
	{
		params->map->y_shift += params->map->xy_scale;
		params->map->x_shift -= params->map->xy_scale;
	}
	if (key == A_KEY)
	{
		params->map->y_shift -= params->map->xy_scale;
		params->map->x_shift -= params->map->xy_scale;
	}
	if (key == D_KEY)
	{
		params->map->y_shift += params->map->xy_scale;
		params->map->x_shift += params->map->xy_scale;
	}
	if (key == S_KEY)
	{
		params->map->y_shift -= params->map->xy_scale;
		params->map->x_shift += params->map->xy_scale;
	}
	draw_map(params->map, params);
	return ;
}

void	manage_scale(int key, t_fdf *params)
{
	mlx_destroy_image(params->mlx_ptr, params->mlx_img);
	if (key == Q_KEY)
		params->map->z_scale++;
	else
		params->map->z_scale--;
	if (params->map->z_scale < 1)
		params->map->z_scale = 1;
	draw_map(params->map, params);
}

void	manage_projection(int key, t_fdf *params)
{
	mlx_destroy_image(params->mlx_ptr, params->mlx_img);
	if (key == ONE_KEY)
	{
		params->map->angle = TRUE_ISO;
	}
	if (key == TWO_KEY)
	{
		params->map->angle = ISO;
	}
	draw_map(params->map, params);
	return ;
}

int	manage_hook(int key, t_fdf *params)
{
	if (key == PLUS_KEY || key == MINUS_KEY)
		manage_zoom(key, params);
	if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY)
		manage_move(key, params);
	if (key == Q_KEY || key == E_KEY)
		manage_scale(key, params);
	if (key == ONE_KEY || key == TWO_KEY)
		manage_projection(key, params);
	if (key == ESC_KEY)
		close_map(params);
	return (0);
}
