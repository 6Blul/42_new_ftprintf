/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 19:18:39 by spochez           #+#    #+#             */
/*   Updated: 2015/01/29 02:59:22 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	ft_put_in(char *res, unsigned int i, intmax_t n)
{
	if (n >= 10 || n <= -10)
	{
		if (n > 0)
			res[i] = (n % 10) + '0';
		else
			res[i] = -(n % 10) + '0';
		ft_put_in(res, i - 1, n / 10);
	}
	else
	{
		if (n > 0)
			res[i] = n + '0';
		else
			res[i] = -n + '0';
	}
}

char	*ft_maxtoa(intmax_t n)
{
	char		*conv;
	size_t		len;
	intmax_t	nb;

	conv = NULL;
	nb = n;
	len = 1;
	while (nb >= 10 || nb <= -10)
	{
		nb /= 10;
		len++;
	}
	conv = (char *)malloc(sizeof(char) * len + 1);
	if (n < 0)
	{
		conv[0] = '-';
		ft_put_in(&conv[1], len - 1, n);
	}
	else
		ft_put_in(conv, len - 1, n);
	if (n < 0)
		conv[len + 1] = 0;
	else
		conv[len] = 0;
	return (conv);
}
