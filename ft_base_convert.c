/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 02:37:38 by spochez           #+#    #+#             */
/*   Updated: 2015/02/03 23:52:55 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_complete(char *bin)
{
	int		len;
	char	*tp;
	char 	*ret;

	len = ft_strlen(bin) + 1;
	ret = (char *)malloc(sizeof(char) * len + 1);
	tp = ret;
	while (*bin)
	{
		*tp = *bin;
		tp++;
		bin++;
	}
	*tp = '0';
	tp += 1;
	*tp = 0;
	return (ret);
}

int		define_conv(char c)
{
	if (c == 'b')
		return (2);
	else if (c == 't')
		return (3);
	else
		return (8);
}

char	*ft_base_convert(uintmax_t arg, char c)
{
	char		*bin;
	uintmax_t	tp;
	int			nb;
	int			add;

	add = 0;
	tp = 0;
	nb = define_conv(c);
	while (arg > 0)
	{
		tp += (arg % nb);
		if (arg % nb == 0)
			add = 1;
		arg /= nb;
		if (arg > 0)
			tp *= 10;
	}
	bin = ft_uinmaxtoa(tp);
	bin = ft_strrev(bin);
	if (add == 1)
		bin = ft_complete(bin);
	return (bin);
}
