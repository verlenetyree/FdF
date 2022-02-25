/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margaritasoldatkina <margaritasoldatkin    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:37:57 by vtyree            #+#    #+#             */
/*   Updated: 2022/02/24 00:11:29 by margaritaso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/fdf_errors.h"
#include "../includes/fdf_key_macros.h"

void	map_init(t_map *map)
{
	map->angle = ISO;
	map->z_scale = 1;
	map->xy_scale = WIN_X / map->width / 1.5;
	map->x_shift = WIN_X / 3.5;
	map->y_shift = WIN_Y / 4.8;
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
