/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 02:37:38 by spochez           #+#    #+#             */
/*   Updated: 2015/02/02 08:05:54 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	tp = 0;
	nb = define_conv(c);
	while (arg > 0)
	{
		tp += (arg % nb);
		arg /= nb;
		if (arg > 0)
			tp *= 10;
	}
	bin = ft_uinmaxtoa(tp);
	bin = ft_strrev(bin);
	return (bin);
}
