/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:50:51 by spochez           #+#    #+#             */
/*   Updated: 2015/02/05 06:47:59 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_i_sflags(char *put, int *tab, char *fmt)
{
	if (tab[1] == 1)
		put = ft_add_bef(put, '+');
	else if (tab[2] == 1)
		put = ft_add_bef(put, ' ');
	if (tab[3] == 1)
	{
		if (tab[4] == 1)
			put = ft_align(put, fmt, 'l', 'i');
		else if (tab[5] == 1)
			put = ft_align(put, fmt, '0', 'i');
		else
			put = ft_align(put, fmt, ' ', 'i');
	}
	return (put);
}

char	*ft_ui_sflags(char *put, int *tab, char *fmt)
{
	char	*temp;

	temp = fmt;
	while (is_convers_flag(*temp) != 2)
		temp++;
	if (tab[1] == 1)
		put = ft_add_bef(put, '+');
	else if (tab[2] == 1)
		put = ft_add_bef(put, ' ');
	if (tab[3] == 1 && (*temp == 'o' || *temp == 'O'))
		put = ft_sharpo(put);
	if (tab[3] == 1 && (*temp == 'x' || *temp == 'X'))
		put = ft_sharpx(put);
	if (tab[4] == 1)
	{
		if (tab[5] == 1)
			put = ft_align(put, fmt, 'l', 'i');
		else if (tab[6] == 1)
			put = ft_align(put, fmt, '0', 'i');
		else
			put = ft_align(put, fmt, ' ', 'i');
	}
	return (put);
}

char	*ft_v_sflags(char *put, int *tab, char *fmt)
{
	while (*(fmt--) != '%')
		;
	if (tab[1] == 1)
	{
		if (tab[2] == 1)
			put = ft_align(put, fmt + 1, 'l', 'v');
		else
			put = ft_align(put, fmt + 1, ' ', 'v');
	}
	return (put);
}
