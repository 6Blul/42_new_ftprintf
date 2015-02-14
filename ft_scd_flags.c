/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scd_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 22:57:16 by spochez           #+#    #+#             */
/*   Updated: 2015/01/24 02:19:27 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_h_ui(uintmax_t arg, char c)
{
	if (c == 'x' || c == 'X')
		return (ft_hexa((unsigned short)arg, c));
	else if (c == 'b' || c == 't' || c == 'o' || c == 'O')
		return (ft_base_convert((unsigned short)arg, c));
	else
		return (ft_uinmaxtoa((unsigned short)arg));
}

char		*ft_hh_ui(uintmax_t arg, char c)
{
	if (c == 'x' || c == 'X')
		return (ft_hexa((unsigned char)arg, c));
	else if (c == 'b' || c == 't' || c == 'o' || c == 'O')
		return (ft_base_convert((unsigned char)arg, c));
	else
		return (ft_uinmaxtoa((unsigned char)arg));
}

char		*ft_l_ui(uintmax_t arg, char c)
{
	if (c == 'x' || c == 'X')
		return (ft_hexa((unsigned long)arg, c));
	else if (c == 'b' || c == 't' || c == 'o' || c == 'O')
		return (ft_base_convert((unsigned long)arg, c));
	else
		return (ft_uinmaxtoa((unsigned long)arg));
}

char		*ft_ll_ui(uintmax_t arg, char c)
{
	if (c == 'x' || c == 'X')
		return (ft_hexa((unsigned long long)arg, c));
	else if (c == 'b' || c == 't' || c == 'o' || c == 'O')
		return (ft_base_convert((unsigned long long)arg, c));
	else
		return (ft_uinmaxtoa((unsigned long long)arg));
}

char		*ft_z_ui(uintmax_t arg, char c)
{
	if (c == 'x' || c == 'X')
		return (ft_hexa((size_t)arg, c));
	else if (c == 'b' || c == 't' || c == 'o' || c == 'O')
		return (ft_base_convert((size_t)arg, c));
	else
		return (ft_uinmaxtoa((size_t)arg));
}
