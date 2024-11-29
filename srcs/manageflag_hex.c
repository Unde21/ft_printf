/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manageflag_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 02:15:48 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/29 09:15:33 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_hex_digits(unsigned long n)
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

char	*ft_itoa_base_hex(unsigned int n, t_flags *flags, int len, char *s)
{
	char	*base_to;

	base_to = flags->base_to;
	if (n == 0)
	{
		s[len] = '0';
		return (s);
	}
	while (n > 0)
	{
		s[len--] = base_to[n % 16];
		n /= 16;
	}
	return (s);
}

void	adding_all_flag_buffer(t_flags *flags, char *s, int len, unsigned int n)
{
	len -= count_hex_digits(n);
	if (flags->point)
	{
		while (flags->size_precision > 0 && len >= 0)
		{
			s[len--] = '0';
			--flags->size_precision;
		}
	}
	if (flags->prefix && n != 0 && len >= 1 && !flags->zero)
		len = adding_prefix(flags, s, len, 1);
	if (flags->zero && flags->point && flags->prefix && len >= 1)
		len = adding_prefix(flags, s, len, 1);
	adding_precision_buffer(flags, s, len, n);
}

void	adding_precision_buffer(t_flags *flags, char *s, int len,
		unsigned int n)
{
	size_t	i;

	if (flags->zero && !flags->less && !flags->point)
	{
		while (flags->size_padding > 0)
		{
			s[len] = '0';
			--len;
			--flags->size_padding;
		}
		if (flags->prefix && n != 0)
			len = adding_prefix(flags, s, len, 1);
	}
	i = 0;
	while (flags->size_padding > 0)
	{
		s[i] = ' ';
		++i;
		--flags->size_padding;
	}
}

int	adding_prefix(t_flags *flags, char *s, int len, int check)
{
	if (check == 0)
	{
		s[len] = '+';
		--len;
		return (len);
	}
	else
	{
		if (ft_strncmp(flags->base_to, LOWER_BASE, 16) == 0)
			s[len] = 'x';
		else
			s[len] = 'X';
		--len;
		s[len] = '0';
		return (len);
	}
}
