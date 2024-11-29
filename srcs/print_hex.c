/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 03:52:40 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/29 11:08:25 by samaouch         ###   ########lyon.fr   */
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
	if ((flags->point && flags->precision == -1 && flags->padding == -1 && arg == 0))
		return ;
	total_length = buffersize_hex(arg, flags);
	convert_hex(flags, arg, total_length);
}

void	print_upper_x(va_list *params, t_flags *flags)
{
	unsigned int	arg;
	int				total_length;

	flags->base_to = UPPER_BASE;
	arg = va_arg(*params, unsigned int);
	if ((flags->point && flags->precision == -1 && flags->padding == -1 && arg == 0) && !flags->sign && !flags->space)
		return ;
	total_length = buffersize_hex(arg, flags);
	convert_hex(flags, arg, total_length);
}

int	buffersize_hex(unsigned int n, t_flags *flags)
{
	int	buffer_size;

	buffer_size = count_hex_digits(n);
	if (flags->point && flags->precision == -1 && flags->padding != -1)
	{
		if (n == 0)
				buffer_size -= 1;
		if (flags->is_precision == false)
		{
			if (flags->padding > buffer_size)
				flags->size_padding = flags->padding - buffer_size;
			else
				flags->padding = buffer_size;
			return (flags->padding);
		}
		flags->precision = flags->padding;
		flags->size_precision = flags->padding - buffer_size;
		//printf("buffer : %d, paddin %d preci %d\n", buffer_size, flags->size_padding, flags->size_precision);
		if (flags->padding - buffer_size > 0)
			return (flags->padding);
		return (buffer_size);
	}
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
	int		check_write_error;

	check_write_error = 0;
	buffer = ft_calloc(sizeof(char), len + 1);
	if (!buffer)
		return ;
	buffer = ft_itoa_base_hex(n, flags, len - 1, buffer);
	adding_all_flag_buffer(flags, buffer, len - 1, n);
	if (flags->less)
		rev_space_and_char(buffer);
	check_write_error = write(1, buffer, len);
	free(buffer);
	if (check_write_error == -1)
		flags->count = -1;
	else
		flags->count += check_write_error;
}
