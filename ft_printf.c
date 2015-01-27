/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 08:58:26 by spochez           #+#    #+#             */
/*   Updated: 2015/01/27 05:52:41 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_written_char(char s, int ct)
{
	ft_putchar(s);
	return (ct + 1);
}

char	*ft_go_to(char *s)
{
	while (is_convers_flag(*(s++)) == 0)
		;
	return (s);
}

char	*ft_cut_fmt(char *s)
{
	char	*res;
	int		j;

	j = 0;
	s = ft_go_to(s);
	res = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	while (*s)
		res[j++] = *(s++);
	res[j] = 0;
	return (res);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*s;
	int			ct;

	va_start(ap, format);
	ct = 0;
	s = ft_strdup((char *)format);
	while (*s)
	{
		if (*s == '%')
		{
			s = ft_go_to(s);
			if (is_convers_flag(*s) == 1)
				ct += ft_treat_int(s - 1, va_arg(ap, intmax_t));
			else if (is_convers_flag(*s) == 2)
				ct += ft_treat_uint(s - 1, va_arg(ap, uintmax_t));
			else if (is_convers_flag(*s) == 3)
				ct += ft_treat_void(s - 1, va_arg(ap, void *));
			s = ft_cut_fmt(s);
		}
		else
			ct = ft_written_char(*(s++), ct);
	}
	va_end(ap);
	return (ct);
}
