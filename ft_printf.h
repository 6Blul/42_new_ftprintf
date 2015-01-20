/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 08:52:20 by spochez           #+#    #+#             */
/*   Updated: 2015/01/20 11:16:35 by spochez          ###   ########.fr       */
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
int						ft_print_cut(char **s);
int						ft_atoi(char *str);
int						ft_strlen(char *s);
int						ft_isdigit(char c);
void					ft_putchar(char c);
void					ft_putstr(char *s);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *b, size_t len);
char					*ft_strchr(char *s, int c);
char					*ft_strdup(char *s1);
int						is_convers_flag(char c);
int						is_sign_flag(char c);
int						is_let_flag(char c);
char					*ft_strrev(char *s);
int						ft_treat_int(int *tab, char *fmt, intmax_t arg);
int						ft_treat_uint(int *tab, char *fmt);
int						ft_treat_void(int *tab, char *fmt);

#endif
