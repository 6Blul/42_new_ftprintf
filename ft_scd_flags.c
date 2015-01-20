/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scd_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 22:57:16 by spochez           #+#    #+#             */
/*   Updated: 2015/01/13 01:18:56 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_h_ui(uintmax_t arg, char c)
{
	if (c == 'o')
		return (ft_octal_h((unsigned short)arg));
	else if (c == 'x' || c == 'X')
		return (ft_hexa_h((unsigned short)arg));
	else if (c == 'b' || c == 't')
		return (ft_bi_trinary_h((unsigned short)arg), c);
	else
		return (ft_uintmaxtoa((unsigned short)arg));
}

char		*ft_hh_ui(uintmax_t arg, char c)
{
	if (c == 'o')
		return (ft_octal_hh((unsigned char)arg));
	else if (c == 'x' || c == 'X')
		return (ft_hexa_hh((unsigned char)arg));
	else if (c == 'b' || c == 't')
		return (ft_bi_trinary_hh((unsigned char)arg), c);
	else
		return (ft_uintmaxtoa((unsigned char)arg));
}

char		*ft_l_ui(uintmax_t arg, char c)
{
	if (c == 'o')
		return (ft_octal_l((unsigned long)arg));
	else if (c == 'x' || c == 'X')
		return (ft_hexa_l((unsigned long)arg));
	else if (c == 'b' || c == 't')
		return (ft_bi_trinary_l((unsigned long)arg)), c;
	else
		return (ft_uintmaxtoa((unsigned long)arg));
}

char		*ft_l_l_ui(uintmax_t arg, char c)
{
	if (c == 'o')
		return (ft_octal_ll((unsigned long long)arg));
	else if (c == 'x' || c == 'X')
		return (ft_hexa_ll((unsigned long long)arg));
	else if (c == 'b' || c == 't')
		return (ft_bi_trinary_ll((unsigned long long)arg), c);
	else
		return (ft_uintmaxtoa((unsigned long long)arg));
}

char		*ft_z_ui(uintmax_t arg, char c)
{
	if (c == 'o')
		return (ft_octal_z((size_t)arg));
	else if (c == 'x' || c == 'X')
		return (ft_hexa_z((size_t)arg));
	else if (c == 'b' || c == 't')
		return (ft_bi_trinary_z((size_t)arg), c);
	else
		return (ft_uintmaxtoa((size_t)arg));
}
