/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 02:28:37 by margaritaso       #+#    #+#             */
/*   Updated: 2022/03/03 11:30:46 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/fdf_key_macros.h"

void	map_rotation(int *x, int *y, int *z, t_map *map)
{
	int	x_old;
	int	y_old;
	int	z_old;

	x_old = *x;
	y_old = *y;
	z_old = *z;
	*x = x_old * cos(map->alpha) - y_old * sin(map->alpha);
	*y = x_old * sin(map->alpha) + y_old * cos(map->alpha);
	x_old = *x;
	*x = x_old * cos(map->beta) - z_old * sin(map->beta);
	*z = x_old * sin(map->beta) + z_old * cos(map->beta);
}

t_value	map_project(t_map *map, t_value *pnt)
{
	int		i;
	int		j;
	int		z;
	t_value	pnt_proj;

	j = (pnt->x * map->xy_scale) - ((map->width * map->xy_scale) / 2);
	i = (pnt->y * map->xy_scale) - ((map->height * map->xy_scale) / 2);
	z = pnt->z_value * map->z_scale;
	map_rotation(&j, &i, &z, map);
	if (map->angle == ISO || map->angle == TRUE_ISO)
	{
		pnt_proj.x = ((j - i) * cos(map->angle));
		pnt_proj.y = ((-z) + (j + i) * sin(map->angle));
	}
	pnt_proj.x += WIN_X / 2 + map->x_shift;
	pnt_proj.y += WIN_Y / 2 + ((map->height / 4) * map->xy_scale) \
		/ 2 + map->y_shift;
	pnt_proj.color = pnt->color;
	return (pnt_proj);
}

void	manage_rotation(int key, t_fdf *params)
{
	mlx_destroy_image(params->mlx_ptr, params->mlx_img);
	if (key == L_ARROW)
		params->map->alpha -= 0.1;
	if (key == R_ARROW)
		params->map->alpha += 0.1;
	if (key == D_ARROW)
		params->map->beta -= 0.1;
	if (key == U_ARROW)
		params->map->beta += 0.1;
	draw_map(params->map, params);
	return ;
}
