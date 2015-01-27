/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 09:10:43 by spochez           #+#    #+#             */
/*   Updated: 2015/01/27 14:49:02 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_bef(char *put, char c)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 1;
	new = (char *)malloc(sizeof(char) * (ft_strlen(put) + 1) + 1);
	new[0] = c;
	while (put[i])
		new[j++] = put[i++];
	new[j] = 0;
	return (new);
}

char	*ft_sharpx(char *put)
{
	char	*ret;
	int		j;
	int		i;

	i = 0;
	j = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(put) + 2) + 1);
	if (put[i] == ' ' || put[i] == '+')
	{
		ret[j] = put[i];
		i++;
		j++;
	}
	ret[j] = '0';
	ret[j + 1] = 'x';
	j += 2;
	while (put[i])
		ret[j++] = put[i++];
	ret[j] = 0;
	return (ret);
}

char	*ft_sharpo(char *put)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(put) + 1) + 1);
	if (put[i] == ' ' || put[i] == '+')
	{
		ret[j] = put[i];
		i++;
		j++;
	}
	ret[j] = '0';
	j++;
	while (put[i])
		ret[j++] = put[i++];
	ret[j] = 0;
	return (ret);
}

char	*ft_left_align(int nb, char *put)
{
	char	*tp;
	char	*res;
	int		i;

	printf("pd");
	i = 0;
	if (nb <= ft_strlen(put))
		return (put);
	tp = ft_strdup(put);
	printf("pd");
	res = (char *)malloc(sizeof(char) * nb + 1);
	while (*tp && i <= nb)
	{
		*(res++) = *(tp++);
		i++;
	}
	while (i < nb)
		*(res++) = ' ';
	*res = 0;
	return (res);
}

char	*ft_align(char *put, char *fmt, char c)
{
	char	*num;
	int		nb;
	int		j;

	j = 0;
	printf("Char = %c\n", c);
	num = (char *)malloc(sizeof(char) * ft_strlen(put) + 1);
	printf("fmt = %s\n", fmt);
	printf("fmt* = %c\n", *fmt);
	while (!ft_isdigit(*fmt))
		fmt = fmt + 1;
	printf("fmt2 = %s\n", fmt);
	printf("char %c\n", *fmt);
	while (ft_isdigit(*fmt))
		num[j++] = *(fmt++);
	num[j] = 0;
	printf("NUM = %s\n", num);
	nb = ft_atoi(num);
	printf("LM == %i\n", nb);
	printf("put = %s\n", put);
	if (nb <= 0 || nb <= ft_strlen(put))
	{
		printf("Ton pere la motte de terre\n");
		return (put);
	}
	else
	{
		nb -= 1;
		printf("Ta mere le reverbere\n");
		printf("NewLM == %i\n", nb);
	}
	printf("Ton mari la borne incendie\n");
	if (c == '0' || c == ' ')
	{
		printf("Ton oncle le furoncle\n");
		put = to_print(nb, put, c);
	}
	else if (c == 'l')
	{
		printf("Ta soeur le pot de fleur\n");
		put = ft_left_align(nb, put);
		printf("Ton frere le lampadaire\n");
	}
	return (put);
}
