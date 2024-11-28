/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:48:59 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/28 03:55:30 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

void	print_nb(va_list *params, t_flags *flags)
{
	int		arg;
	int		total_length;
	char	*buffer;
	int		check_write_error;
	
	check_write_error = 0;
	arg = va_arg(*params, int);
	if ((flags->point && flags->precision == -1 && flags->padding == -1 && arg == 0) && !flags->sign && !flags->space)
		return ;
	total_length = buffersize_nb(arg, flags);
	buffer = calloc(sizeof(int), total_length + 1);
	if (!buffer)
		return ;
	buffer = itoa(arg, total_length, buffer, flags);
	buffer = manage_flags_nb(flags, buffer, total_length - 1, arg);
	check_write_error = write(1, buffer, total_length);
	free(buffer);
	if (check_write_error == -1)
		flags->count = -1;
	else
		flags->count += check_write_error;
}

int	buffersize_nb(int n, t_flags *flags)
{
	int	buffer_size;

buffer_size = count_digits_nb(n);
	if (flags->point && flags->precision == -1 && flags->padding != -1)
	{
		if (n == 0)
			buffer_size -= 1;
		if (flags->is_precision ==  false)
		{
			flags->size_padding = flags->padding - buffer_size;
			return (flags->padding);
		}
		if (n < 0)
			flags->padding += 1;
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
	if (flags->sign && n >= 0)
		buffer_size += 1;
	if (flags->padding > buffer_size + flags->size_precision)
	{
		if (flags->point && flags->precision >= count_digits_nb(n) && n < 0)
			flags->size_precision = flags->precision - count_digits_nb(n) + 1;
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
	if (flags->space && n >= 0)
		buffer_size += 1;
	//printf("buffer : %d, paddin %d preci %d\n", buffer_size, flags->size_padding, flags->size_precision);
	return (buffer_size);
}

int	count_digits_nb(int n)
{
	int		i;
	
	i = 0;
	if (n < 0)
	{
		n = -n;
		++i;
	}
	while (n != 0)
	{
		++i;
		n /= 10;
	}
	if (i == 0)
		++i;
	return (i);
}

char	*itoa(int n, int len, char *s, t_flags *flags)
{
	long	nb;

	nb = (long)n;
	if (nb == 0 && flags->size_precision != 0)
	{
		s[len] = '0';
		return (s);
	}
	if (nb < 0)
		nb = -nb;
	while(len-- > 0)
	{
		s[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (s);
}
