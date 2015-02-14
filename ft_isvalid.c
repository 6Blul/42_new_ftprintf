/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 10:37:02 by spochez           #+#    #+#             */
/*   Updated: 2015/02/14 10:41:34 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_validchar(char c)
{
	if (ft_strchr("#0 +-.123456789hljz", (int)c) != NULL)
		return (1);
	return (0);
}

int		ft_isvalid(char *s)
{
	int		i;

	i = 0;
	if (s[i] == '%' && s[i - 1] != '%' && s[i + 1] != '%')
	{
		while (!is_convers_flag(s[i]) && s[i])
			i++;
		if (s[i] == 0)
			return (0);
		else
		{
			i--;
			while (s[i] != '%')
			{
				if (!ft_validchar(s[i]))
					return (0);
				i--;
			}
			return (1);
		}
	}
	else
		return (0);
}

int		ft_count_percent(char *s)
{
	int		i;

	i = 0;
	while (s[i] == '%' && s[i])
		i++;
	if (s[i + 1] == '%')
		i += 1;
	return (i);
}

int		ft_treat_percent(char *s)
{
	int		nb;
	int		per;
	int		count;

	count = 0;
	if (*(s - 1) == '%')
		return (0);
	else
	{
		nb = ft_count_percent(s);
		per = nb / 2;
		while (count < per)
		{
			ft_putchar('%');
			count++;
		}
	}
	return (count);
}
