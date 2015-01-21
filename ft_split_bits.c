/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 04:29:32 by spochez           #+#    #+#             */
/*   Updated: 2015/01/14 04:13:58 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_tab(char **res, int nb, char *bits)
{
	int		i;
	int		j;
	int		b;

	j = 0;
	b = 0;
	while (j < nb)
	{
		res[j] = (char *)malloc(sizeof(char) * (7 + 1));
		i = 7;
		while (i >= 0)
		{
			if (bits[b])
				res[j][i--] = bits[b++];
			else if (!bits[b] && i >= 0)
			{
				res[j][i] = '0';
				i--;
			}
		}
		res[j][8] = 0;
		j++;
	}
}

int		ft_define_tab(char *bits)
{
	size_t	len;
	int		nb;

	len = ft_strlen(bits);
	if (len <= 8)
		nb = 1;
	else if (len > 8 && len <= 16)
		nb = 2;
	else if (len > 16 && len <= 24)
		nb = 3;
	else
		nb = 4;
	return (nb);
}

int		*ft_split_bits(char *bits)
{
	char	**res;
	int		*bins;
	int		nb;
	int		i;

	i = 0;
	nb = ft_define_tab(bits);
	res = (char **)malloc(sizeof(char *) * (nb + 1));
	bin = (int *)malloc(sizeof(int) * nb + 1);
	ft_fill_tab(res, nb, bits);
	while (res[i])
		bins[i++] = ft_atoi(res[i++]);
	return (bins);
}
