/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:09:53 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/30 17:28:27 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

void	print_s(va_list *params, t_flags *flags)
{
	int		total_length;
	char	*arg;
	char	*buffer;
	int		check_write_error;

	check_write_error = 0;
	arg = va_arg(*params, char *);
	if (flags->point && flags->precision == -1 && flags->padding == -1)
		return ;
	total_length = buffersize_s(arg, flags);
	buffer = ft_calloc(sizeof(char), total_length + 1);
	if (!buffer)
		return ;
	if (arg == NULL)
		manage_flags_s(flags, buffer, "(null)");
	else
		manage_flags_s(flags, buffer, arg);
	check_write_error = write(1, buffer, total_length);
	free(buffer);
	if (check_write_error == -1)
		flags->count = -1;
	else
		flags->count += check_write_error;
}

int	buffersize_s(char *str, t_flags *flags)
{
	int	buffer_size;
	int	len_str;

	if (str == NULL)
		len_str = 6;
	else
		len_str = (int)ft_strlen(str);
	buffer_size = len_str;
	if (str[0] == '\0' && flags->point && flags->padding != -1
		&& flags->precision != -1)
	{
		flags->size_padding = flags->padding;
		return (flags->size_padding);
	}
	if (flags->point && flags->precision == -1 && flags->padding != -1
		&& str != NULL)
		return (calculate_size_precision_s(flags, buffer_size));
	buffer_size = calculate_field_s(flags, buffer_size);
	return (buffer_size);
}

int	calculate_size_precision_s(t_flags *flags, int buffer_size)
{
	if (flags->is_precision == false)
	{
		flags->size_padding = flags->padding;
		return (flags->padding);
	}
	flags->precision = flags->padding;
	flags->size_precision = flags->padding - buffer_size;
	if (flags->padding > buffer_size)
		return (buffer_size);
	return (flags->precision);
}

int	calculate_field_s(t_flags *flags, int buffer_size)
{
	if (flags->point)
	{
		if (flags->precision < buffer_size)
		{
			flags->size_precision = flags->precision;
			buffer_size = flags->precision;
		}
		else
			flags->size_precision = flags->precision - buffer_size;
		if (flags->padding != -1 && flags->padding > buffer_size)
			flags->size_padding = flags->padding - buffer_size;
	}
	if (flags->padding > flags->size_precision)
	{
		flags->size_padding = flags->padding - buffer_size;
		if (flags->size_padding > 0)
			buffer_size += flags->size_padding;
		return (buffer_size);
	}
	buffer_size += flags->size_padding;
	return (buffer_size);
}
