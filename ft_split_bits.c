/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 04:29:32 by spochez           #+#    #+#             */
/*   Updated: 2015/01/27 06:04:03 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_replace_x(char **pd, int sandwich)
{
	int		i;
	int		j;

	j = 0;
	while (j < sandwich)
	{
		i = 0;
		while (i < ft_strlen(pd[j]))
		{
			if (pd[j][i] == 'x')
				pd[j][i] = '0';
			i++;
		}
		j++;
	}
}

void	ft_fill_tab(int sandwich, char *bits, char **pd)
{
	int		i;
	int		j;
	int		groq;

	i = sandwich;
	groq = (ft_strlen(bits) - 1);
	while (i >= 0)
	{
		j = (ft_strlen(pd[i]) - 1);
		while (j >= 0 && groq >= 0)
		{
			if (pd[i][j] == 'x')
			{
				pd[i][j] = bits[groq];
				groq--;
			}
			j--;
		}
		i--;
	}
}

char	*ft_define_tab(char *bits)
{
	size_t	len;
	char	*nb;

	len = ft_strlen(bits);
	if (len <= 7)
		nb = "0xxxxxxx";
	else if (len > 7 && len <= 11)
		nb = "110xxxxx 10xxxxxx";
	else if (len > 11 && len <= 16)
		nb = "1110xxxx 10xxxxxx 10xxxxxx";
	else
		nb = "11110xxx 10xxxxxx 10xxxxxx 10xxxxxx";
	return (nb);
}

char	**ft_split_bits(char *bits)
{
	char	**pd;
	char	*gropd;
	int		sandwich;

	sandwich = 0;
	gropd = ft_define_tab(bits);
	pd = ft_strsplit(gropd, ' ');
	while (pd[sandwich])
		sandwich++;
	ft_fill_tab(sandwich - 1, bits, pd);
	ft_replace_x(pd, sandwich - 1);
	return (pd);

}
