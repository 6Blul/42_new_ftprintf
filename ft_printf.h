/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 08:52:20 by spochez           #+#    #+#             */
/*   Updated: 2015/02/05 06:49:06 by spochez          ###   ########.fr       */
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
# include <inttypes.h>
# include <limits.h>

int			ft_printf(const char *format, ...);
char		*ft_full_fmt(char *s);
char		*ft_go_to(char *s);
char		*ft_cut_fmt(char *s);
int			ft_written_char(char *s, int ct);
int			ft_atoi(char *str);
int			ft_strlen(char *s);
int			ft_isdigit(char c);
void		ft_putchar(char c);
void		ft_putstr(char *s);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *b, size_t len);
char		*ft_strchr(char *s, int c);
char		*ft_strdup(char *s1);
int			*fill_iflags(int *tab, char *fmt, int arg);
int			*fill_uiflags(int *tab, char *fmt, unsigned int arg);
int			*fill_vflags(int *tab, char *fmt);
void		ft_adapt_char(int *tab);
int			is_convers_flag(char c);
int			is_sign_flag(char c);
int			is_let_flag(char c);
char 		*ft_get_char(char arg);
char		*ft_strrev(char *s);
int			ft_treat_int(char *fmt, intmax_t arg, char *copy);
int			ft_treat_uint(char *fmt, uintmax_t arg, char *copy);
int			ft_treat_void(char *fmt, void *arg, char *copy);
char		*ft_get_itypes(intmax_t arg, char c);
char		*ft_get_utypes(uintmax_t arg, char c);
char		*ft_uinmaxtoa(uintmax_t n);
char		*ft_maxtoa(intmax_t n);
char		*ft_h_ui(uintmax_t arg, char c);
char		*ft_hh_ui(uintmax_t arg, char c);
char		*ft_l_ui(uintmax_t arg, char c);
char		*ft_ll_ui(uintmax_t arg, char c);
char		*ft_z_ui(uintmax_t arg, char c);
char		*ft_base_convert(uintmax_t arg, char c);
char		*ft_hexa(uintmax_t arg, char c);
char		*ft_ui_conversions(uintmax_t arg, char *put, char *fmt);
char		*ft_i_conversions(intmax_t arg, char *put, char *fmt);
char		*ft_treat_prec(char *put, char *fmt, int type, int isneg);
char		*ft_i_sflags(char *put, int *tab, char *fmt);
char		*ft_ui_sflags(char *put, int *tab, char *fmt);
char		*ft_v_sflags(char *put, int *tab, char *fmt);
char		*to_print(int width, char *conv, char c);
char		*ft_align(char *put, char *fmt, char c, char type);
char		*ft_sharpo(char *put);
char		*ft_sharpx(char *put, char c);
char		*ft_add_bef(char *put, char c);
void		ft_putwchar(char **tab);
int			ft_get_wprecision(char *fmt);
int			ft_treat_wchar(char *fmt, wchar_t arg, int *tab, int st);
int			ft_treat_wstr(char *fmt, int *tab, wchar_t *arg);
char		**ft_split_bits(char *bits);
void		ft_adjust(int lm);
char		*ft_convers_void(char *fmt, int *tab, void *arg);
char		*ft_treat_preint(int nb, char *pre, char *put, int isneg);
char		*ft_treat_prestr(int nb, char *pre, char *put);
char		*ft_insta_uint(uintmax_t arg, char *fmt);
int			ft_get_lm(char *fmt);
int			is_lm(char *fmt);
char		*ft_complete(char *bin);
int 		ft_treat_null(char c);
int 		ft_isvalid(char *s);
int			ft_treat_percent(char *s);
char		**ft_strsplit(char const *s, char c);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
int			ft_binary_to_dec(char *pd);
char		*ft_arg_is_zero(void);

#endif
