/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:49:05 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/29 11:08:11 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

void	print_c(va_list *params, t_flags *flags)
{
	int		total_length;
	int		arg;
	char	*buffer;
	int		count;

	count = 0;
	arg = va_arg(*params, int);
	total_length = buffersize_c(flags);
	buffer = ft_calloc(sizeof(char), total_length + 1);
	if (!buffer)
		return ;
	buffer = manage_flags_c(flags, buffer, total_length - 1, arg);
	count = write(1, buffer, total_length);
	free(buffer);
	if (count == -1)
		flags->count = -1;
	flags->count += count;
}

int	buffersize_c(t_flags *flags)
{
	int	buffer_size;

	buffer_size = 1;
	if (flags->padding > 1)
		flags->size_padding = flags->padding - buffer_size;
	else
		flags->padding = 0;
	buffer_size += flags->size_padding;
	return (buffer_size);
}

char	*manage_flags_c(t_flags *flags, char *s, int len, int c)
{
	if (flags->less)
		s[0] = c;
	else
	{
		s[len] = c;
		--len;
	}
	while (flags->size_padding  > 0)
	{
		s[len] = ' ';
		--len;
		--flags->size_padding;
	}
	return (s);
}
