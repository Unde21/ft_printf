/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammy <sammy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:11:07 by sammy             #+#    #+#             */
/*   Updated: 2024/11/17 18:44:14 by sammy            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	main()
{
	char s1[] = "Hello world";
	ft_printf("Hello les amis %d, %p, %s,", 42, NULL, s1);
}