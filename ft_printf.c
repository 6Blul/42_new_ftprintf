/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 08:58:26 by spochez           #+#    #+#             */
/*   Updated: 2015/01/24 03:47:13 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_written_char(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '%')
		ft_putchar(s[i++]);
	return (i);
}

char	*ft_print_cut(char *s)
{
	int		i;
	char	*res;

	i = 0;
	printf("troncate1\n");
	while (s[i] && s[i] != '%')
		i++;
	while (!is_convers_flag(s[i]))
		i++;
	s[i - 1] = 0;
	if (s[i])
		res = ft_strdup(s);
	else
		return (NULL);
	printf("troncate2\n");
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
		ct += ft_written_char(s);
		if (is_convers_flag(*s) == 1)
			ct += ft_treat_int(s - 1, va_arg(ap, intmax_t));
		else if (is_convers_flag(*s) == 2)
			ct += ft_treat_uint(s - 1, va_arg(ap, uintmax_t));
		else if (is_convers_flag(*s) == 3)
			ct += ft_treat_void(s - 1, va_arg(ap, void *));
		s = ft_print_cut(s);
	}
	va_end(ap);
	return (ct);
}
