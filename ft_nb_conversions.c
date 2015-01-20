/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:15:15 by spochez           #+#    #+#             */
/*   Updated: 2015/01/20 14:38:00 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ui_conversions(uintmax_t arg, char *put, char *fmt)
{
	static int	passed;
	char		c;

	c = *fmt + 1;
	if (passed == 0)
	{
		if (*fmt == 'l' && *fmt + 1 == 'l')
			put = ft_l_l_ui(arg, c);
		else if (*fmt == 'h' && *fmt + 1 == 'h')
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

}
