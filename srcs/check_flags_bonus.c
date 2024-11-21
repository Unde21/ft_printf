/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 02:07:34 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/21 02:00:47 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf_bonus.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int	check_flg_format(va_list *params, char *format, t_flags *flags)
{
	int		pos_next;

	pos_next = pos_next_format(format);
	if (*(format + pos_next) == 'x')
		print_x(params, flags);
	if (*(format + pos_next) == 'X')
		print_X(params, flags);
	// if (*(format + pos_next) == 'd' || *(format + pos_next) == 'i')
	// 	print_nb(params, *(format + pos_next));
	// if (*(format + pos_next) == 'u')
	// 	print_unsigned_nb(params, *(format + pos_next));
	// if (*(format + pos_next) == 'p')
	// 	print_p(params, *(format + pos_next));
	// if (*(format + pos_next) == 's')
	// 	print_s(params, *(format + pos_next));
	// if (*(format + pos_next) == 'c')
	// 	print_c(params, *(format + pos_next));
	return (pos_next);
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
	return (c == 'c' || c == 'd' || c == 'i'
		|| c == 'p' || c == 'x' || c == 'X'
		|| c == 'u' || c == 's' || c == '%');
}
