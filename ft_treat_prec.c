/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_troncate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:38:05 by spochez           #+#    #+#             */
/*   Updated: 2015/02/05 06:01:07 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_treat_preint(int nb, char *pre, char *put, int isneg)
{
	int		i;
	int		len;
	int		zer;

	i = 0;
	if (isneg == 1)
	{
		pre[i] = '-';
		put = put + 1;
		nb += 1;
		i++;
	}
	len = ft_strlen(put);
	zer = nb - len;
	while (i < zer)
		pre[i++] = '0';
	while (*put)
		pre[i++] = *put++;
	pre[i] = 0;
	return (pre);
}

char	*ft_treat_prestr(int nb, char *pre, char *put)
{
	int		i;

	i = 0;
	while (i <= nb && put[i])
	{
		pre[i] = put[i];
		i++;
	}
	pre[i] = 0;
	return (pre);
}

int		ft_get_precision(char *fmt)
{
	int		nb;

	while (*(fmt++) != '.')
		;
	nb = ft_atoi(fmt);
	return (nb);
}

char	*which_return(char *put)
{
	if (put[0] == '0' && !put[1])
	{
		put = (char *)malloc(sizeof(char) * 1 + 1);
		put[0] = ' ';
		put[1] = 0;
	}
	return (put);
}

char	*ft_treat_prec(char *put, char *fmt, int type, int isneg)
{
	char	*pre;
	int		nb;

	nb = ft_get_precision(fmt);
	pre = (char *)malloc(sizeof(char) * nb + 1);
	if (type == 0)
	{
		if (nb <= ft_strlen(put))
			return (which_return(put));
		else
			pre = ft_treat_preint(nb, pre, put, isneg);
	}
	else
	{
		if (nb > ft_strlen(put))
			return (put);
		else if (nb == 0)
		{
			ft_bzero((void *)put, (size_t)ft_strlen(put));
			return (put);
		}
		else
			pre = ft_treat_prestr(nb - 1, pre, put);
	}
	return (pre);
}
