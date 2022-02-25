/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margaritasoldatkina <margaritasoldatkin    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:23:46 by margaritaso       #+#    #+#             */
/*   Updated: 2022/02/10 23:13:18 by margaritaso      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*gnl_ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = gnl_ft_strlen(s1);
	copy = malloc(sizeof(char) * len + 1);
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < len && s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*gnl_ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;
	size_t	j;

	i = 0;
	j = start;
	if (s == NULL)
		return (NULL);
	if (start > gnl_ft_strlen(s))
		return (gnl_ft_strdup(""));
	if (gnl_ft_strlen(s + start) < len)
		len = gnl_ft_strlen(s + start);
	out = (char *)malloc(sizeof(char) * (len + 1));
	if (out == NULL)
		return (NULL);
	while (i < len && s[j] != '\0')
	{
		out[i++] = s[j++];
	}
	out[i] = '\0';
	return (out);
}

char	*gnl_ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i + 1);
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

char	*gnl_ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = gnl_ft_strlen(s1);
	len2 = gnl_ft_strlen(s2);
	out = (char *)malloc(sizeof(char) * ((len1 + len2) + 1));
	if (out == NULL)
		return (NULL);
	while (i < len1 + len2)
	{
		if (i < len1)
			out[i] = s1[i];
		else
			out[i] = s2[j++];
		i++;
	}
	out[i] = '\0';
	return (out);
}
