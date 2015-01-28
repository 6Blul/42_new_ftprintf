/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_lm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 10:00:38 by spochez           #+#    #+#             */
/*   Updated: 2015/01/28 22:16:45 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_lm(char *fmt)
{
	int		lm;

	printf("LMFMT = %s\n", fmt);
	while (*fmt != '%')
		(*fmt)--;
	while (!ft_isdigit(*fmt) && *fmt)
		(*fmt)++;
	if (*fmt == 0 || *(fmt - 1) == '.')
		return (0);
	lm = ft_atoi(fmt);
	return (lm);
}
