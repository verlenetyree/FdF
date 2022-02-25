/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtyree <vtyree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 22:18:10 by margaritaso       #+#    #+#             */
/*   Updated: 2022/02/23 19:46:51 by vtyree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || \
		c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	nbase(int c, int base)
{
	char	*str_base;
	char	*str_base2;
	int		i;

	i = 0;
	str_base = "0123456789abcdef";
	str_base2 = "0123456789ABCDEF";
	while (i < base)
	{
		if (c == str_base[i] || c == str_base2[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int base)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	sign = 1;
	n = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] && nbase(str[i], base) != -1)
	{
		n = (n * base) + nbase(str[i], base);
		i++;
	}
	return (sign * n);
}
