/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:56:16 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/22 00:04:26 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

void	print_s(va_list *params, t_flags *flags)
{
	int		total_length;
	char	*arg;
	char 	*buffer;

	arg = va_arg(*params, char *);
	total_length = buffersize_s(arg, flags);
	buffer = calloc(sizeof(char), total_length + 1);
	if (!buffer)
		return ;
	buffer = manage_flags_s(flags, buffer, arg);
	flags->count += write(1, buffer, total_length);
	free(buffer);
}

int	buffersize_s(char *str, t_flags *flags)
{
	int	buffer_size;
	
	buffer_size = (int)ft_strlen(str);
	if (flags->precision == -1)
		flags->precision = 0;
	if (flags->padding == -1)
		flags->padding = 0;
	if (flags->point && flags->precision == 0 && flags->padding !=0)
		flags->precision = flags->padding;
	if (flags->point && flags->precision < buffer_size)
	{
		flags->size_precision = flags->precision;
		buffer_size = flags->size_precision;
	}
	if (flags->padding > buffer_size)
		flags->size_padding =  flags->padding - buffer_size;
	buffer_size += flags->size_padding;
	return (buffer_size);
}

char	*manage_flags_s(t_flags *flags, char *s, char *str)
{
	size_t	i;
	int		len_str;
	
	len_str = (int)ft_strlen(str);
	i = 0;
	while (flags->size_padding > 0)
	{
		s[i] = ' ';
		++i;
		--flags->size_padding;
	}
	if (flags->precision == 0 || flags->precision > len_str)
		flags->size_precision = len_str;
	ft_strlcpy(&s[i], str, flags->size_precision + 1);
	if (flags->less)
		rev_space_and_char(s);
	return (s);
}