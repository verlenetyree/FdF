/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:01:29 by vtyree            #+#    #+#             */
/*   Updated: 2022/02/23 19:52:43 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# define BUFFER_SIZE    42

char	*get_next_line(int fd);

size_t	gnl_ft_strlen(const char *s);
char	*gnl_ft_strdup(const char *s1);
char	*gnl_ft_strchr(const char *s, int c);
char	*gnl_ft_strjoin(char const *s1, char const *s2);
char	*gnl_ft_substr(char const *s, unsigned int start, size_t len);

#endif
