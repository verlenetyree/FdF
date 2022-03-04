/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margaritasoldatkina <margaritasoldatkin    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:37:57 by vtyree            #+#    #+#             */
/*   Updated: 2022/02/28 04:33:13 by margaritaso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/fdf_errors.h"
#include "../includes/fdf_key_macros.h"

void	map_init(t_map *map)
{
	map->angle = ISO;
	map->z_scale = 1;
	if (WIN_X / map->width / 2 > WIN_Y / map->height / 2)
		map->xy_scale = WIN_X / map->width / 1.6;
	else
		map->xy_scale = WIN_Y / map->height / 1.6;
	map->x_shift = 0;
	map->y_shift = 0;
	map->alpha = 0;
	map->beta = 0;
	return ;
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_fdf	params;

	if (argc == 2)
	{
		if (check_extension(argv[1]))
		{
			read_map(argv[1], &map);
			map_init(&map);
			params.map = &map;
			params.mlx_ptr = mlx_init();
			params.mlx_win = mlx_new_window(params.mlx_ptr, \
				WIN_X, WIN_Y, "fdf");
			draw_map(&map, &params);
			mlx_key_hook(params.mlx_win, &manage_hook, &params);
			mlx_hook(params.mlx_win, ON_DESTROY, 0, &close_map, &params);
			mlx_loop(params.mlx_ptr);
		}
		else
			error_handler(WRONG_EXT);
	}
	else
		error_handler(WRONG_ARGS);
	return (0);
}
