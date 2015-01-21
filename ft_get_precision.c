/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 09:48:19 by spochez           #+#    #+#             */
/*   Updated: 2015/01/21 09:52:49 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_precision(char *fmt)
{
	int		nb;

	while (*fmt != '.' || *fmt != '%')
		*fmt--;
	if (!ft_isdigit(*fmt + 1) || *fmt == '%')
		return (ft_strlen(fmt));
	nb = ft_atoi(fmt);
	return (nb);
}
