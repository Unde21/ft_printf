/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 05:45:31 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/29 11:09:54 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

void	print_unb(va_list *params, t_flags *flags)
{
	unsigned int	arg;
	int				total_length;
	char			*buffer;
	int				check_write_error;

	check_write_error = 0;
	arg = va_arg(*params, unsigned int);
	if ((flags->point && flags->precision == -1 && flags->padding == -1 && arg == 0))
		return ;
	total_length = buffersize_u_nb(arg, flags);
	buffer = ft_calloc(sizeof(unsigned int), total_length + 1);
	if (!buffer)
		return ;
	buffer = unsigned_itoa(arg, total_length, buffer, flags);
	//printf("buff %s", buffer);
	buffer = manage_flags_u_nb(flags, buffer, total_length - 1, arg);
	check_write_error = write(1, buffer, total_length);
	free(buffer);
	if (check_write_error == -1)
		flags->count = -1;
	else
		flags->count += check_write_error;
}

int	buffersize_u_nb(unsigned int n, t_flags *flags)
{
	int	buffer_size;

	buffer_size = count_digits_u_nb(n);
	if (flags->point && flags->precision == -1 && flags->padding != -1)
	{
		if (n == 0)
			buffer_size -= 1;
		if (flags->is_precision ==  false)
		{
			flags->size_padding = flags->padding - buffer_size;
			return (flags->padding);
		}
		flags->precision = flags->padding;
		flags->size_precision = flags->padding - buffer_size;
		if (flags->padding > buffer_size)
			return (flags->padding);
		return (buffer_size);
	}
	if (flags->point && flags->precision > buffer_size)
	{
		if (n <= 0)
			flags->size_precision = flags->precision - buffer_size + 1;
		else
			flags->size_precision = flags->precision - buffer_size;
	}
	if (flags->padding >= buffer_size + flags->size_precision)
	{
		if (flags->point && flags->precision >= count_digits_u_nb(n) && n < 0)
			flags->size_precision = flags->precision - count_digits_u_nb(n) + 1;
		// if (n == 0 && !flags->less && flags->point)
		// 	buffer_size -= 1;
		if (n == 0 && flags->point)
			flags->size_padding = 1;
		flags->size_padding += flags->padding - (buffer_size
				+ flags->size_precision);
	}
	buffer_size += flags->size_precision + flags->size_padding;
	if (n == 0 && flags->point)
			buffer_size -= 1;
	//printf("buffer : %d, paddin %d preci %d\n", buffer_size, flags->size_padding, flags->size_precision);
	return (buffer_size);
}

int	count_digits_u_nb(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		++i;
		n /= 10;
	}
	if (i == 0)
		++i;
	return (i);
}

char	*unsigned_itoa(unsigned int n, int len, char *s, t_flags *flags)
{
	if (n == 0 && flags->size_precision != 0)
	{

		s[len] = '0';
		return (s);
	}
	while (len-- > 0)
	{
		s[len] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}
