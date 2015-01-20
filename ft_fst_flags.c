/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fst_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 22:53:19 by spochez           #+#    #+#             */
/*   Updated: 2015/01/10 00:10:28 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

short		ft_h_i(intmax_t arg)
{
	return ((short)arg);
}

signed char	ft_hh_i(intmax_t arg)
{
	return ((signed char)arg);
}

long		ft_l_i(intmax_t arg)
{
	return ((long)arg);
}

long long	ft_l_l_i(intmax_t arg)
{
	return ((long long)arg);
}

size_t		ft_z_i(intmax_t arg)
{
	return ((size_t)arg);
}
