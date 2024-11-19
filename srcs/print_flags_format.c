/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammy <sammy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 03:52:40 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/19 14:56:54 by sammy            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf_bonus.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

void	print_x(va_list *params, char format, t_flags *flags)
{
	int				count;
	char			*buffer;
	unsigned int	arg;
	size_t			total_length;

	arg = va_arg(*params, unsigned int);
	total_length += buffersize_hexa(arg, LOWER_BASE, flags);
	buffer = malloc(sizeof(char) * (total_length + 1));
	if (!buffer)
		return ;
	convert_hexa(buffer, arg, LOWER_BASE, flags);
	flags.count += print_buffer(buffer);
	free(buffer);
}

int	buffersize_hexa(unsigned int n, const char *base, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags.point && flags.arg2 == -1)
		flags.arg2 = 0;
	if (n == 0 && flags.point && flags.arg2 == 0)
		return (0);
	count = count_hex_digits(n);
	count = handle_point(count, flags);
	count = handle_sharp(count, n, flags);
	count = size_field(count, flags);
	return (count);
}

int	count_hex_digits(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	else
	{
		while (n > 0)
		{
			n /= 16;
			++count;
		}
	}
	return (count);
}
