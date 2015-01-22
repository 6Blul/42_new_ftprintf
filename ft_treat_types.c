/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 10:37:42 by spochez           #+#    #+#             */
/*   Updated: 2015/01/22 05:30:51 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_wchar(char *c)
{
	return (*c == 'C' || (*c == 'c' && *c - 1 == 'l'));
}

int		is_wstr(char *c)
{
	return (*c == 'S' || (*c == 's' && *c - 1 == 'l'));
}

int		ft_treat_int(char *fmt, intmax_t arg)
{
	int		*tab;

	tab = (int *)malloc(sizeof(int) * 6);
	tab = fill_iflags(tab, fmt, arg);
	if (*fmt - 1 == '%' && !is_wchar(fmt))
		put = ft_maxtoa(arg);
	else if (is_wchar(fmt))
		return (ft_treat_wchar(*fmt, (wchar_t)arg, tab, 0));
	else
	{
		while (is_let_flag(*fmt))
		{
			put = ft_i_conversions(arg, put, fmt);
			*fmt--;
		}
		if (tab[0] == 1)
			put = ft_troncate(put, fmt);
		if (put)
			put = ft_i_sflags(put, tab, fmt);
		else
			return (0);
	}
	ft_putstr(put);
	return (ft_strlen(put));
}

int		ft_treat_uint(char *fmt, uintmax_t arg)
{
	int		*tab;
	char	*put;

	tab = (int *)malloc(sizeof(int) * 7);
	tab = fill_uiflags(tab, fmt);
	if (*fmt - 1 == '%')
		put = ft_uintmaxtoa(arg);
	else
	{
		while (is_let_flag(*fmt))
		{
			put = ft_ui_conversions(arg, put, fmt);
			*fmt--;
		}
		if (tab[0] == 1)
			put = ft_troncate(put, fmt);
		if (put)
			put = ft_ui_sflags(arg, put, tab, fmt);
		else
			return (0);
	}
	ft_putstr(put);
	return (ft_strlen(put));
}

int		ft_treat_void(char *fmt, void *arg)
{
	int		*tab;

	tab = (int *)malloc(sizeof(int) * 3);
	tab = fill_vflags(tab, fmt);
	if (is_wstr(fmt))
		return (ft_treat_wstr(fmt, tab, (wchar_t *)arg));
	else if (*fmt == 'p')
		ft_treat_void(fmt, tab, (void *)arg);
	// Ou si void -> traiter void (return dans put)
	else
	{
		put = ft_strdup((char *)arg);
		if (*fmt - 1 != '%')
		{
			if (tab[0] == 1)
				put = ft_troncate(put, fmt);
			if (put)
				put = ft_v_sflags(put, tab, fmt);
		}
	}
	ft_putstr(put);
	return (ft_strlen(put));
}
