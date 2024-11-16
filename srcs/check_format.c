/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:34:24 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/16 13:35:00 by samaouch         ###   ########lyon.fr   */
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
		count += ft_putnbr_base(va_arg(params, int), 0, count);
	else if (format == 'c')
		count += ft_putchar(va_arg(params, int));
	else if (format == 's')
		count += ft_putstr(va_arg(params, char *));
	else if (format == 'p')
	{
	 	count += ft_putaddr(va_arg(params, unsigned long), 0, 0);
	}	
	else if (format == 'u')
	 	count +=  ft_putnbr_base(va_arg(params, unsigned int), 1, count);
	else if (format == 'x')
		count += ft_puthexa(va_arg(params, unsigned int), 0, count);
 	else if (format == 'X')
 		count += ft_puthexa(va_arg(params, unsigned int), 1, count);
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}
