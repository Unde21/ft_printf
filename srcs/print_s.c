/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:56:16 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/27 21:21:37 by samaouch         ###   ########lyon.fr   */
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
	total_length = buffersize_s(arg, flags);
	buffer = calloc(sizeof(char), total_length + 1);
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

	if (str == NULL)
		buffer_size = 6;
	else
		buffer_size = (int)ft_strlen(str);
	if (flags->point && flags->precision == -1 && flags->padding == -1)
		return (buffer_size);
	if (str[0] == '\0' && flags->point && flags->padding != 0 && flags->precision != 0)
		{
			flags->size_padding = flags->padding;
			return (flags->size_padding);
		}
	if (flags->point && flags->precision == 0 && flags->padding != 0 && str != NULL)
	{
		if (flags->is_precision == false)
		{
			flags->size_padding = flags->padding - buffer_size;
			return (flags->padding);
		}
		flags->size_precision = flags->padding;
		if (buffer_size > flags->size_precision)
			buffer_size = flags->size_precision;
		return (buffer_size);
	}
	if (flags->padding > buffer_size + flags->precision)
	{
		flags->size_padding = flags->padding - buffer_size;
	}
	if (flags->padding > buffer_size)
		flags->size_padding = flags->padding - buffer_size;
	buffer_size += flags->size_padding;
	// printf("buffer size : %d, paddi %d preci %d\n", buffer_size, flags->size_padding, flags->size_precision);
	return (buffer_size);
}

void	manage_flags_s(t_flags *flags, char *s, char *str)
{
	size_t	i;
	int		len_str;

	len_str = (int)ft_strlen(str);
	i = 0;
	if (flags->less)
	{
		if (flags->size_precision == 0 || flags->size_precision > len_str)
			flags->size_precision = len_str;
		ft_strlcpy(&s[i], str, flags->size_precision + 1);
		while (flags->size_padding > 0)
		{
			s[len_str + i++] = ' ';
			--flags->size_padding;
		}
	}
	else
	{	
		if (flags->size_precision == 0 || flags->size_precision > len_str)
			flags->size_precision = len_str;
		while (flags->size_padding > 0)
		{
			s[i++] = ' ';
			--flags->size_padding;
		}
		ft_strlcpy(&s[i], str, flags->size_precision + 1);
	}
}
