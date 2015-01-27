/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 02:37:38 by spochez           #+#    #+#             */
/*   Updated: 2015/01/27 12:08:52 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_base_convert(uintmax_t arg, char c)
{
	char		*bin;
	intmax_t	tp;
	int			nb;

	tp = 0;
	if (c == 'b')
		nb = 2;
	else if (c == 't')
		nb = 3;
	else
		nb = 8;
	while (arg > 0)
	{
		tp += (arg % nb);
		arg /= nb;
		if (arg > 0)
			tp *= 10;
	}
	bin = ft_maxtoa(tp);
	bin = ft_strrev(bin);
	return (bin);
}
