/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 09:10:43 by spochez           #+#    #+#             */
/*   Updated: 2015/02/05 07:43:08 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_bef(char *put, char c)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 1;
	new = (char *)malloc(sizeof(char) * (ft_strlen(put) + 1) + 1);
	new[0] = c;
	while (put[i])
		new[j++] = put[i++];
	new[j] = 0;
	return (new);
}

char	*ft_sharpx(char *put, char c)
{
	char	*ret;
	int		j;
	int		i;

	i = 0;
	j = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(put) + 2) + 1);
	if (put[i] == ' ' || put[i] == '+')
	{
		ret[j] = put[i];
		i++;
		j++;
	}
	ret[j] = '0';
	ret[j + 1] = c;
	j += 2;
	while (put[i])
		ret[j++] = put[i++];
	ret[j] = 0;
	return (ret);
}

char	*ft_sharpo(char *put)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(put) + 1) + 1);
	if (put[i] == ' ' || put[i] == '+')
	{
		ret[j] = put[i];
		i++;
		j++;
	}
	ret[j] = '0';
	j++;
	while (put[i])
		ret[j++] = put[i++];
	ret[j] = 0;
	return (ret);
}

char	*ft_left_align(int nb, char *put)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (nb <= ft_strlen(put))
		return (put);
	res = (char *)malloc(sizeof(char) * (nb + 1));
	while (put[i])
		res[j++] = put[i++];
	while (j < nb)
	{
		res[j] = ' ';
		j++;
	}
	res[j] = 0;
	return (res);
}

char	*ft_align(char *put, char *fmt, char c, char type)
{
	char	*num;
	int		nb;
	int		j;

	j = 0;
	num = (char *)malloc(sizeof(char) * (ft_strlen(put) + 1));
	while (!ft_isdigit(*fmt))
		fmt = fmt + 1;
	while (ft_isdigit(*fmt))
	{
		num[j] = *fmt;
		j++;
		fmt++;
	}
	num[j] = 0;
	nb = ft_atoi(num);
	if (type == 'i' && nb <= ft_strlen(put))
		return (put);
	if (nb <= 0 || nb < (ft_strlen(put)))
		return (put);
	if (c == '0' || c == ' ')
		put = to_print(nb, put, c);
	else if (c == 'l')
		put = ft_left_align(nb, put);
	return (put);
}
