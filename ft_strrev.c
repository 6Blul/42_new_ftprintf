/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 01:02:39 by spochez           #+#    #+#             */
/*   Updated: 2015/01/12 02:28:22 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_strrev(char *s)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * len + 1);
	j = len - 1;
	while (j >= 0)
		res[i++] = s[j--];
	res[len] = 0;
	return (res);
}
