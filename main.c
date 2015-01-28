/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 02:55:31 by spochez           #+#    #+#             */
/*   Updated: 2015/01/28 23:25:32 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	char	*s;
	int		i;
	unsigned int	x;
	unsigned int	o;
	char	*ad;

	s = "un gros chat bleu";
	i = 12;
	x = 245;
	o = 10;
	ad = "pdpd";
	ft_printf("J'ai %20.5s qui pese %i kilos et %x grammes, gimme your ad : [%20p] ! Je le caresse %o fois par jour !\n\n", s, i, x, ad, o);
	printf("J'ai %20.5s qui pese %i kilos et %x grammes, gimme your ad : [%20p] ! Je le caresse %o fois par jour !\n\n", s, i, x, ad, o);
	return (0);
}
