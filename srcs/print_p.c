/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 02:59:31 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/21 23:27:20 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

void	print_p(va_list *params, t_flags *flags)
{
		unsigned long arg;
		int				total_length;
		
		flags->base_to = LOWER_BASE;
		arg = va_arg(*params, unsigned long);
		total_length = buffersize_addr(arg, flags);
		convert_addr(flags, arg, total_length);
}

int	buffersize_addr(unsigned long n, t_flags *flags)
{
	int	buffer_size;

	buffer_size = count_hex_digits(n) + 2;
	if (flags->padding > buffer_size)
		flags->size_padding = flags->padding - buffer_size;
	buffer_size += flags->size_padding;
	return (buffer_size);
}
void	convert_addr(t_flags *flags, unsigned long n, int len)
{
	char	*buffer;

	buffer = calloc(sizeof(char), len + 1);
	if (!buffer)
		return ;
	flags->base_to = LOWER_BASE;
	buffer = ft_itoa_base_hex(n, flags, len - 1, buffer);
	buffer = manage_flags_addr(flags, buffer, len - 1, n);
	flags->count += write(1, buffer, len);
	free(buffer);
}

char	*manage_flags_addr(t_flags *flags, char *s, int len, unsigned long n)
{
	len -= count_hex_digits(n);
	s[len] = 'x';
	--len;
	s[len] = '0';
	--len;
	while (flags->size_padding > 0)
	{
		s[len] = ' ';
		--len;
		--flags->size_padding;
	}
	if (flags->less && flags->padding > 0)
		rev_space_and_char(s);
	return (s);
}
