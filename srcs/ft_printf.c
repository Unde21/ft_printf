/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:00:00 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/16 13:27:13 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	va_list	params;
	int		count;

	count = 0;
	va_start(params, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			++count;
		}
		else if (*format == '%')
		{
			++format;
			count += check_format(params, *format);
		}
		++format;
	}
	va_end(params);
	return (count);
}

int	ft_putstr(char *str)
{
	size_t	i;
	int		count;

	count = 0;
	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		++count;
		++i;
	}
	return (count);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
