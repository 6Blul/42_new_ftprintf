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

char	*ft_get_char(char arg)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * 1 + 1);
	res[0] = arg;
	res[1] = 0;
	return (res);
}
