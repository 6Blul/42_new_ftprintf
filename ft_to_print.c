/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 14:04:45 by spochez           #+#    #+#             */
/*   Updated: 2015/01/24 02:49:31 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*put_blanks(char *s, int spaces, char *ret)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i <= spaces)
		ret[i++] = ' ';
	while (s[j])
		ret[i++] = s[j++];
	ret[i] = 0;
	return (ret);
}

char	*put_zeros(char *s, int spaces, char *ret)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i <= spaces)
		ret[i++] = '0';
	while (s[j])
		ret[i++] = s[j++];
	ret[i] = 0;
	return (ret);
}

char	*to_print(int width, char *conv, char c)
{
	int		len;
	char	*ret;

	len = ft_strlen(conv);
	ret = (char *)malloc(sizeof(char) * width + 1);
	if (len >= width)
		return (conv);
	else
	{
		if (c == ' ')
			ret = put_blanks(conv, width, ret);
		else if (c == '0')
			ret = put_zeros(conv, width, ret);
	}
	return (ret);
}
