/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 08:52:20 by spochez           #+#    #+#             */
/*   Updated: 2015/01/27 10:38:39 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>
# include <stdarg.h>
# include <stdio.h>

int			ft_printf(const char *format, ...);
char		*ft_full_fmt(const char *fmt);
char		*ft_go_to(char *s);
char		*ft_cut_fmt(char *s);
int			ft_written_char(char s, int ct);
int			ft_atoi(char *str);
int			ft_strlen(char *s);
int			ft_isdigit(char c);
void		ft_putchar(char c);
void		ft_putstr(char *s);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *b, size_t len);
char		*ft_strchr(char *s, int c);
char		*ft_strdup(char *s1);
int			*fill_iflags(int *tab, char *fmt, intmax_t arg);
int			*fill_uiflags(int *tab, char *fmt);
int			*fill_vflags(int *tab, char *fmt);
int			is_convers_flag(char c);
int			is_sign_flag(char c);
int			is_let_flag(char c);
char		*ft_strrev(char *s);
int			ft_treat_int(char *fmt, intmax_t arg, char *copy);
int			ft_treat_uint(char *fmt, uintmax_t arg, char *copy);
int			ft_treat_void(char *fmt, void *arg, char *copy);
char		*ft_uinmaxtoa(uintmax_t n);
char		*ft_maxtoa(intmax_t n);
short		ft_h_i(intmax_t arg);
signed char	ft_hh_i(intmax_t arg);
long		ft_l_i(intmax_t arg);
long long	ft_ll_i(intmax_t arg);
size_t		ft_z_i(intmax_t arg);
char		*ft_h_ui(uintmax_t arg, char c);
char		*ft_hh_ui(uintmax_t arg, char c);
char		*ft_l_ui(uintmax_t arg, char c);
char		*ft_ll_ui(uintmax_t arg, char c);
char		*ft_z_ui(uintmax_t arg, char c);
char		*ft_base_convert(uintmax_t arg, char c);
char		*ft_hexa(uintmax_t arg);
char		*ft_ui_conversions(uintmax_t arg, char *put, char *fmt);
char		*ft_i_conversions(intmax_t arg, char *put, char *fmt);
char		*ft_treat_prec(char *put, char *fmt, int type);
char		*ft_i_sflags(char *put, int *tab, char *fmt);
char		*ft_ui_sflags(char *put, int *tab, char *fmt);
char		*ft_v_sflags(char *put, int *tab, char *fmt);
char		*to_print(int width, char *conv, char c);
char		*ft_align(char *put, char *fmt, char c);
char		*ft_sharpo(char *put);
char		*ft_sharpx(char *put);
char		*ft_add_bef(char *put, char c);
void		ft_putwchar(int *tab);
int			ft_get_precision(char *fmt);
int			ft_get_lm(char *fmt);
int			ft_treat_wchar(char *fmt, wchar_t arg, int *tab, int st);
int			ft_treat_wstr(char *fmt, int *tab, wchar_t *arg);
int			*ft_split_bits(char *bits);
void		ft_adjust(int lm);
char		*ft_convers_void(char *fmt, int *tab, void *arg);
char		*ft_treat_preint(int nb, char *pre, char *put);
char		*ft_treat_prestr(int nb, char *pre, char *put);
char		*ft_treat_hexa(int nb, char *pre, char *put);
char		*ft_insta_uint(uintmax_t arg, char *fmt);

#endif
