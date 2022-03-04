/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:59:06 by vtyree            #+#    #+#             */
/*   Updated: 2022/03/03 11:37:15 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/fdf_errors.h"

void	free_t_array(int height, t_value **arr)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return ;
}

int	close_map(t_fdf *params)
{
	mlx_destroy_window(params->mlx_ptr, params->mlx_win);
	free_t_array(params->map->height, params->map->value);
	exit(0);
}

void	draw_background(t_fdf *params)
{
	int	i;
	int	*image;

	i = 0;
	image = (int *)(params->addr);
	while (i < (WIN_Y * WIN_X))
	{
		image[i] = BACKGROUND_COLOR;
		i++;
	}
	return ;
}

t_bool	check_extension(const char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (!ext)
		return (false);
	if (!ft_strncmp(ext, ".fdf", 4))
		return (true);
	return (false);
}

void	error_handler(const char *message)
{
	if (errno == 0)
	{
		ft_putendl_fd((char *)message, 2);
	}
	else
		perror(message);
	exit(EXIT_FAILURE);
}
