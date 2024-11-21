/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:11:07 by sammy             #+#    #+#             */
/*   Updated: 2024/11/21 02:27:59 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf_bonus.h"

int	main()
{
	//char s[] = "hello world";
	ft_printf("%#15x", 25545);
	ft_printf("\n");    
	printf("%#15x", 25545);
	//printf("\n% 10d", 25);
}


/*
	# flags : add "0x" for %x and "0X" for %X (non compatible avec : '+')
	0 flags : valeur complete a gauche par des 0, si '0' && '+' -> '0' ignored si une precision est donne avec un chiffre '0' est ignore
	- flags : ajuste a gauche par des espaces, (nb precise) "%-10d", 42 -> 8 espaces a droite apres le nb
	' ' flags : Un espace doit être laissé avant un nombre positif (ou une chaîne vide) produit par une conversion signée. si '+' espace -> ignored
	'+' flags : Un signe (+ ou -) doit toujours être placé avant un nombre produit par une conversion signée.  
				Par défaut, un signe n'est utilisé que pour les nombres négatifs.  Un + remplace ' ' si les deux sont utilisés
	'.' flags : %10.0d, 42 -> 8 espaces puis 42 , %10.10, 42 ->, 8 '0' 42  %12.10, 42 -> 2 espaces && 8 '0' 42 compatible avec : '+, #, 0' '#' doit etre devant '.'  

	 ' ' - #/+ 0 .
*/ 
// c = number et '-'
