/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:50:51 by spochez           #+#    #+#             */
/*   Updated: 2015/01/20 15:34:48 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_i_sflags(char *put, int *tab, char *fmt)
{

}

char	*ft_ui_sflags(char *put, int *tab, char *fmt)
{
	char	*temp;

	temp = fmt;
	while (is_convers_flag(*temp) != 2)
		*temp++;
	if (tab[1] == 1)
		put = ft_add_bef(put, '+');
	else if (tab[2] == 1)
		put  = ft_add_bef(put, ' ');
	if (tab[3] == 1 && (*temp == 'o' || *temp == 'O'))
		put = ft_sharpo(put);
	if (tab[3] == 1 && (*temp == 'x' || *temp == 'X'))
		put = ft_sharpx(put);
	if (tab[4] == 1)
	{
		if (tab[5] == 1)
			put = ft_align(put, fmt, 'l');
		else if (tab[6] == 1)
			put = ft_align(put, fmt, '0');
		else
			put = ft_align(put, fmt, ' ');
	}
	return (put);
}

char	*ft_v_sflags(char *put, int *tab, char *fmt)
{

}
