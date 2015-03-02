/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:40:49 by spochez           #+#    #+#             */
/*   Updated: 2015/01/20 08:40:51 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_strdup(char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = NULL;
	s2 = malloc(sizeof(char) * ft_strlen(s1) + 1);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

char	*ft_strchoice(void *arg, char c)
{
	char	*res;
	int		i;
	wchar_t	*tp;

	if (c == 's')
		return (ft_strdup((char *)arg));
	else
	{
		tp = (wchar_t *)arg;
		i = 0;
		res = (char *)malloc(sizeof(char) * ft_strwlen((wchar_t *)arg) + 1);
		while (tp[i])
		{
			res[i] = tp[i];
			i++;
		}
		res[i] = 0;
	}
	return (res);
}
