/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 03:01:52 by spochez           #+#    #+#             */
/*   Updated: 2015/01/29 03:06:59 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_get_char(char arg)
{
	char	*put;

	put = (char *)malloc(sizeof(char) * 2);
	if (arg == 0)
		ft_bzero(put, '2');
	else
	{
		put[0] = arg;
		put[1] = 0;
	}
	return (put);
}
