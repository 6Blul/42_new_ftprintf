/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 10:37:42 by spochez           #+#    #+#             */
/*   Updated: 2015/02/05 07:12:53 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_wchar(char *c)
{
	return (*c == 'C' || (*c == 'c' && *(c - 1) == 'l'));
}

int		is_wstr(char *c)
{
	return (*c == 'S' || (*c == 's' && *(c - 1) == 'l'));
}

int		ft_treat_int(char *fmt, intmax_t arg, char *copy)
{
	int		*tab;
	char	*put;

	tab = (int *)malloc(sizeof(int) * 7);
	tab = fill_iflags(tab, copy, (int)arg);
	if (is_wchar(fmt))
		return (ft_treat_wchar(fmt, (wchar_t)arg, tab, 0));
	if (*fmt == 'c')
		put = ft_get_char((arg));
	else
		put = ft_maxtoa(arg);
	if (*(fmt - 1) != '%')
	{
		put = ft_i_conversions(arg, put, fmt - 1);
		while (is_let_flag(*fmt) || is_sign_flag(*fmt))
			fmt--;
		if (tab[0] == 1)
			put = ft_treat_prec(put, copy, 0, tab[6]);
		if (put)
			put = ft_i_sflags(put, tab, copy);
		else
			return (0);
	}
	ft_putstr(put);
	return (ft_strlen(put));
}

int		ft_treat_uint(char *fmt, uintmax_t arg, char *copy)
{
	int		*tab;
	char	*put;

	tab = (int *)malloc(sizeof(int) * 8);
	if (*fmt == 'x' || *fmt == 'X' || *fmt == 'o' || *fmt == 'O')
		tab[7] = 2;
	tab = fill_uiflags(tab, copy, (unsigned int)arg);
	put = ft_insta_uint(arg, fmt);
	if (*(fmt - 1) != '%')
	{
		put = ft_ui_conversions(arg, put, fmt - 1);
		while (is_let_flag(*fmt))
			fmt--;
		if (tab[0] == 1)
			put = ft_treat_prec(put, copy, 0, 0);
		if (put)
			put = ft_ui_sflags(put, tab, copy);
		else
			return (0);
	}
	ft_putstr(put);
	return (ft_strlen(put));
}

int		ft_treat_void(char *fmt, void *arg, char *copy)
{
	int		*tab;
	char	*put;

	tab = (int *)malloc(sizeof(int) * 3);
	tab = fill_vflags(tab, copy);
	if (is_wstr(fmt))
		return (ft_treat_wstr(fmt, tab, (wchar_t *)arg));
	else if (*fmt == 'p')
		put = ft_convers_void(copy, tab, (void *)arg);
	else
	{
		put = ft_strdup((char *)arg);
		if (*(fmt - 1) != '%')
		{
			if (tab[0] == 1)
				put = ft_treat_prec(put, copy, 1, 0);
			if (put)
				put = ft_v_sflags(put, tab, fmt);
		}
	}
	ft_putstr(put);
	return (ft_strlen(put));
}
