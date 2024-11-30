/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:11:07 by sammy             #+#    #+#             */
/*   Updated: 2024/11/30 20:09:13 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int a = 0;
	int b = 0;
	// char s[] = "hello world";
	//  a = 0; //= ft_printf("%.7s%.2s", "hello", "world");
	// printf("\n");
	// b = 0; //= printf("%.7s%.2s", "hello", "world");
	// printf("\n a : %d  b : %d\n", a, b);
	a = ft_printf("{%-163.23s}" , " SA VA PASSER");
	printf("\n");
	b = printf("{%-163.23s}" , " SA VA PASSER");
	printf("\n");
	printf("\n a %d   b %d\n", a, b);
	a = ft_printf("aldadlalda %d  : %u %s %c %x %%", 42, -454, "Hello", 'A', 255);
	printf("\n");
	b = printf("aldadlalda %d  : %u %s %c %x %%", 42, -454, "Hello", 'A', 255);
	printf("\n");
	// printf("\n a %d   b %d\n", a, b);
	// printf("\n");
	// a = ft_printf("%7.5s", "tubular");
	// printf("\n");
	// b = printf("%7.5s", "tubular");
	printf("\n a %d   b %d", a, b);
}
