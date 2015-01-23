/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_troncate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:38:05 by spochez           #+#    #+#             */
/*   Updated: 2015/01/23 20:32:02 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_treat_preint(int nb, char *pre, char *put)
{

}

char	*ft_treat_prestr(int nb, char *pre, char *put)
{

}

int		ft_get_precision(char *fmt)
{
	int		nb;

	while (*fmt != '.' || *fmt != '%')
		*fmt--;
	if (*fmt == '%' || !ft_isdigit(*fmt + 1))
		return (0);
	nb = ft_atoi(fmt);
	return (nb);
}

char	*ft_treat_prec(char *put, char *fmt, int type)
{
	char	*pre;
	int		nb;

	nb = ft_get_precision(fmt);
	pre = (char *)malloc(sizeof(char) * nb + 1);
	if (type == 0)
	{
		if (nb <= ft_strlen(put))
			return (put);
		else
			pre = ft_treat_preint(nb, pre, put);
	}
	else if (type == 1)
	{
		if (nb == 0)
			return (NULL);
		else if (nb >= ft_strlen(put))
			return (put);
		else
			pre = ft_treat_prestr(nb, pre, put);
	}
	return (pre);
}
