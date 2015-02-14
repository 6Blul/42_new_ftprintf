/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 02:05:53 by spochez           #+#    #+#             */
/*   Updated: 2015/01/27 10:41:57 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	ft_hexa_mininb(int n)
{
	if (n == 10)
		return ('a');
	else if (n == 11)
		return ('b');
	else if (n == 12)
		return ('c');
	else if (n == 13)
		return ('d');
	else if (n == 14)
		return ('e');
	else if (n == 15)
		return ('f');
	return ((char)n);
}

char	ft_hexa_maxinb(int n)
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

char	ft_which_nb(char n, char c)
{
	if (c == 'x')
		return (ft_hexa_mininb(n));
	return (ft_hexa_maxinb(n));
}

char	*ft_hexa(uintmax_t arg, char c)
{
	char	*tp;
	char	*new;
	int		i;
	int		len;
	int		nb;

	i = 0;
	tp = ft_uinmaxtoa(arg);
	len = ft_strlen(tp);
	new = (char *)malloc(sizeof(char) * len + 1);
	while (arg > 0)
	{
		nb = (arg % 16);
		if (nb >= 10)
			new[i] = ft_which_nb(nb, c);
		else
			new[i] = nb + '0';
		arg /= 16;
		i++;
	}
	new[i] = 0;
	new = ft_strrev(new);
	return (new);
}
