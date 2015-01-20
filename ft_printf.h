/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 08:52:20 by spochez           #+#    #+#             */
/*   Updated: 2015/01/20 08:57:59 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <stdarg.h>

int						ft_printf(const char *format, ...);
int						ft_atoi(char *str);
int						ft_strlen(char *s);
int						ft_isdigit(char c);
void					ft_putchar(char c);
void					ft_putstr(char *s);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *b, size_t len);
char					*ft_strchr(char *s, int c);
char					*ft_strdup(char *s1);

#endif
