/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 13:08:37 by spochez           #+#    #+#             */
/*   Updated: 2015/02/12 13:12:52 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_itypes(intmax_t arg, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_maxtoa((int)arg));
	return (ft_maxtoa((long int)arg));
}

char	*ft_get_utypes(uintmax_t arg, char c)
{
	if (c == 'o' || c == 't' || c == 'b')
		return (ft_base_convert(arg, c));
	else if (c == 'O')
		return (ft_base_convert((long unsigned)arg, c));
	else if (c == 'x')
		return (ft_hexa(arg));
	else if (c == 'X')
		return (ft_hexa((long unsigned)arg));
	else if (c == 'U')
		return (ft_uinmaxtoa((long unsigned)arg));
	return (ft_uinmaxtoa(arg));
}
