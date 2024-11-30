/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:11:07 by sammy             #+#    #+#             */
/*   Updated: 2024/11/30 20:00:59 by samaouch         ###   ########lyon.fr   */
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
	a = ft_printf("{%-163.23s}" , NULL);
	printf("\n");
	b = printf("{%-163.23s}" , NULL);
	// printf("\n a %d   b %d\n", a, b);
	// printf("\n");
	// a = ft_printf("%7.5s", "tubular");
	// printf("\n");
	// b = printf("%7.5s", "tubular");
	printf("\n a %d   b %d", a, b);
}
