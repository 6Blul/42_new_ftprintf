/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 02:05:53 by spochez           #+#    #+#             */
/*   Updated: 2015/01/20 12:56:09 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	ft_hexa_nb(int n)
{
	if (n == 10)
		return ('A');
	else if (n == 11)
		return ('B');
	else if (n == 12)
		return ('C');
	else if (n == 13)
		return ('D');
	else if (n == 14)
		return ('E');
	else if (n == 15)
		return ('F');
	return ((char)n);
}

char	*ft_hexa(uintmax_t arg)
{
	char	*tp;
	char	*new;
	int		i;
	int		len;
	int		nb;

	i = 0;
	tp = ft_uinmaxtoa((uintmax_t)arg);
	len = ft_strlen(tp);
	new = (char *)malloc(sizeof(char) * len + 1);
	while (arg > 0)
	{
		nb = (arg % 16);
		if (nb >= 10)
			new[i] = ft_hexa_nb(nb);
		else
			new[i] = nb + '0';
		arg /= 16;
		i++;
	}
	new[i] = 0;
	new = ft_strrev(new);
	return (new);
}
