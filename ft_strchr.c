/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:22:44 by spochez           #+#    #+#             */
/*   Updated: 2015/01/24 02:46:28 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(char *s, int c)
{
	char	t;
	int		i;
	char	*tp;

	i = 0;
	t = (char)c;
	tp = (char *)s;
	if (tp)
	{
		while (i < (ft_strlen(tp) + 1))
		{
			if (tp[i] == t)
				return (&tp[i]);
			i++;
		}
		if (t == 0)
			return ((char *)s);
	}
	return (NULL);
}
