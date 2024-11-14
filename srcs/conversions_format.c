/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:40:38 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/14 21:36:00 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_putnbr_base(long n, unsigned int len_base, int count)
{
	char	*base;
	
	base = "0123456789abcdef";
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		++count;
	}
	if (n >= len_base)
		ft_putnbr_base(n / len_base, len_base, count);
	++count;
	ft_putchar(base[(n % len_base)]);
	return (count);
}

int	ft_putnbr_base_uppercase(long n, unsigned int len_base, int count)
{
	char	*base;
	
	base = "0123456789ABCDEF";
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		++count;
	}
	if (n >= len_base)
		ft_putnbr_base(n / len_base, len_base, count);
	ft_putchar(base[(n % len_base)]);
	++count;
	return (count);
}
