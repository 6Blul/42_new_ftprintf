/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:30:38 by spochez           #+#    #+#             */
/*   Updated: 2015/02/14 13:01:23 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (s)
	{
		res = (char *)malloc(sizeof(char) * len + 1);
		if (res == NULL)
			return (NULL);
		i = 0;
		while (i < len)
		{
			res[i] = s[start];
			i++;
			start++;
		}
		res[i] = 0;
		return (res);
	}
	return (NULL);
}
