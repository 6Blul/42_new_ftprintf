/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 00:44:10 by spochez           #+#    #+#             */
/*   Updated: 2015/03/01 00:44:12 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	main(void)
{
	//ft_printf("%s %C %d %p %x %%", "bonjour ", L'該', 42, &free, 42);
	//ft_printf("%S", L"لحم خنزير");
	//ft_printf("%s %C %d %p %x %% %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
	//ft_printf("%C", L'猫');

	ft_printf("%C", L'δ');
	printf("\n");
	ft_printf("%C", L'요');
	printf("\n");
	ft_printf("%C", L'莨');
	printf("\n");
	ft_printf("%C", L'ي');
	printf("\n");
	printf("\n");
	ft_printf("%i", L'δ');
	printf("\n");
	ft_printf("%i", L'요');
	printf("\n");
	ft_printf("%i", L'莨');
	printf("\n");
	ft_printf("%i", L'ي');
	printf("\n");
	printf("\n");
	printf("%i", L'δ');
	printf("\n");
	printf("%i", L'요');
	printf("\n");
	printf("%i", L'莨');
	printf("\n");
	printf("%i", L'ي');
	printf("\n");
	return (0);
}