/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 08:58:26 by spochez           #+#    #+#             */
/*   Updated: 2015/01/20 11:49:46 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_cut(char **s)
{
	int		nb;
	int		ct;

	nb = 0;
	ct = 0;
	while (**s && **s != '%')
	{
		ft_putchar(**s++);
		ct++;
	}
	while (!is_convers_flag(**s))
	{
		nb++;
		**s++;
	}
	if (*s + (ct + nb + 1))
		*s = ft_strdup(*s + (ct + nb + 1));
	else
		*s = NULL;
	return (ct);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*s1;
	char		*s2;
	int			ct;

	va_start(ap, format);
	ct = 0;
	s1 = ft_strdup(format);
	while (*s1)
	{
		s2 = ft_strchr(s1, '%');
		while (*s2++)
		{
			if (is_convers_flag(*s2) == 1)
				ct += ft_treat_int(s2, va_arg(ap, intmax_t));
			else if (is_convers_flag(*s2) == 2)
				ct += ft_treat_uint(s2, va_arg(ap, uintmax_t));
			else if (is_convers_flag(*s2) == 3)
				ct += ft_treat_void(s2, va_arg(api, void *));
		}
		ct += ft_print_cut(&s1);
	}
	va_end(ap);
	return (ct);
}
