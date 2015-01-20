/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 10:37:42 by spochez           #+#    #+#             */
/*   Updated: 2015/01/20 14:49:07 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_wchar(char *c)
{
	return (*c == 'C' || (*c == 'c' && *c - 1 == 'l'));
}

int		is_wstr(char *c)
{
	return (*c == 'S' || (*c == 's' && *c - 1 == 'l'));
}

int		ft_treat_int(char *fmt, intmax_t arg)
{
	int		*tab;

	tab = (int *)malloc(sizeof(int) * 6);
	tab = fill_iflags(tab, fmt, arg);
	if (*fmt - 1 == '%' && !is_wchar(fmt))
		put = ft_maxtoa(arg);
	// ou si wchar -> traiter w_char (et return direct apres la valeur de retour du treat)
	// ou sinon :
	// - chercher les flags de conversion
	// - gerer la precision si tab[0] = 0
	// - s'il reste quelque chose (precision > 0) -> appliquer les autres flags
	// afficher put, return la longueur de put
}

int		ft_treat_uint(char *fmt, uintmax_t arg)
{
	int		*tab;
	char	*put;

	tab = (int *)malloc(sizeof(int) * 7);
	tab = fill_uiflags(tab, fmt);
	if (*fmt - 1 == '%')
		put = ft_uintmaxtoa(arg);
	else
	{
		while (is_let_flag(*fmt))
		{
			put = ft_ui_conversions(arg, put, fmt);
			*fmt--;
		}
		if (tab[0] == 0)
			put = ft_troncate(put, fmt);
		if (put != NULL)
			put = ft_ui_sflags(put, tab, fmt);
		else
			return (0);
	}
	ft_putstr(put);
	return (ft_strlen(put));
}

int		ft_treat_void(char *fmt, void *arg)
{
	int		*tab;

	tab = (int *)malloc(sizeof(int) * 3);
	tab = fill_vflags(tab, fmt);
	// S'il n'y a qu'un %s -> put = ft_strdup((char *)arg);
	// Ou si wstr -> traiter wstr (return le nb de caracteres ecrits et la return directement)
	// Ou si void -> traiter void (return dans put)
	// Sinon :
	// - Mettre le char * dans put.
	// - Gerer la precision si tab[0] == 0
	// - Gerer les autres flags (si precision > 0)
	// Afficher put, return la longueur de put.
}
