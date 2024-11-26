/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammy <sammy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:48:59 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/26 14:12:39 by sammy            ###   ########lyon.fr   */
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
	total_length = buffersize_nb(arg, flags);
	buffer = calloc(sizeof(int), total_length + 1);
	if (!buffer)
		return ;
	buffer = itoa(arg, total_length - 1, buffer);
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
	if (flags->precision == -1)
		flags->precision = 0;
	if (flags->padding == -1)
		flags->padding = 0;
	if (flags->point && flags->precision == 0 && flags->padding != 0)
		flags->precision = flags->padding;
	if (flags->point && flags->precision > buffer_size)
		flags->size_precision = flags->precision - buffer_size;
	if (flags->sign && n >= 0)
		buffer_size += 1;
	if (flags->padding > buffer_size + flags->size_precision)
		flags->size_padding = flags->padding - (buffer_size
				+ flags->size_precision);
	buffer_size += flags->size_precision + flags->size_padding;
	// if (n < 0)
	// 	buffer_size += 1;
	if (flags->space && n >= 0)
		buffer_size += 1;
	return (buffer_size);
}

int	count_digits_nb(int nb)
{
	int		i;
	long	n;

	n = (long)nb;
	i = 0;
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		++i;
		n /= 10;
	}
	if (i == 0)
		++i;
	return (i);
}

char	*itoa(int n, int len, char *s)
{
	long	nb;

	nb = (long)n;
	if (nb == 0)
	{
		s[len] = '0';
		return (s);
	}
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		s[len] = (nb % 10) + '0';
		--len;
		nb /= 10;
	}
	return (s);
}
