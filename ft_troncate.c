/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_troncate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:38:05 by spochez           #+#    #+#             */
/*   Updated: 2015/01/20 14:47:43 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_troncate(char *put, char *fmt)
{
	char	*pre;
	int		nb;
	int		i;

	i = 0;
	while (*fmt != '.')
		*fmt--;
	if (!ft_isdigit(*fmt + 1))
		return (put);
	nb = ft_atoi(fmt);
	if (nb == 0)
		return (NULL);
	pre = (char *)malloc(sizeof(char) * nb + 1);
	while (i < nb)
		pre[i++] = *put++;
	pre[i] = 0;
	return (pre);
}
