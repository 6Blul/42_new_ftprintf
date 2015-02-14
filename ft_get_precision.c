/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 09:48:19 by spochez           #+#    #+#             */
/*   Updated: 2015/01/21 09:52:49 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_wprecision(char *fmt)
{
	int		nb;
	int		isprec;

	isprec = 0;
	while (*fmt != '%')
		fmt--;
	while ((*fmt != 'c' || *fmt != 'C') && *fmt)
	{
		if (*fmt == '.')
			isprec = 1;
		fmt++;
	}
	if (isprec == 1)
	{
		while (*fmt != '.')
			fmt++;
		nb = ft_atoi(fmt);
	}
	else
		nb = -1;
	return (nb);
}
