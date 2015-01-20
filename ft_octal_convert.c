/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 01:48:37 by spochez           #+#    #+#             */
/*   Updated: 2015/01/20 13:18:56 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_octal(uintmax_t arg)
{
	char	*tp;
	char	*new;
	int		i;
	int		len;

	i = 0;
	tp = ft_uinmaxtoa(arg);
	len = ft_strlen(tp);
	new = (char *)malloc(sizeof(char) * len + 1);
	while (arg > 0)
	{
		new[i] = (arg % 8) + '0';
		arg /= 8;
		i++;
	}
	new[i] = 0;
	new = ft_strrev(new);
	return (new);
}
