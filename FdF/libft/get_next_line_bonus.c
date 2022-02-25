/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:01:34 by vtyree            #+#    #+#             */
/*   Updated: 2022/02/23 19:49:51 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_output(int fd, char **arr)
{
	char	*out;
	char	*temp;
	char	*next_line;

	next_line = gnl_ft_strchr(arr[fd], '\n');
	if (next_line)
	{
		out = gnl_ft_substr(arr[fd], 0, next_line - arr[fd]);
		temp = gnl_ft_strdup(next_line);
		free(arr[fd]);
		arr[fd] = temp;
	}
	else if (arr[fd][0] == 0)
	{
		free(arr[fd]);
		arr[fd] = NULL;
		out = NULL;
	}
	else
	{
		out = gnl_ft_strdup(arr[fd]);
		free(arr[fd]);
		arr[fd] = NULL;
	}
	return (out);
}

char	*get_next_line(int fd)
{
	static char		*arr[OPEN_MAX];
	char			buf[BUFFER_SIZE + 1];
	char			*temp;
	int				ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (arr[fd] == NULL)
			arr[fd] = gnl_ft_strdup("");
		temp = gnl_ft_strjoin(arr[fd], buf);
		free(arr[fd]);
		arr[fd] = temp;
		if (gnl_ft_strchr(buf, '\n'))
			break ;
		ret = read(fd, buf, BUFFER_SIZE);
	}
	if (arr[fd] == NULL)
		return (NULL);
	return (ft_output(fd, arr));
}
