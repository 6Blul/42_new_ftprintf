/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchrtreat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 09:36:05 by spochez           #+#    #+#             */
/*   Updated: 2015/01/22 05:32:56 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_adjust(int lm)
{
	int		i;

	i = 1;
	while (i < (lm - 1))
	{
		write(1, ' ', 1);
		i++;
	}
}

void	ft_putwchar(int *tab)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (tab[i])
	{
		write(1, &tab[i], 1);
		i++;
	}
}

int		ft_treat_wchar(char *fmt, wchar_t arg, int *tab, int st)
{
	char	*bin;
	int		*bits;
	int		pre;
	int		lm;

	if (st == 0)
	{
		pre = ft_get_precision(fmt);
		lm = ft_get_lm(fmt);
	}
	else
		pre = 1;
	if (tab[3] == 1 && tab[4] == 0 && st == 0)
		ft_adjust(lm);
	if (pre > 0)
	{
		bin = ft_base_convert((int)arg, 'b');
		bits = ft_split_bits(bin);
		ft_putwchar(bits);
		if (tab[3] == 1 && tab[4] == 1 && st == 0)
			ft_adjust(lm);
		return (lm + 1);
	}
	return (0);
}

int		ft_treat_wstr(char *fmt, int *tab, wchar_t *arg)
{
	int		lm;
	int		pre;
	int		j;

	pre = ft_get_precision(fmt);
	lm = ft_get_lm(fmt);
	j = 0;
	if (tab[1] == 1 && tab[2] == 0)
		ft_adjust(lm - ft_strlen(arg));
	while (j <= pre)
		ft_treat_wchar(fmt, arg[j++], tab, 1);
	if (tab[1] == 1 && tab[2] == 1)
		ft_adjust(lm - ft_strlen(arg));
	return (lm);
}
