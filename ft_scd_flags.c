/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scd_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 22:57:16 by spochez           #+#    #+#             */
/*   Updated: 2015/01/21 07:54:12 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_h_ui(uintmax_t arg, char c)
{
	if (c == 'x' || c == 'X')
		return (ft_hexa((unsigned short)arg));
	else if (c == 'b' || c == 't' || c == 'o')
		return (ft_bi_trinary((unsigned short)arg), c);
	else
		return (ft_uintmaxtoa((unsigned short)arg));
}

char		*ft_hh_ui(uintmax_t arg, char c)
{
	if (c == 'x' || c == 'X')
		return (ft_hexa((unsigned char)arg));
	else if (c == 'b' || c == 't' || c == 'o')
		return (ft_bi_trinary((unsigned char)arg), c);
	else
		return (ft_uintmaxtoa((unsigned char)arg));
}

char		*ft_l_ui(uintmax_t arg, char c)
{
	if (c == 'x' || c == 'X')
		return (ft_hexa((unsigned long)arg));
	else if (c == 'b' || c == 't' || c == 'o')
		return (ft_bi_trinary((unsigned long)arg)), c;
	else
		return (ft_uintmaxtoa((unsigned long)arg));
}

char		*ft_ll_ui(uintmax_t arg, char c)
{
	if (c == 'x' || c == 'X')
		return (ft_hexa((unsigned long long)arg));
	else if (c == 'b' || c == 't' || c == 'o')
		return (ft_bi_trinary((unsigned long long)arg), c);
	else
		return (ft_uintmaxtoa((unsigned long long)arg));
}

char		*ft_z_ui(uintmax_t arg, char c)
{
	if (c == 'x' || c == 'X')
		return (ft_hexa((size_t)arg));
	else if (c == 'b' || c == 't' || c == 'o')
		return (ft_bi_trinary((size_t)arg), c);
	else
		return (ft_uintmaxtoa((size_t)arg));
}
