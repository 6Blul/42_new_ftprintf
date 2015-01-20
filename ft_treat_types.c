/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 10:37:42 by spochez           #+#    #+#             */
/*   Updated: 2015/01/20 11:46:34 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_int(char *fmt, intmax_t arg)
{
	int		*tab;

	tab = (int *)malloc(sizeof(int) * 6);
	tab = fill_iflags(tab, fmt, arg);
}

int		ft_treat_uint(char *fmt, uintmax_t arg)
{
	int		*tab;

	tab = (int *)malloc(sizeof(int) * 7);
	tab = fill_uiflags(tab, fmt);
}

int		ft_treat_void(char *fmt, void *arg)
{
	int		*tab;

	tab = (int *)malloc(sizeof(int) * 3);
	tab = fill_vflags(tab, fmt);
}
