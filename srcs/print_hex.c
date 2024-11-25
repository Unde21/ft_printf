/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammy <sammy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 03:52:40 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/25 13:37:21 by sammy            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

void	print_x(va_list *params, t_flags *flags)
{
	unsigned int	arg;
	int				total_length;

	flags->base_to = LOWER_BASE;
	arg = va_arg(*params, unsigned int);
	total_length = buffersize_hex(arg, flags);
	convert_hex(flags, arg, total_length);
}

void	print_upper_x(va_list *params, t_flags *flags)
{
	unsigned int	arg;
	int				total_length;

	flags->base_to = UPPER_BASE;
	arg = va_arg(*params, unsigned int);
	total_length = buffersize_hex(arg, flags);
	convert_hex(flags, arg, total_length);
}

int	buffersize_hex(unsigned int n, t_flags *flags)
{
	int	buffer_size;

	buffer_size = count_hex_digits(n);
	if (flags->precision == -1)
		flags->precision = 0;
	if (flags->padding == -1)
		flags->padding = 0;
	if (flags->point && flags->precision == 0 && flags->padding != 0)
		flags->precision = flags->padding;
	if (flags->point && flags->precision > buffer_size)
		flags->size_precision = flags->precision - buffer_size;
	if (flags->prefix && n != 0)
		buffer_size += 2;
	if (flags->padding > buffer_size + flags->size_precision)
		flags->size_padding = flags->padding - (buffer_size
				+ flags->size_precision);
	buffer_size += flags->size_precision + flags->size_padding;
	return (buffer_size);
}

void	convert_hex(t_flags *flags, unsigned int n, int len)
{
	char	*buffer;

	buffer = calloc(sizeof(char), len + 1);
	if (!buffer)
		return ;
	buffer = ft_itoa_base_hex(n, flags, len - 1, buffer);
	adding_all_flag_buffer(flags, buffer, len - 1, n);
	if (flags->less)
		rev_space_and_char(buffer);
	flags->count += write(1, buffer, len);
	free(buffer);
}
