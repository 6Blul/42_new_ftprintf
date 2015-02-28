/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 11:22:53 by spochez           #+#    #+#             */
/*   Updated: 2015/02/13 11:22:56 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_no_prec(void)
{
	char	*pd;

	pd = (char *)malloc(sizeof(char) * 3);
	pd[0] = '0';
	pd[1] = 'x';
	pd[2] = 0;
	return (pd);
}

char	*ft_null_prec(char *s)
{
	int		nb;
	int		i;
	char	*ret;

	i = 2;
	while (*s != '.')
		s--;
	if (!ft_isdigit(*(s + 1)) || *(s + 1) == '0')
		return (ft_no_prec());
	nb = ft_atoi(s + 1);
	ret = (char *)malloc(sizeof(char) * (nb + 1) + 1);
	ret[0] = '0';
	ret[1] = 'x';
	while (i <= (nb + 1))
	{
		ret[i] = '0';
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*ft_treat_nullalign(char *s, char *pd, int l)
{
	char	*tp;

	tp = s;
	while (*tp != '%')
		tp--;
	if (l == 1)
		pd = ft_align(pd, tp, 'l', 'i');
	else
		pd = ft_align(pd, tp, ' ', 'i');
	return (pd);
}

int		ft_treat_flags_null(int *tab, char *s)
{
	char	*pd;

	if (tab[0] == 1)
		pd = ft_null_prec(s);
	else
	{
		pd = (char *)malloc(sizeof(char) * 4);
		pd[0] = '0';
		pd[1] = 'x';
		pd[2] = '0';
		pd[3] = 0;
	}
	if (tab[2] == 1 || tab[1] == 1)
		pd = ft_treat_nullalign(s, pd, tab[2]);
	ft_putstr(pd);
	return (ft_strlen(pd));
}

int		ft_treat_null(char *s, int *tab)
{
	int		res;

	if (*s == 'S' || *s == 's')
	{
		ft_putstr("(null)");
		return (6);
	}
	else
	{
		if (tab[0] == 0 && tab[1] == 0 && tab[2] == 0)
		{
			ft_putstr("0x0");
			res = 3;
		}
		else
			res = ft_treat_flags_null(tab, s);
	}
	return (res);
}
