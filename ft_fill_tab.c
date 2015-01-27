/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 10:56:19 by spochez           #+#    #+#             */
/*   Updated: 2015/01/27 10:58:47 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		*fill_iflags(int *tab, char *fmt, intmax_t arg)
{
	ft_bzero(tab, 5);
	while (is_convers_flag(*fmt) == 0)
	{
		if (*fmt == '.')
			tab[0] = 1;
		if (*fmt == '+' && arg > 0)
			tab[1] = 1;
		if (*fmt == ' ' && arg > 0)
			tab[2] = 1;
		if (ft_isdigit(*fmt) && (*(fmt + 1)) != '.' && !ft_isdigit(*(fmt + 1)))
			tab[3] = 1;
		if (*fmt == '-')
			tab[4] = 1;
		if (*fmt == '0')
			tab[5] = 1;
		(*fmt)++;
	}
	if (tab[1] == 1 && tab[2] == 1)
		tab[2] = 0;
	if (tab[4] == 1 && tab[5] == 1)
		tab[5] = 0;
	return (tab);
}

int		*fill_uiflags(int *tab, char *fmt)
{
	ft_bzero(tab, 6);
	while (is_convers_flag(*fmt) == 0)
	{
		if (*fmt == '.')
			tab[0] = 1;
		if (*fmt == '+')
			tab[1] = 1;
		if (*fmt == ' ')
			tab[2] = 1;
		if (*fmt == '#')
			tab[3] = 1;
		if (ft_isdigit(*fmt) && (*(fmt + 1)) != '.' && !ft_isdigit(*(fmt + 1)))
			tab[4] = 1;
		if (*fmt == '-')
			tab[5] = 1;
		if (*fmt == '0')
			tab[6] = 1;
		(*fmt)++;
	}
	if (tab[1] == 1 && tab[2] == 1)
		tab[2] = 0;
	if (tab[5] == 1 && tab[6] == 1)
		tab[6] = 0;
	return (tab);
}

int		*fill_vflags(int *tab, char *fmt)
{
	ft_bzero(tab, 2);
	while (is_convers_flag(*fmt) == 0)
	{
		if (*fmt == '.')
			tab[0] = 1;
		if (ft_isdigit(*fmt) && (*(fmt + 1)) != '.' && !ft_isdigit(*(fmt + 1)))
			tab[1] = 1;
		if (*fmt == '-')
			tab[2] = 1;
		(*fmt)++;
	}
	return (tab);
}
