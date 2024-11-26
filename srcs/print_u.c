/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 05:45:31 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/26 04:21:58 by samaouch         ###   ########lyon.fr   */
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
	total_length = buffersize_u_nb(arg, flags);
	buffer = calloc(sizeof(unsigned int), total_length + 1);
	if (!buffer)
		return ;
	buffer = itoa(arg, total_length - 1, buffer);
	buffer = manage_flags_u_nb(flags, buffer, total_length - 1, arg);
	if (flags->less)
		rev_space_and_char(buffer);
	free(buffer);
	check_write_error = write(1, buffer, total_length);
	if (check_write_error == -1)
		flags->count = -1;
	else
		flags->count += check_write_error + 1;
}

int	buffersize_u_nb(unsigned int n, t_flags *flags)
{
	int	buffer_size;

	buffer_size = count_digits_u_nb(n);
	if (flags->precision == -1)
		flags->precision = 0;
	if (flags->padding == -1)
		flags->padding = 0;
	if (flags->point && flags->precision == 0 && flags->padding != 0)
		flags->precision = flags->padding;
	if (flags->point && flags->precision > buffer_size)
		flags->size_precision = flags->precision - buffer_size;
	if (flags->padding > buffer_size + flags->size_precision)
		flags->size_padding = flags->padding - (buffer_size
				+ flags->size_precision);
	buffer_size += flags->size_precision + flags->size_padding;
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

char	*unsigned_itoa(int n, int len, char *s)
{
	if (n == 0)
		s[len] = '0';
	return (s);
	while (n > 0)
	{
		s[len] = (n % 10) + '0';
		--len;
		n /= 10;
	}
	return (s);
}
