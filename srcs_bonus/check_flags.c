/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 02:07:34 by samaouch          #+#    #+#             */
/*   Updated: 2024/12/02 10:33:29 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int	check_flg_format(va_list *params, char *format, t_flags *flags)
{
	int	pos_next;

	pos_next = pos_next_format(format);
	if (*(format + pos_next) == 'x')
		print_x(params, flags);
	if (*(format + pos_next) == 'X')
		print_upper_x(params, flags);
	if (*(format + pos_next) == 'd' || *(format + pos_next) == 'i')
		print_nb(params, flags);
	if (*(format + pos_next) == 'u')
		print_unb(params, flags);
	if (*(format + pos_next) == 'p')
		print_p(params, flags);
	if (*(format + pos_next) == 's')
		print_s(params, flags);
	if (*(format + pos_next) == 'c')
		print_c(params, flags);
	if (*(format + pos_next) == '%')
	{
		print_char('%');
		flags->count += 1;
	}
	return (pos_next);
}

int	check_format(va_list *params, char format)
{
	int		count;

	count = 0;
	if (format == 'd' || format == 'i')
		count += print_nbr(va_arg(*params, int), 0, count);
	else if (format == 'c')
		count += print_char(va_arg(*params, int));
	else if (format == 's')
		count += print_str(va_arg(*params, char *));
	else if (format == 'p')
		count += print_addr(va_arg(*params, unsigned long), 0, 0);
	else if (format == 'u')
		count += print_nbr(va_arg(*params, unsigned int), 1, count);
	else if (format == 'x')
		count += print_hexa(va_arg(*params, unsigned int), LOWER_BASE, count);
	else if (format == 'X')
		count += print_hexa(va_arg(*params, unsigned int), UPPER_BASE, count);
	else if (format == '%')
		count += print_char('%');
	return (count);
}

int	pos_next_format(char *format)
{
	int	pos;

	pos = 0;
	while (format[pos] != '\0' && !valid_format(format[pos]))
		++pos;
	return (pos);
}

bool	valid_format(char c)
{
	return (c == 'c' || c == 'd' || c == 'i' || c == 'p' || c == 'x' || c == 'X'
		|| c == 'u' || c == 's' || c == '%');
}

bool	is_flags(t_flags *flags)
{
	if (flags->less || flags->sign || flags->zero
		|| flags->point || flags->space || flags->prefix || flags->padding != -1
		|| flags->precision != -1)
		return (true);
	return (false);
}
