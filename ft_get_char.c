/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 03:01:52 by spochez           #+#    #+#             */
/*   Updated: 2015/01/29 03:06:59 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_char(char arg, char *fmt, int *tab)
{
	char	*put;

	put = (char *)malloc(sizeof(char) * 2);
	if (arg == 0)
	{
		ft_bzero(put, '2');
		return (1);
	}
	put[0] = arg;
	put[1] = 0;
	while (*(fmt - 1) != '%')
		fmt--;
	if (tab[4] == 1)
		put = ft_align(put, fmt, 'l', 'c');
	else if (tab[3] == 1)
		put = ft_align(put, fmt, ' ', 'c');
	ft_putstr(put);
	return (ft_strlen(put));
}
