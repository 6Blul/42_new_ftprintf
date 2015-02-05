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
	static int	passed;
	char		c;

	c = *(fmt + 1);
	if (passed == 0)
	{
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
		else
			return (ft_uinmaxtoa(arg));
	}
	passed = 1;
	return (put);
}

char	*ft_i_conversions(intmax_t arg, char *put, char *fmt)
{
	static int	passed;

	if (passed == 0)
	{
		if (*fmt == 'l' && *(fmt - 1) == 'l')
			put = ft_maxtoa(ft_ll_i(arg));
		else if (*fmt == 'h' && *(fmt - 1) == 'h')
			put = ft_maxtoa(ft_hh_i(arg));
		else if (*fmt == 'l')
			put = ft_maxtoa(ft_l_i(arg));
		else if (*fmt == 'h')
			put = ft_maxtoa(ft_h_i(arg));
		else if (*fmt == 'z')
			put = ft_maxtoa(ft_z_i(arg));
		else
			return (ft_maxtoa(arg));
	}
	passed = 1;
	return (put);
}
