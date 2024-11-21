/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 02:07:34 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/21 04:49:36 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf_bonus.h"
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
		print_X(params, flags);
	// if (*(format + pos_next) == 'd' || *(format + pos_next) == 'i')
	// 	print_nb(params, *(format + pos_next));
	// if (*(format + pos_next) == 'u')
	// 	print_unsigned_nb(params, *(format + pos_next));
	if (*(format + pos_next) == 'p')
		print_p(params, flags);
	// if (*(format + pos_next) == 's')
	// 	print_s(params, *(format + pos_next));
	if (*(format + pos_next) == 'c')
		print_c(params, flags);
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
