/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 02:42:41 by spochez           #+#    #+#             */
/*   Updated: 2015/01/24 03:33:38 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	char	*str;
	int		dz;

	str = "Bonjour";
	dz = 12;
	ft_printf("Moi des fois je dis %s ! Au moins %i fois !", str, dz);
	return (0);
}
