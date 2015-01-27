/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 10:37:42 by spochez           #+#    #+#             */
/*   Updated: 2015/01/27 12:41:59 by spochez          ###   ########.fr       */
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

	tab = (int *)malloc(sizeof(int) * 6);
	tab = fill_iflags(tab, copy, arg);
	if (*(fmt - 1) == '%' && !is_wchar(fmt))
		put = ft_maxtoa(arg);
	else if (is_wchar(fmt))
		return (ft_treat_wchar(fmt, (wchar_t)arg, tab, 0));
	else
	{
		while (is_let_flag(*fmt))
		{
			put = ft_i_conversions(arg, put, fmt);
			(*fmt)--;
		}
		if (tab[0] == 1)
			put = ft_treat_prec(put, fmt, 0);
		if (put)
			put = ft_i_sflags(put, tab, fmt);
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
	tab = fill_uiflags(tab, copy);
	if (*(fmt - 1) == '%')
		put = ft_insta_uint(arg, fmt);
	else
	{
		while (is_let_flag(*fmt))
		{
			put = ft_ui_conversions(arg, put, fmt);
			(*fmt)++;
		}
		if (tab[0] == 1)
			put = ft_treat_prec(put, fmt, tab[7]);
		if (put)
			put = ft_ui_sflags(put, tab, fmt);
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

	printf("cc\n");
	tab = (int *)malloc(sizeof(int) * 3);
	tab = fill_vflags(tab, copy);
	printf("cc1\n");
	while (*tab)
		printf("[%i]\n", *tab++);
	if (is_wstr(fmt))
		return (ft_treat_wstr(fmt, tab, (wchar_t *)arg));
	else if (*fmt == 'p')
		put = ft_convers_void(fmt, tab, (void *)arg);
	else
	{
		put = ft_strdup((char *)arg);
		if (*(fmt - 1) != '%')
		{
			if (tab[0] == 1)
				put = ft_treat_prec(put, fmt, 1);
			if (put)
				put = ft_v_sflags(put, tab, fmt);
		}
	}
	ft_putstr(put);
	return (ft_strlen(put));
}
