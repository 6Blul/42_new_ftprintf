/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 02:37:38 by spochez           #+#    #+#             */
/*   Updated: 2015/02/14 13:29:44 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_complete(char *bin)
{
	int		len;
	char	*tp;
	char	*ret;

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
	if (c == 'b' || c == 'P')
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

	if (arg == 0)
		return (ft_arg_is_zero());
	add = 0;
	tp = 0;
	nb = define_conv(c);
	if (arg % nb == 0 && c != 'P')
		add = 1;
	while (arg > 0)
	{
		tp += (arg % nb);
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

int		ft_power(int nb, int power)
{
	int		tp;

	tp = nb;
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	while (power != 1)
	{
		tp *= nb;
		power--;
	}
	return (tp);
}

int		ft_binary_to_dec(char *pd)
{
	int		gropd;
	int		q;
	int		zhonya;

	gropd = 0;
	zhonya = 0;
	q = (ft_strlen(pd) - 1);
	while (q >= 0)
	{
		if (pd[q] == '1')
			gropd += ft_power(2, zhonya);
		zhonya++;
		q--;
	}
	return (gropd);
}
