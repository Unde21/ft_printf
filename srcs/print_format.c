/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:34:24 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/14 21:35:22 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>

int	check_format(va_list params, char  format)
{
	int	count;

	count = 0;
	if (format == 'd' || format == 'i')
		count += ft_putnbr_base(va_arg(params, int), 10, count);
	else if (format == 'c')
		count += ft_putchar(va_arg(params, int));
	else if (format == 's')  
		count += ft_putstr(va_arg(params, const char *));
	else if (format == 'p')
	{
		write(1, "0x", 2);
	 	count += ft_putnbr_base(va_arg(params, long), 16, count);
	}	
	else if (format == 'u')
	 	count +=  ft_putnbr_base(va_arg(params, unsigned int), 10, count);
	else if (format == 'x')
		count += ft_putnbr_base(va_arg(params, unsigned int), 16, count);
 	else if (format == 'X')
 		count += ft_putnbr_base_uppercase(va_arg(params, unsigned int), 16, count);
	else if (format == '%')
		count += ft_putchar('%');
		
	return (count);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char s1[] = "Hello les amis";
// 	int		nb = -42;
// 	int		hexa = 232;
// 	char	c = 'a';
// 	int		n = -42;
	
// 	ft_printf("s:%s, Aloaaaaa d:%d     c:%c    i:%i     u:%u      p:'%p'      :%%     x:%x    X:%X\n", s1, nb, c, nb, n, s1, hexa, hexa);		
// 	   printf("s:%s, Aloaaaaa d:%d     c:%c    i:%i     u:%u      p:'%p'      :%%     x:%x    X:%X\n", s1, nb, c, nb, n, s1, hexa, hexa);
// }
