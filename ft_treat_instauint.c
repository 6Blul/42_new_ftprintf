/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_instauint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 09:13:47 by spochez           #+#    #+#             */
/*   Updated: 2015/01/27 12:17:32 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_insta_uint(uintmax_t arg, char *fmt)
{
	char	*put;

	while (is_convers_flag(*fmt) == 0)
		(*fmt)++;
	if (*fmt == 'o' || *fmt == 'O')
		put = ft_base_convert(arg, 'o');
	else if (*fmt == 'x' || *fmt == 'X')
		put = ft_hexa(arg);
	else
		put = ft_maxtoa(arg);
	return (put);
}
