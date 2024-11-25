/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammy <sammy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 00:38:27 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/25 13:13:23 by sammy            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	va_list	params;
	t_flags	*flags;
	int		count;

	count = 0;
	va_start(params, format);
	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (0);
	flags->count = 0;
	reset_struct(flags);
	count = parse_format(&params, (char *)format, flags);
	va_end(params);
	free(flags);
	return (count);
}

int	parse_format(va_list *params, char *format, t_flags *flags)
{
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*format + 1)
			{
				++format;
				if (parse_flags(format, flags))
				{
					format += check_flg_format(params, format, flags);
					reset_struct(flags);
				}
				else
					flags->count += check_format(params, *format);
			}
		}
		else
			flags->count += print_char(*format);
		++format;
	}
	return (flags->count);
}

int	parse_flags(char *format, t_flags *flags)
{
	while (valid_format(*format) == 0 && *format != '\0')
	{
		change_struct_flags(*format, flags);
		if (*format > '0' && *format <= '9')
		{
			if (flags->padding == -1)
				flags->padding = ft_atoi((const char *)format);
			else
				flags->precision = ft_atoi((const char *)format);
			while (*format > '0' && *format <= '9')
				++format;
			continue ;
		}
		++format;
	}
	if (flags->nb == 0)
		return (0);
	return (1);
}

void	change_struct_flags(char format, t_flags *flags)
{
	if (format == '#')
		flags->prefix = true;
	if (format == '+')
		flags->sign = true;
	if (format == '-')
		flags->less = true;
	if (format == ' ')
		flags->space = true;
	if (format == '.')
		flags->point = true;
	if (format == '0' && flags->padding == -1)
		flags->zero = true;
	else
		++flags->nb;
}

void	reset_struct(t_flags *flags)
{
	flags->prefix = false;
	flags->sign = false;
	flags->less = false;
	flags->space = false;
	flags->point = false;
	flags->zero = false;
	flags->nb = 0;
	flags->padding = -1;
	flags->precision = -1;
	flags->size_precision = 0;
	flags->size_padding = 0;
}
