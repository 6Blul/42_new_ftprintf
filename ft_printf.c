/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 08:58:26 by spochez           #+#    #+#             */
/*   Updated: 2015/01/24 23:52:14 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_written_char(char s)
{
	ft_putchar(s);
	return (1);
}

char	*ft_cut_fmt(char *s)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	i = 0;
	j = 0;
	while (s[i] != '%' && s[i])
		i++;
	while (!is_convers_flag(s[i]) && s[i])
		i++;
	if (!s[i + 1])
		return (NULL);
	i += 1;
	len = ft_strlen(s) - i;
	res = (char *)malloc(sizeof(char) * len + 1);
	while (s[i])
		res[j++] = s[i++];
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
	while ((*s)++)
	{
		if (*s == '%')
		{
			while (!is_convers_flag(*s))
				(*s)++;
			if (is_convers_flag(*s) == 1)
				ct += ft_treat_int(s - 1, va_arg(ap, intmax_t));
			else if (is_convers_flag(*s) == 2)
				ct += ft_treat_uint(s - 1, va_arg(ap, uintmax_t));
			else if (is_convers_flag(*s) == 3)
				ct += ft_treat_void(s - 1, va_arg(ap, void *));
			s = ft_cut_fmt(s);
		}
		else
			ct += ft_written_char(*s);
	}
	va_end(ap);
	return (ct);
}
