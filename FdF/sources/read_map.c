/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:53:18 by vtyree            #+#    #+#             */
/*   Updated: 2022/02/23 19:29:05 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/fdf_errors.h"

static void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return ;
}

void	fill_values(int fd, t_value *value)
{
	static int	j;
	int			i;
	char		*line;
	char		*color;
	char		**array;

	line = get_next_line(fd);
	array = ft_split(line, ' ');
	free(line);
	i = 0;
	while (array[i])
	{
		value[i].y = j;
		value[i].x = i;
		value[i].z_value = ft_atoi(array[i]);
		color = ft_strrchr(array[i], 'x');
		if (color)
			value[i].color = ft_atoi_base(++color, 16);
		else
			value[i].color = DEFAULT_COLOR;
		i++;
	}
	free_array(array);
	j++;
	return ;
}

static int	get_width(char *line, char sp)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	if (line == NULL)
		return (0);
	while (line[i])
	{
		while (line[i] == sp)
			i++;
		if (line[i] != sp && line[i])
			width++;
		while (line[i] != sp && line[i])
			i++;
	}
	return (width);
}

void	get_params(char *file_name, t_map *map)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_handler(ERROR_OPEN);
	line = get_next_line(fd);
	map->width = get_width(line, ' ');
	height = 0;
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	map->height = height;
	free(line);
	close(fd);
	return ;
}

void	read_map(char *file_name, t_map *map)
{
	int		i;
	int		fd;

	get_params(file_name, map);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_handler(ERROR_OPEN);
	map->value = (t_value **)malloc(sizeof(t_value *) * (map->height));
	if (!map->value)
		error_handler(ERROR_MALLOC);
	i = 0;
	while (i < map->height)
	{
		map->value[i] = (t_value *)malloc(sizeof(t_value) * (map->width));
		if (!map->value[i])
			error_handler(ERROR_MALLOC);
		fill_values(fd, map->value[i]);
		i++;
	}
	close(fd);
	return ;
}
