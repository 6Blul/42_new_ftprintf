/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 02:37:38 by spochez           #+#    #+#             */
/*   Updated: 2015/01/20 14:46:50 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_base_convert(uintmax_t arg, char c)
{
	char		*bin;
	intmax_t	tp;
	int			nb;

	if (c == 'b')
		nb = 2;
	else if (c == 't')
		nb = 3;
	else
		nb = 8;
	while (arg > 0)
	{
		tp = (arg % nb) + '0';
		arg /= nb;
		if (arg > 0)
			tp *= 10;
	}
	bin = ft_maxtoa(tp);
	return (bin);
}
