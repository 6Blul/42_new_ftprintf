/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 19:18:39 by spochez           #+#    #+#             */
/*   Updated: 2015/01/14 01:15:09 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void	ft_put_in(char *res, unsigned int i, uintmax_t n)
{
	if (n >= 10)
	{
		res[i] = (n % 10) + '0';
		ft_put_in(res, i - 1, n / 10);
	}
	else
	{
		res[i] = n + '0';
	}
}

char		*ft_uinmaxtoa(uintmax_t n)
{
	char		*conv;
	size_t		len;
	uintmax_t	nb;

	conv = NULL;
	nb = n;
	len = 1;
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	conv = (char *)malloc(sizeof(char) * len + 1);
	ft_put_in(conv, len - 1, n);
	conv[len] = 0;
	return (conv);
}
