/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 08:58:26 by spochez           #+#    #+#             */
/*   Updated: 2015/02/05 04:36:44 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_written_char(char *s, int ct)
{
	if (*(s - 1) && *(s - 1) == '%' && *s == '%')
		return (ct);
	else
		ft_putchar(*s);
	return (ct + 1);
}

char	*ft_go_to(char *s)
{
	while (is_convers_flag(*s) == 0 && *s)
		s++;
	return (s);
}

char	*ft_cut_fmt(char *s)
{
	char	*res;
	int		j;

	j = 0;
	s = ft_go_to(s);
	s = s + 1;
	res = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	while (*s)
		res[j++] = *(s++);
	res[j] = 0;
	return (res);
}

char	*ft_full_fmt(char *s)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	while (s[i] != '%')
		i--;
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
	while (*s)
	{
		if (*s == '%' && *(s - 1) != '%')
		{
			s = ft_go_to(s);
			if (is_convers_flag(*s) == 1)
				ct += ft_treat_int(s, va_arg(ap, intmax_t), ft_full_fmt(s));
			else if (is_convers_flag(*s) == 2)
				ct += ft_treat_uint(s, va_arg(ap, uintmax_t), ft_full_fmt(s));
			else if (is_convers_flag(*s) == 3)
				ct += ft_treat_void(s, va_arg(ap, void *), ft_full_fmt(s));
			s = ft_cut_fmt(s);
		}
		else
			ct = ft_written_char(s++, ct);
	}
	va_end(ap);
	return (ct);
}
