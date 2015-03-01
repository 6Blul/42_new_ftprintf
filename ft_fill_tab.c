/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 10:56:19 by spochez           #+#    #+#             */
/*   Updated: 2015/02/05 06:41:21 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_lm(char *fmt)
{
	int		dot;

	dot = 0;
	while (*fmt != '%')
	{
		if (*fmt == '.')
			dot = 1;
		fmt--;
	}
	if (dot == 1)
	{
		while (*fmt != '.')
			fmt++;
		if (ft_isdigit(*(fmt - 1)))
			return (1);
	}
	else
	{
		while (is_convers_flag(*(fmt++)) == 0)
		{
			if (ft_isdigit(*fmt))
				return (1);
		}
	}
	return (0);
}

int		*fill_iflags(int *tab, char *fmt, int arg)
{
	ft_bzero(tab, 6);
	while (is_convers_flag(*(fmt++)) == 0)
	{
		if (*fmt == '.')
			tab[0] = 1;
		if (*fmt == '+' && arg >= 0)
			tab[1] = 1;
		if (*fmt == ' ' && arg >= 0)
			tab[2] = 1;
		if (*fmt == '-')
			tab[4] = 1;
		if (*fmt == '0' && !ft_isdigit(*(fmt - 1)) && tab[0] == 0)
			tab[5] = 1;
	}
	if (tab[1] == 1 && tab[2] == 1)
		tab[2] = 0;
	if (tab[4] == 1 && tab[5] == 1)
		tab[5] = 0;
	if (arg < 0)
		tab[6] = 1;
	tab[3] = is_lm(fmt);
	return (tab);
}

int		*fill_uiflags(int *tab, char *fmt, unsigned int arg)
{
	ft_bzero(tab, 6);
	while (is_convers_flag(*(fmt++)) == 0)
	{
		if (*fmt == '.')
			tab[0] = 1;
		if (*fmt == '#' && arg >= 1)
			tab[3] = 1;
		if (*fmt == '-')
			tab[5] = 1;
		if (*fmt == '0' && !ft_isdigit(*(fmt - 1)) && tab[0] == 0)
			tab[6] = 1;
	}
	tab[4] = is_lm(fmt);
	if (tab[5] == 1 && tab[6] == 1)
		tab[6] = 0;
	return (tab);
}

int		*fill_vflags(int *tab, char *fmt)
{
	ft_bzero(tab, 2);
	while (is_convers_flag(*(fmt++)) == 0)
	{
		if (*fmt == '.')
			tab[0] = 1;
		if (*fmt == '-')
			tab[2] = 1;
	}
	tab[1] = is_lm(fmt);
	return (tab);
}
