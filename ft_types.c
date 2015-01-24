/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 09:41:55 by spochez           #+#    #+#             */
/*   Updated: 2015/01/24 01:52:47 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_sign_flag(char c)
{
	if (ft_strchr("#0 +-.", (int)c) != NULL)
		return (1);
	return (0);
}

int		is_let_flag(char c)
{
	if (ft_strchr("hljz", (int)c) != NULL)
		return (1);
	return (0);
}

int		is_convers_flag(char c)
{
	int		nb;

	nb = 0;
	if (ft_strchr("dDicC", (int)c) != NULL)
		nb = 1;
	if (ft_strchr("oOuUxXbt", (int)c) != NULL)
		nb = 2;
	if (ft_strchr("sSp", (int)c) != NULL)
		nb = 3;
	return (nb);
}
