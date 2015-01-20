/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:40:30 by spochez           #+#    #+#             */
/*   Updated: 2015/01/20 08:06:32 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_is_other(char c)
{
	return (c == '\r' || c == '\v' || c == '\f');
}

static int		ft_is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static int		ft_sp(char c)
{
	return (ft_is_space(c) || ft_is_other(c));
}

int				ft_atoi(char *str)
{
	int	i;
	int	res;
	int	neg;

	i = 0;
	res = 0;
	neg = 0;
	while (ft_sp(str[i]) || (str[i] == '+' && ft_isdigit(str[i + 1])))
		i++;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res += (str[i] - '0');
		if (str[i + 1] && ft_isdigit(str[i + 1]))
			res *= 10;
		i++;
	}
	if (neg == 1)
		res *= -1;
	return (res);
}
