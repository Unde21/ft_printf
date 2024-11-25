/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammy <sammy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:11:07 by sammy             #+#    #+#             */
/*   Updated: 2024/11/25 13:22:17 by sammy            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	main(void)
{
	//int a = 0;
	// char s[] = "hello world";
	ft_printf("'%010u", 355);  // test avec 0
	ft_printf("\n");
	printf("'%010u", 355);
	// printf("\n% 10d", 25);
}
// cc -Wall -Wextra -Werror -I includes -L. -lftprintf main.c -o test
/*
	# flags : sign "0x" for %x and "0X" for %X (non compatible avec : '+')
	0 flags : valeur complete a gauche par des 0, si '0' && '+'
		-> '0' ignored si une precision est donne avec un chiffre '0' est ignore
	- flags : ajuste a gauche par des espaces, (nb precise) "%-10d", 42
		-> 8 espaces a droite apres le nb
	' ' flags : Un espace doit être laissé avant un nombre positif (ou une chaîne vide) produit par une conversion signée. si '+' espace
		-> ignored
	'+' flags : Un signe (+ ou
		-) doit toujours être placé avant un nombre produit par une conversion signée.
				Par défaut,
					un signe n'est utilisé que pour les nombres négatifs.  Un
					+ remplace ' ' si les deux sont utilisés
	'.' flags : %10.0d, 42 -> 8 espaces puis 42 , %10.10, 42 ->, 8 '0' 42 
		%12.10, 42 -> 2 espaces && 8 '0' 42 compatible avec : '+, #,
		0' '#' doit etre devant '.'

		' ' - #/+ 0 .
*/
// c = number et '-'
// p = number et '-'
// s = number et '-'  et '.'


// u = number et '.' '-' '0'
// d et i = '0' '-' '+' ' ' '.'


// gerer le parsing ex : sur 'x' ft_printf("%010 x", 255); / Ordre des flags a parser
// ajouter un call fonction a l entree de check_flg_format pour gerer les cas impossible et juste print
// aller voir les atribute pour gerer les error 
// gerer le % seul pour return -1 (start count a - 1)
// verifier les types dans count_hex_digits ->addr
// voir si il faut bouger la fonction adding_prefix 
