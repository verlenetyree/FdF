/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margaritasoldatkina <margaritasoldatkin    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 02:28:37 by margaritaso       #+#    #+#             */
/*   Updated: 2022/02/23 23:49:31 by margaritaso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_value	map_project(t_map *map, t_value *pnt)
{
	int		i;
	int		j;
	t_value	pnt_proj;

	j = (pnt->x * map->xy_scale) + map->x_shift;
	i = (pnt->y * map->xy_scale) - map->y_shift;
	if (map->angle == ISO || map->angle == TRUE_ISO)
	{
		pnt_proj.x = ((j - i) * cos(map->angle));
		pnt_proj.y = (-pnt->z_value * map->z_scale) + (j + i) * sin(map->angle);
	}
	pnt_proj.color = pnt->color;
	return (pnt_proj);
}
