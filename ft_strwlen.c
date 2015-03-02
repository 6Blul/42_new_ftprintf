/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 02:29:25 by spochez           #+#    #+#             */
/*   Updated: 2015/03/01 02:29:27 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		ft_charsize(int c)
{
	char 	*b;

	b = ft_base_convert(c, 'b');
	if (ft_strlen(b) <= 7)
		return (1);
	if (ft_strlen(b) <= 11)
		return (2);
	if (ft_strlen(b) <= 16)
		return (3);
	return (4);
}

int		ft_strwlen(wchar_t *s)
{
	int		i;

	if (s == NULL)
		return (0);
	i = 0;
	while (*s)
	{
		i += ft_charsize(*s);
		s++;
	}
	return (i);
}

int		is_str(wchar_t *s)
{
	int		size;
	int		i;

	i = 0;
	size = ft_strwlen(s);
	while (s[i])
		i++;
	if (i == size)
		return (1);
	return (0);
}