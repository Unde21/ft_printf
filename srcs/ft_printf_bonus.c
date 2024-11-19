/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 00:38:27 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/19 04:36:51 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf_bonus.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	va_list	params;
	t_list	flags;

	reset_struct_false();
	va_start(params, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*format + 1)
			{
				++format;
				if (check_flags(&format))
					format += check_flags_format(&params, format);
				else if (format)
					flags.count += check_format(&params, *format);
			}
		}
		else
			flags.count += print_char(*format);
		++format;
	}
	va_end(params);
	return (flags.count);
}

int	check_flags(char *format)
{
	t_list	flags;
	
	while (valid_format(&format) == 0 && *format != NULL)
	{
		change_struct_flags(&format);
		if (format > '0' && format <= '9')
		{
			if (flags.arg1 == -1)
				flags.arg1 = ft_atoi(&format);
			else
				flags.arg2 = ft_atoi(&format);
		}
		++format;
	}
	if (flags.nb != 0)
		return (1);
	return (0);
}
void	change_struct_flags(char *format)
{
	t_list	flags;

	if (format == '#')
		flags.sharp = true;
	else if (format == '+')
		flags.add = true;
	else if (format == '-')
		flags.less = true;
	else if (format == ' ')
		flags.space = true;
	else if (format == '.')
		flags.point = true;
	else if (format == '0')
		flags.zero = true;
	else
		++flags.nb;
}
void	reset_struct_false(void)
{
	t_list	flags;

	flags.sharp = false;
	flags.add = false;
	flags.less = false;
	flags.space = false;
	flags.point = false;
	flags.zero = false;
	flags.nb = 0;
	flags.arg1 = -1;
	flags.arg2 = -1;
}
int	check_format(va_list *params, char format)
{
	int		count;
	char	*upper_base;
	char	*lower_base;

	upper_base = "0123456789ABCDEF";
	lower_base = "0123456789abcdef";
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
		count += print_hexa(va_arg(*params, unsigned int), lower_base, count);
	else if (format == 'X')
		count += print_hexa(va_arg(*params, unsigned int), upper_base, count);
	else if (format == '%')
		count += print_char('%');
	return (count);
}
