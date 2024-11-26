/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammy <sammy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 00:38:09 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/26 14:18:36 by sammy            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int	print_str(char *str)
{
	int		count;

	count = 0;
	if (str == NULL)
	{
		count = write(1, "(null)", 6);
		if (count == -1)
			return (-1);
		return (6);
	}
	count = write(1, str, ft_strlen(str));
	return (count);
}

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_nbr(int nb, int check_form, int count)
{
	long	n;
	int		check_write_error;

	check_write_error = 0;
	if (check_form == 0)
		n = (long)nb;
	else
		n = (unsigned int)nb;
	if (n < 0)
	{
		print_char('-');
		n = -n;
		++count;
	}
	if (n >= 10)
	{
		count = print_nbr(n / 10, check_form, count);
		if (count == -1)
			return (-1);
	}
	check_write_error = print_char(n % 10 + '0');
	if (check_write_error == -1)
		return (-1);
	count += check_write_error;
	return (count);
}

int	print_hexa(unsigned int n, const char *base, int count)
{
	int	check_write_error;

	check_write_error = 0;
	if (n >= 16)
	{
		count = print_hexa(n / 16, base, count);
		if (count == -1)
			return (-1);
	}
	check_write_error = print_char(base[(n % 16)]);
	if (check_write_error == -1)
		return (-1);
	count += check_write_error;
	return (count);
}

int	print_addr(unsigned long ptr, int count, int index)
{
	char	*base;
	int		check_write_error;

	check_write_error = 0;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (index == 0)
	{
		count += write(1, "0x", 2);
		++index;
	}
	base = LOWER_BASE;
	if (ptr >= 16)
	{
		count = print_addr(ptr / 16, count, index);
		if (count == -1)
			return (-1);
	}
	check_write_error = print_char(base[(ptr % 16)]);
	if (check_write_error == -1)
		return (-1);
	count += check_write_error;
	return (count);
}
