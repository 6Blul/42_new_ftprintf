/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spochez <spochez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 03:12:37 by spochez           #+#    #+#             */
/*   Updated: 2015/02/12 14:25:23 by spochez          ###   ########.fr       */
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
	char				*test;//Je content
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
	long int			dd;//D long signed decimal
	long unsigned int 	uu;//U long unsigned 
	long unsigned int 	xx;//X long unsigned hexa
	long unsigned int 	oo;//O long unsigned octal
	long int 			ld;// long int pour comparer avec 'D'
	char				*s;//s char *
	char				*p;//p void *
	char				c;//c char
	char				*retour;//teste le retour de ft_printf
	char				*retour1;//teste le retour de printf
	int					res;//associe a "retour"
	int					res1;//associe a "retour1"

	retour = "Test du retour de ft_printf : ";
	retour1 = "Test du retour de printf : ";
	test = "Test de :";
	u = 3554;
	x = 834444444;
	o = 42;
	lu = 10212;
	lx = 3609098989808;
	lo = 27098989896;
	bi = 478;
	ter = 890;
	i = -4250909;
	d = 0;
	dd = 90102030;
	uu = 10212;
	xx = 3609098989808;
	oo = 27098989896;
	ld = 90102030;
	s = "Un enoooorme chat bleu";
	p = "je oui je oui je oui";
	c = 'L';


	printf("\n%s flag 'u'\n", test);
	ft_printf("%u", u);
	ft_printf("\n");
	printf("%u", u);
	printf("\n");
	ft_printf("Test du flag '0' : [%0u], [%015u], [%04u]\n", u, u, u);
	printf("Test du flag '0' : [%0u], [%015u], [%04u]\n\n", u, u, u);
	ft_printf("Test du flag '-' et de la longueur minimale du champ : [%18u], [%3u], [%-22u], [%3u]\n", u, u, u, u);
	printf("Test du flag '-' et de la longueur minimale du champ : [%18u], [%3u], [%-22u], [%3u]\n\n", u, u, u, u);
	ft_printf("Test de la precision : [%.23u], [%.3u], [%.78u]\n", u, u, u);
	printf("Test de la precision : [%.23u], [%.3u], [%.78u]\n\n", u, u, u);
	res = ft_printf("Test de plusieurs flags sur le meme argument : [%-18.4u], [%-8u], [%15.7u]\n", u, u, u);
	res1 = printf("Test de plusieurs flags sur le meme argument : [%-18.4u], [%-8u], [%15.7u]\n\n\n", u, u, u);
	printf("%s%i\n", retour, res);
	printf("%s%i\n\n", retour1, res1 - 2);


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
	res = ft_printf("Test de plusieurs flags sur le meme argument : [%-18.4lx], [%-8lx], [%15.7lx]\n", lx, lx, lx);
	res1 = printf("Test de plusieurs flags sur le meme argument : [%-18.4lx], [%-8lx], [%15.7lx]\n\n\n", lx, lx, lx); 
	printf("%s%i\n", retour, res);
	printf("%s%i\n\n", retour1, res1 - 2);


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


	printf("\n%s flag 'D' (comparaison avec ld)\n", test);
	ft_printf("Original = [%D]\n", dd);
	printf("Original = [%ld]\n\n", ld);
	ft_printf("Test du flag ' ' : [% D]\n", dd);
	printf("Test du flag ' ' : [% ld]\n\n", ld);
	ft_printf("Test du flag '+' : [%+D]\n", dd);
	printf("Test du flag '+' : [%+ld]\n\n", ld);
	ft_printf("Test du flag '-' et de la long minimale du champ : [%12D] - [%-12D]\n", dd, dd);
	printf("Test du flag '-' et de la long minimale du champ : [%12ld] - [%-12ld]\n\n", ld, ld);
	ft_printf("Test de la precision : [%.1D] - [%.5D] - [%.10D] - [%.0D]\n", dd, dd, dd, dd);
	printf("Test de la precision : [%.1ld] - [%.5ld] - [%.10ld] - [%.0ld]\n\n", ld, ld, ld, ld);
	ft_printf("Tests multiples : [%-12.15D] - [%+20D] - [%8.15D] - [% .14D] - [% 14D] - [% 14.D]\n", dd, dd, dd, dd, dd, dd);
	printf("Tests multiples : [%-12.15ld] - [%+20ld] - [%8.15ld] - [% .14ld] - [% 14ld] - [% 14.ld]\n\n\n", ld, ld, ld, ld, ld, ld);

	printf("\n%s flag 'U' (comparaison avec lu)\n", test);
	ft_printf("Original = [%U]\n", uu);
	printf("Original = [%lu]\n\n", lu);
	ft_printf("Test du flag '0' : [%0U], [%015U], [%04U]\n", uu, uu, uu);
	printf("Test du flag '0' : [%0lu], [%015lu], [%04lu]\n\n", lu, lu, lu);
	ft_printf("Test du flag '-' et de la long. minimale du champ : [%18U], [%3U], [%-22U], [%3U]\n", uu, uu, uu, uu);
	printf("Test du flag '-' et de la long. minimale du champ : [%18lu], [%3lu], [%-22lu], [%3lu]\n\n", lu, lu, lu, lu);
	ft_printf("Test de la precision : [%.23U], [%.3U], [%.78U]\n", uu, uu, uu);
	printf("Test de la precision : [%.23lu], [%.3lu], [%.78lu]\n\n", lu, lu, lu);
	ft_printf("Test de plusieurs flags sur le meme argument : [%-18.4U], [%-8U], [%15.7U]\n", uu, uu, uu);
	printf("Test de plusieurs flags sur le meme argument : [%-18.4lu], [%-8lu], [%15.7lu]\n\n\n", lu, lu, lu); 

	printf("\n%s flag 'X' (comparaison avec lx)\n", test);
	ft_printf("%X\n", 42);
	printf("Original = [%lx]\n\n", lx);
	ft_printf("Test du flag '0' : [%0X], [%015X], [%04X]\n", xx, xx, xx);
	printf("Test du flag '0' : [%0lx], [%015lx], [%04lx]\n\n", lx, lx, lx);
	ft_printf("Test du flag '-' et de la long. minimale du champ : [%18X], [%3X], [%-22X], [%3X]\n", xx, xx, xx, xx);
	printf("Test du flag '-' et de la long. minimale du champ : [%18lx], [%3lx], [%-22lx], [%3lx]\n\n", lx, lx, lx, lx);
	ft_printf("Test de la precision : [%.23X], [%.3X], [%.78X]\n", xx, xx, xx);
	printf("Test de la precision : [%.23lx], [%.3lx], [%.78lx]\n\n", lx, lx, lx);
	res = ft_printf("Test de plusieurs flags sur le meme argument : [%-18.4X], [%-8X], [%15.7X]\n", xx, xx, xx);
	res1 = printf("Test de plusieurs flags sur le meme argument : [%-18.4lx], [%-8lx], [%15.7lx]\n\n\n", lx, lx, lx); 
	printf("%s%i\n", retour, res);
	printf("%s%i\n\n", retour1, res1 - 2);

	printf("\n%s flag 'O' (comparaison avec lo)\n", test);
	res = ft_printf("Original = [%O]\n", oo);
	res1 = printf("Original = [%lo]\n\n", lo);
	ft_printf("Test du flag '0' : [%0O], [%015O], [%04O]\n", oo, oo, oo);
	printf("Test du flag '0' : [%0lo], [%015lo], [%04lo]\n\n", lo, lo, lo);
	ft_printf("Test du flag '-' et de la long. minimale du champ : [%18O], [%3O], [%-22O], [%3O]\n", oo, oo, oo, oo);
	printf("Test du flag '-' et de la long. minimale du champ : [%18lo], [%3lo], [%-22lo], [%3lo]\n\n", lo, lo, lo, lo);
	ft_printf("Test de la precision : [%.23O], [%.3O], [%.78O]\n", oo, oo, oo);
	printf("Test de la precision : [%.23lo], [%.3lo], [%.78lo]\n\n", lo, lo, lo);
	res = ft_printf("Test de plusieurs flags sur le meme argument : [%-18.4O], [%-8O], [%15.7O]\n", oo, oo, oo);
	res1 = printf("Test de plusieurs flags sur le meme argument : [%-18.4lo], [%-8lo], [%15.7lo]\n\n\n", lo, lo, lo); 
	printf("%s%i\n", retour, res);
	printf("%s%i\n\n", retour1, res1 - 2);


	printf("\n%s flag 's'\n", test);
	ft_printf("%s", s);
	printf("\n");
	printf("%s", s);
	printf("\n");
	ft_printf("Test de la long. minimale et du flag '-' : \n[%12s]\n[%1s]\n[%25s]\n[%-25s]\n[%-12s]\n", s, s, s, s, s);
	printf("Test de la long. minimale et du flag '-' : \n[%12s]\n[%1s]\n[%25s]\n[%-25s]\n[%-12s]\n\n", s, s, s, s, s);
	ft_printf("Test de la precision : [%.25s]\n[%.5s]\n[%.s]\n", s, s, s);
	printf("Test de la precision : [%.25s]\n[%.5s]\n[%.s]\n\n", s, s, s);
	res = ft_printf("Tests multiples : [%15.5s]\n[%5.15s]\n[%30.5s]\n[%5.30s]\n", s, s, s, s);
	res1 = printf("Tests multiples : [%15.5s]\n[%5.15s]\n[%30.5s]\n[%5.30s]\n\n\n", s, s, s, s);
	printf("%s%i\n", retour, res);
	printf("%s%i\n\n", retour1, res1 - 2);




	printf("\n%s flag 'p'\n", test);
	ft_printf("Original = [%p]\n", p);
	printf("Original = [%p]\n\n", p);
	res = ft_printf("Test de la longueur minimale et du flag '-' : \n[%12p]\n[%1p]\n[%25p]\n[%-25p]\n[%-1p]\n[%-12p]\n", p, p, p, p, p, p);
	res1 = printf("Test de la longueur minimale et du flag '-' : \n[%12p]\n[%1p]\n[%25p]\n[%-25p]\n[%-1p]\n[%-12p]\n\n\n", p, p, p, p, p, p);
	printf("%s%i\n", retour, res);
	printf("%s%i\n\n", retour1, res1 - 2);


	printf("\n%s flags 'b' && 't'\n", test);
	printf("Nombre d'origine : BI = %u - TER = %u\n", bi, ter);
	ft_printf("Nombre d'origine : BI = %u - TER = %u\n", bi, ter);
	ft_printf("Conversion : BI  = [%b] - TER = [%t]\n\n\n", bi, ter);
	ft_printf("Tests avec flags : \nBI =  [%34b] [%.0b] [%.20b]\nTER = [%34t] [%.0t] [%.20t]\n\n\n", bi, bi, bi, ter, ter, ter);


	printf("\n%s flag 'c'\n", test);
	res = ft_printf("Char d'origine : [%c]\n", c);
	res1 = printf("Char d'origine : [%c]\n\n\n", c);
	printf("%s%i\n", retour, res);
	printf("%s%i\n\n", retour1, res1 - 2);

	char				hhi;
	unsigned char		hhu;
	short				hi;
	unsigned short		hu;
	long				li;
	unsigned long		ulu;
	long long			lli;
	unsigned long long	llu;
	intmax_t			imt;
	uintmax_t			uimt;
	size_t				st;
	unsigned long 		lb;
	unsigned long 		lt;
	char 				*pd;
	unsigned long 		gropd;


	pd = NULL;
	hhi = 'C';
	hhu = 'C';
	hi = -15;
	hu = 25;
	li = -947495550;
	ulu = 0;
	lli = -123456785999;
	llu = ULONG_MAX;
	imt = -777776667677;
	uimt = 9999976767799;
	st = -670;
	lt = 943874;
	lb = 484885;
	gropd = ULONG_MAX;
	printf("\n%s flags 'l' 'll' 'h' 'hh' 'z'\n", test);
	ft_printf("Test des flags h/hh : [%hi] [%hu] [%hhi] [%hhu]\n", hi, hu, hhi, hhu);
	printf("Test des flags h/hh : [%hi] [%hu] [%hhi] [%hhu]\n", hi, hu, hhi, hhu);
	res = ft_printf("Test des flags l/ll : [%li] [%lu] [%lli] [%llu]\n", li, ulu, lli, llu);
	res1 = printf("Test des flags l/ll : [%li] [%lu] [%lli] [%llu]\n", li, ulu, lli, llu);
	ft_printf("Test des flags j/z : [%ji] [%ju] [%zi] [%zu]\n", imt, uimt, st, st);
	printf("Test des flags j/z : [%ji] [%ju] [%zi] [%zu]\n\n", imt, uimt, st, st);
	
	printf("Test du flag 'l' sur 't' && 'b'\n");
	ft_printf("Tests sur 'b' :  %lb\n", lb);
	ft_printf("Tests sur 't' :  %lt\n\n", lt);

	printf("Test d'un pointeur null avec 's' puis 'p'\n");
	printf("Suce : %s\n", pd);
	ft_printf("Suce : %s\n", pd);
	printf("Suce : %p\n", pd);
	ft_printf("Suce : %p\n\n", pd);

	printf("Test de deux pourcents && multi pourcent (non existant dans printf)\n");
	res = ft_printf("%%");
	printf("\n");
	res1 = printf("%%");
	printf("\n");
	printf("%s%i\n", retour, res);
	printf("%s%i\n", retour1, res1);
	res = ft_printf("%%%%%%%%%%");
	printf("\n");
	res = ft_printf("%");
	printf("\n");
	res = ft_printf("% Zoooo\n");
	printf("\n");
	res = ft_printf("{%}\n");
	printf("\n");
	res = ft_printf("{% %}\n");

	ft_printf("Bonjour %CAu revoir", 945);
	ft_printf("\n");
	res = ft_printf("%C", 945);
	printf("\nres = %i", res);
	ft_printf("\n");

	res = ft_printf("%c%c%c%c%c", 'A', 'B', 'C', 'D', 'E');
	printf("\nres = %i", res);
	ft_printf("\n");
	printf("\nBONJOUR :\n");
	ft_printf("%lo", gropd);
	ft_printf("\n");
	printf("%lo", gropd);
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("\n");


	return (0);
}
