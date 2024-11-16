/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:40:38 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/16 13:35:20 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_putnbr_base(int nb, int check, int count)
{
	long	n;
	
	if (check == 0)
		n = (long)nb;
	else
		n = (unsigned int)nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		++count;
	}
	if (n >= 10)
		count = ft_putnbr_base(n / 10, check, count);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_puthexa(unsigned int n, int check_base, int count)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		++count;
	}
	if (n >= 16)
		count = ft_puthexa(n / 16, check_base, count);
	if (check_base == 0 && base[n % 16] >= 'A' && base[n % 16] <= 'F')
		count += ft_putchar(base[(n % 16)] + 32);
	else
		count += ft_putchar(base[(n % 16)]);
	return (count);
}
int	ft_putaddr(long n, int count, int index)
{
	char	*base;

	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (index == 0)
	{
		count += write(1, "0x", 2);
		++index;
	}
	base = "0123456789abcdef";
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		++count;
	}
	if (n >= 16)
		count = ft_putaddr(n / 16, count, index);
	count += ft_putchar(base[(n % 16)]);
	return (count);
}
