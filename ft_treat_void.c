/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_void.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 19:37:43 by spochez           #+#    #+#             */
/*   Updated: 2015/02/05 06:49:55 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convers_void(char *fmt, int *tab, void *arg)
{
	uintmax_t	addr;
	char		*put;

	addr = (uintmax_t)arg;
	put = ft_hexa(addr, 'x');
	if (tab[0] == 1)
		put = ft_treat_prec(put, fmt, 0, 0);
	put = ft_sharpx(put, 'x');
	if (tab[1] == 1)
	{
		if (tab[2] == 1)
			put = ft_align(put, fmt, 'l', 'v');
		else
			put = ft_align(put, fmt, ' ', 'v');
	}
	return (put);
}
