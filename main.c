/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 03:12:37 by spochez           #+#    #+#             */
/*   Updated: 2015/02/05 06:00:32 by spochez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Pour chaque conversion, on compare ft_printf avec la vraie fonction.
// Tous les flags possibles dans la vraie fonction sont testes.
// Pour chaque test, la premiere ligne est la sortie de ft_printf et la deuxieme celle de printf.

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		main(void)
{
	char				*test;
	unsigned int		o;//o unsigned octal
	unsigned int		x;//x unsigned hexadecimal
	unsigned int		u;//u unsigned decimal
	long unsigned int 	lu; //lu long unsigned decimal
	long unsigned int	lx;	//X unsigned decimal (as X)
	long unsigned int	lo;	//lo long unsigned octal
	unsigned int		bi;//b -> A tester sans le vrai PRINTF
	unsigned int		ter;//t -> A tester sans le vrai PRINTF
	int					i;//i signed decimal
	int					d;//d signed decimal
//	long int			dd;//D long signed decimal
	char				*s;//s char *
	char				*p;//p void *
	char				c;//c char
	char				*retour;
	char				*retour1;
	int					res;
	int					res1;

	retour = "Test du retour de ft_printf : ";
	retour1 = "Test du retour de printf : ";
	test = "Test de :";
	u = 3554;
	x = 834;
	o = 304;
	lu = 10212;
	lx = 368;
	lo = 27056;
	bi = 478;
	ter = 890;
	i = 0;
	d = 155;
	//dd = 90102030;
	s = "un enooorme chat bleu";
	p = "je oui je oui je oui";
	c = 'L';


	printf("\n%s flag 'u'\n", test);
	ft_printf("Original = [%u]\n", u);
	printf("Original = [%u]\n\n", u);
	ft_printf("Test du flag '0' : [%0u], [%015u], [%04u]\n", u, u, u);
	printf("Test du flag '0' : [%0u], [%015u], [%04u]\n\n", u, u, u);
	ft_printf("Test du flag '-' et de la longueur minimale du champ : [%18u], [%3u], [%-22u], [%3u]\n", u, u, u, u);
	printf("Test du flag '-' et de la longueur minimale du champ : [%18u], [%3u], [%-22u], [%3u]\n\n", u, u, u, u);
	ft_printf("Test de la precision : [%.23u], [%.3u], [%.78u]\n", u, u, u);
	printf("Test de la precision : [%.23u], [%.3u], [%.78u]\n\n", u, u, u);
	ft_printf("Test de plusieurs flags sur le meme argument : [%-18.4u], [%-8u], [%15.7u]\n", u, u, u);
	printf("Test de plusieurs flags sur le meme argument : [%-18.4u], [%-8u], [%15.7u]\n\n\n", u, u, u);



	printf("\n%s flag 'x'\n", test);
	ft_printf("Original = [%x]\n", x);
	printf("Original = [%x]\n\n", x);
	ft_printf("Test du flag '#' : [%#x]\n", x);
	printf("Test du flag '#' : [%#x]\n\n", x);
	ft_printf("Test du flag '0' : [%0x], [%015x], [%04x]\n", x, x, x);
	printf("Test du flag '0' : [%0x], [%015x], [%04x]\n\n", x, x, x);
	ft_printf("Test du flag '-' et de la longueur minimale du champ : [%18x], [%4x], [%-22x], [%3x]\n", x, x, x, x);
	printf("Test du flag '-' et de la longueur minimale du champ : [%18x], [%4x], [%-22x], [%3x]\n\n", x, x, x, x);
	ft_printf("Test de la precision : [%.23x], [%.3x], [%.78x]\n", x, x, x);
	printf("Test de la precision : [%.23x], [%.3x], [%.78x]\n\n", x, x, x);
	ft_printf("Test de plusieurs flags sur le meme argument : [%#043x], [%.18x], [%#-23x]\n", x, x, x);
	ft_printf("Test de plusieurs flags sur le meme argument : [%#043x], [%.18x], [%#-23x]\n\n\n", x, x, x);



	printf("\n%s flag 'o'\n", test);
	ft_printf("Original = [%o]\n", o);
	printf("Original = [%o]\n\n", o);
	ft_printf("Test du flag '#' : [%#o]\n", o);
	printf("Test du flag '#' : [%#o]\n\n", o);
	ft_printf("Test du flag '0' : [%0o], [%015o], [%04o]\n", o, o, o);
	printf("Test du flag '0' : [%0o], [%015o], [%04o]\n\n", o, o, o);
	ft_printf("Test du flag '-' et de la longueur minimale du champ : [%18o], [%3o], [%-22o], [%3o]\n", o, o, o, o);
	printf("Test du flag '-' et de la longueur minimale du champ : [%18o], [%3o], [%-22o], [%3o]\n\n", o, o, o, o);
	ft_printf("Test de la precision : [%.23o], [%.3o], [%.78o]\n", o, o, o);
	printf("Test de la precision : [%.23o], [%.3o], [%.78o]\n\n", o, o, o);
	ft_printf("Test de plusieurs flags sur le meme argument : [%#43o], [%.18o], [%#-23o]\n", o, o, o);
	ft_printf("Test de plusieurs flags sur le meme argument : [%#43o], [%.18o], [%#-23o]\n\n\n", o, o, o);



	printf("\n%s flag 'lu'\n", test);
	ft_printf("Original = [%lu]\n", lu);
	printf("Original = [%lu]\n\n", lu);
	ft_printf("Test du flag '0' : [%0lu], [%015lu], [%04lu]\n", lu, lu, lu);
	printf("Test du flag '0' : [%0lu], [%015lu], [%04lu]\n\n", lu, lu, lu);
	ft_printf("Test du flag '-' et de la long. minimale du champ : [%18lu], [%3lu], [%-22lu], [%3lu]\n", lu, lu, lu, lu);
	printf("Test du flag '-' et de la long. minimale du champ : [%18lu], [%3lu], [%-22lu], [%3lu]\n\n", lu, lu, lu, lu);
	ft_printf("Test de la precision : [%.23lu], [%.3lu], [%.78lu]\n", lu, lu, lu);
	printf("Test de la precision : [%.23lu], [%.3lu], [%.78lu]\n\n", lu, lu, lu);
	ft_printf("Test de plusieurs flags sur le meme argument : [%-18.4lu], [%-8lu], [%15.7lu]\n", lu, lu, lu);
	printf("Test de plusieurs flags sur le meme argument : [%-18.4lu], [%-8lu], [%15.7lu]\n\n\n", lu, lu, lu); 



	printf("\n%s flag 'lx'\n", test);
	ft_printf("Original = [%lx]\n", lx);
	printf("Original = [%lx]\n\n", lx);
	ft_printf("Test du flag '#' : [%#lx]\n", lx);
	printf("Test du flag '#' : [%#lx]\n\n", lx);
	ft_printf("Test du flag '0' : [%0lx], [%015lx], [%04lx]\n", lx, lx, lx);
	printf("Test du flag '0' : [%0lx], [%015lx], [%04lx]\n\n", lx, lx, lx);
	ft_printf("Test du flag '-' et de la long. minimale du champ : [%18lx], [%3lx], [%-22lx], [%3lx]\n", lx, lx, lx, lx);
	printf("Test du flag '-' et de la long. minimale du champ : [%18lx], [%3lx], [%-22lx], [%3lx]\n\n", lx, lx, lx, lx);
	ft_printf("Test de la precision : [%.23lx], [%.3lx], [%.78lx]\n", lx, lx, lx);
	printf("Test de la precision : [%.23lx], [%.3lx], [%.78lx]\n\n", lx, lx, lx);
	ft_printf("Test de plusieurs flags sur le meme argument : [%-18.4lx], [%-8lx], [%15.7lx]\n", lx, lx, lx);
	printf("Test de plusieurs flags sur le meme argument : [%-18.4lx], [%-8lx], [%15.7lx]\n\n\n", lx, lx, lx); 



	printf("\n%s flag 'lo'\n", test);
	ft_printf("Original = [%lo]\n", lo);
	printf("Original = [%lo]\n\n", lo);
	ft_printf("Test du flag '#' : [%#lo]\n", lo);
	printf("Test du flag '#' : [%#lo]\n\n", lo);
	ft_printf("Test du flag '0' : [%0lo], [%015lo], [%04lo]\n", lo, lo, lo);
	printf("Test du flag '0' : [%0lo], [%015lo], [%04lo]\n\n", lo, lo, lo);
	ft_printf("Test du flag '-' et de la long. minimale du champ : [%18lo], [%3lo], [%-22lo], [%3lo]\n", lo, lo, lo, lo);
	printf("Test du flag '-' et de la long. minimale du champ : [%18lo], [%3lo], [%-22lo], [%3lo]\n\n", lo, lo, lo, lo);
	ft_printf("Test de la precision : [%.23lo], [%.3lo], [%.78lo]\n", lo, lo, lo);
	printf("Test de la precision : [%.23lo], [%.3lo], [%.78lo]\n\n", lo, lo, lo);
	ft_printf("Test de plusieurs flags sur le meme argument : [%-18.4lo], [%-8lo], [%15.7lo]\n", lo, lo, lo);
	printf("Test de plusieurs flags sur le meme argument : [%-18.4lo], [%-8lo], [%15.7lo]\n\n\n", lo, lo, lo); 



	/*printf("\n%s flag 'bi'\n", test);



	printf("\n%s flag 'ter'\n", test);*/



	printf("\n%s flag 'i'\n", test);
	ft_printf("Original = [%i]\n", i);
	printf("Original = [%i]\n\n", i);
	ft_printf("Test du flag ' ' : [% i]\n", i);
	printf("Test du flag ' ' : [% i]\n\n", i);
	ft_printf("Test du flag '+' : [%+i]\n", i);
	printf("Test du flag '+' : [%+i]\n\n", i);
	ft_printf("Test du flag '-' et de la long minimale du champ : [%12i] - [%-12i]\n", i, i);
	printf("Test du flag '-' et de la long minimale du champ : [%12i] - [%-12i]\n\n", i, i);
	ft_printf("Test de la precision : [%.1i] - [%.5i] - [%.15i]\n", i, i, i);
	printf("Test de la precision : [%.1i] - [%.5i] - [%.15i]\n\n", i, i, i);
	ft_printf("Tests multiples : [%-12.30i] - [%+20i] - [%8.15i] - [% .14i] - [% 14i] - [% 14.i]\n", i, i, i, i, i, i);
	printf("Tests multiples : [%-12.30i] - [%+20i] - [%8.15i] - [% .14i] - [% 14i] - [% 14.i]\n\n\n", i, i, i, i, i, i);

	printf("\n%s flag 'd'\n", test);
	ft_printf("Original = [%d]\n", d);
	printf("Original = [%d]\n\n", d);
	ft_printf("Test du flag ' ' : [% d]\n", d);
	printf("Test du flag ' ' : [% d]\n\n", d);
	ft_printf("Test du flag '+' : [%+d]\n", d);
	printf("Test du flag '+' : [%+d]\n\n", d);
	ft_printf("Test du flag '-' et de la long minimale du champ : [%12d] - [%-12d]\n", d, d);
	printf("Test du flag '-' et de la long minimale du champ : [%12d] - [%-12d]\n\n", d, d);
	ft_printf("Test de la precision : [%.1d] - [%.5d] - [%.10d] - [%.0d]\n", d, d, d, d);
	printf("Test de la precision : [%.1d] - [%.5d] - [%.10d] - [%.0d]\n\n", d, d, d, d);
	ft_printf("Tests multiples : [%-12.15d] - [%+20d] - [%8.15d] - [% .14d] - [% 14d] - [% 14.d]\n", d, d, d, d, d, d);
	printf("Tests multiples : [%-12.15d] - [%+20d] - [%8.15d] - [% .14d] - [% 14d] - [% 14.d]\n\n\n", d, d, d, d, d, d);

	//printf("\n%s flag 'D'\n", test);



	printf("\n%s flag 's'\n", test);
	ft_printf("Original = [%s]\n", s);
	printf("Original = [%s]\n\n", s);
	ft_printf("Test de la long. minimale et du flag '-' : \n[%12s]\n[%1s]\n[%25s]\n[%-25s]\n[%-12s]\n", s, s, s, s, s);
	printf("Test de la long. minimale et du flag '-' : \n[%12s]\n[%1s]\n[%25s]\n[%-25s]\n[%-12s]\n\n", s, s, s, s, s);
	ft_printf("Test de la precision : [%.25s]\n[%.5s]\n[%.s]\n", s, s, s);
	printf("Test de la precision : [%.25s]\n[%.5s]\n[%.s]\n\n", s, s, s);
	res = ft_printf("Tests multiples : [%15.5s]\n[%5.15s]\n[%30.5s]\n[%5.30s]\n", s, s, s, s);
	res1 = printf("Tests multiples : [%15.5s]\n[%5.15s]\n[%30.5s]\n[%5.30s]\n\n\n", s, s, s, s);
	printf("%s%i\n", retour, res);
	printf("%s%i\n\n", retour1, res1);



	printf("\n%s flag 'p'\n", test);
	ft_printf("Original = [%p]\n", p);
	printf("Original = [%p]\n\n", p);
	ft_printf("Test de la longueur minimale et du flag '-' : \n[%12p]\n[%1p]\n[%25p]\n[%-25p]\n[%-1p]\n[%-12p]\n", p, p, p, p, p, p);
	printf("Test de la longueur minimale et du flag '-' : \n[%12p]\n[%1p]\n[%25p]\n[%-25p]\n[%-1p]\n[%-12p]\n\n\n", p, p, p, p, p, p);



	printf("\n%s flag 'b' && 's'\n", test);
	printf("Nombre d'origine : BI = %u - TER = %u\n", bi, ter);
	ft_printf("Nombre d'origine : BI = %u - TER = %u\n", bi, ter);
	ft_printf("Conversion : BI = [%b] - TER = [%t]\n\n\n", bi, ter);
	
	
	
	printf("\n%s flag 'c'\n", test);
	ft_printf("Char d'origine : [%c]\n", c);
	printf("Char d'origine : [%c]\n\n\n", c);
	return (0);
}
