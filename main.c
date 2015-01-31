/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 03:12:37 by spochez           #+#    #+#             */
/*   Updated: 2015/01/31 04:01:02 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Pour chaque conversion, on compare ft_printf avec la vraie fonction.
// Tous les flags possibles dans la vraie fonction sont testes.
// Pour chaque test, la premiere ligne est la sortie de ft_printf et la deuxieme celle de printf.

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char				*test;
	unsigned int		o;//o unsigned octal
	unsigned int		x;//x unsigned hexadecimal
	unsigned int		u;//u unsigned decimal
	/*long unsigned int 	lu; //lu long unsigned decimal
	unsigned int		lx;	//X unsigned decimal (as x)
	long unsigned int	lo;	//lo long unsigned octal
	unsigned int		bi;//b -> A tester sans le vrai PRINTF
	unsigned int		ter;//t -> A tester sans le vrai PRINTF
	int					i;//i signed decimal
	int					d;//d signed decimal
	long int			dd;//D long signed decimal
	char				*s;//s char *
	char				*p;//p void *
	char				c;//c char*/

	test = "Test de :";
	u = 12950;
	x = 356;
	o = 8;
	/*lu = 1029384756;
	lx = 2468013579;
	lo = 1357924680;
	bi = 478;
	ter = 890;
	i = 340;
	d = 450;
	dd = 90102030;
	s = "un enooorme chat bleu";
	p = "je oui je oui je oui";
	c = 'L';*/

	printf("\n%s flag 'u'\n", test);
	ft_printf("Original = [%u]\n", u);
	printf("Original = [%u]\n", u);
	ft_printf("Test du flag '-' et de la longueur minimale du champ : [%45u], [%3u], [%-45u], [%3u]\n", u, u, u, u);
	printf("Test du flag '-' et de la longueur minimale du champ : [%45u], [%3u], [%-45u], [%3u]\n\n", u, u, u, u);
	ft_printf("Test de la precision : [%23u], [%3u], [%78u]\n", u, u, u);
	printf("Test de la precision : [%23u], [%3u], [%78u]\n\n", u, u, u);
	ft_printf("Test de plusieurs flags sur le meme argument : [%-45.4u], [%-8u], [%34.7u]\n", u, u, u);
	printf("Test de plusieurs flags sur le meme argument : [%-45.4u], [%-8u], [%34.7u]\n\n\n", u, u, u);
	
	printf("\n%s flag 'x'\n", test);
	ft_printf("Original = [%x]\n", x);
	printf("Original = [%x]\n", x);
	ft_printf("Test du flag '#' : [%#x]\n", x);
	printf("Test du flag '#' : [%#x]\n\n", x);
	ft_printf("Test du flag '0' : [%0x], [%034x], [%04x]\n", x, x, x);
	printf("Test du flag '0' : [%0x], [%034x], [%04x]\n\n", x, x, x);
	ft_printf("Test du flag '-' et de la longueur minimale du champ : [%45x], [%3x], [%-45x], [%3x]\n", x, x, x, x);
	printf("Test du flag '-' et de la longueur minimale du champ : [%45x], [%3x], [%-45x], [%3x]\n\n", x, x, x, x);
	ft_printf("Test de la precision : [%23x], [%3x], [%78x]\n", x, x, x);
	printf("Test de la precision : [%23x], [%3x], [%78x]\n\n", x, x, x);
	ft_printf("Test de plusieurs flags sur le meme argument : [%#43x], [%.45x], [%#-23x]\n", x, x, x);
	ft_printf("Test de plusieurs flags sur le meme argument : [%#43x], [%.45x], [%#-23x]\n\n\n", x, x, x);

	printf("\n%s flag 'o'\n", test);
	ft_printf("Original = [%o]\n", o);
	printf("Original = [%o]\n", o);
	ft_printf("Test du flag '#' : [%#o]\n", o);
	printf("Test du flag '#' : [%#o]\n\n", o);
	ft_printf("Test du flag '0' : [%0o], [%034o], [%04o]\n", o, o, o);
	printf("Test du flag '0' : [%0o], [%034o], [%04o]\n\n", o, o, o);
	ft_printf("Test du flag '-' et de la longueur minimale du champ : [%45o], [%3o], [%-45o], [%3o]\n", o, o, o, o);
	printf("Test du flag '-' et de la longueur minimale du champ : [%45o], [%3o], [%-45o], [%3o]\n\n", o, o, o, o);
	ft_printf("Test de la precision : [%23o], [%3o], [%78o]\n", o, o, o);
	printf("Test de la precision : [%23o], [%3o], [%78o]\n\n", o, o, o);
	ft_printf("Test de plusieurs flags sur le meme argument : [%#43o], [%.45o], [%#-23o]\n", o, o, o);
	ft_printf("Test de plusieurs flags sur le meme argument : [%#43o], [%.45o], [%#-23o]\n\n\n", o, o, o);


	/*printf("\n%s flag 'lu'\n", test);


	printf("\n%s flag 'X'\n", test);


	printf("\n%s flag 'lo'\n", test);


	printf("\n%s flag 'bi'\n", test);


	printf("\n%s flag 'ter'\n", test);


	printf("\n%s flag 'i'\n", test);


	printf("\n%s flag 'd'\n", test);


	printf("\n%s flag 'D'\n", test);


	printf("\n%s flag 's'\n", test);


	printf("\n%s flag 'p'\n", test);


	printf("\n%s flag 'c'\n", test);*/
	return (0);
}
