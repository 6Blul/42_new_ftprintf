/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:15:15 by spochez           #+#    #+#             */
/*   Updated: 2015/02/05 07:11:30 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ui_conversions(uintmax_t arg, char *put, char *fmt)
{
	char		c;

	c = *(fmt + 1);
	if (*fmt == 'l' && *(fmt - 1) == 'l')
		put = ft_ll_ui(arg, c);
	else if (*fmt == 'h' && *(fmt - 1) == 'h')
		put = ft_hh_ui(arg, c);
	else if (*fmt == 'l')
		put = ft_l_ui(arg, c);
	else if (*fmt == 'h')
		put = ft_h_ui(arg, c);
	else if (*fmt == 'z')
		put = ft_z_ui(arg, c);
	else if (*fmt == 'j')
		put = ft_uinmaxtoa(arg);
	else
		return (ft_get_utypes(arg, c));
	return (put);
}

char	*ft_i_conversions(intmax_t arg, char *put, char *fmt)
{
	if (*fmt == 'l' && *(fmt - 1) == 'l')
		put = ft_maxtoa((long long int)arg);
	else if (*fmt == 'h' && *(fmt - 1) == 'h')
		put = ft_maxtoa((signed char)arg);
	else if (*fmt == 'l')
		put = ft_maxtoa((long int)arg);
	else if (*fmt == 'h')
		put = ft_maxtoa((short)arg);
	else if (*fmt == 'z')
		put = ft_maxtoa((size_t)arg);
	else if (*fmt == 'j')
		put = ft_maxtoa(arg);
	return (put);
}
