/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manageflag_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 02:15:48 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/21 05:25:32 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

char	*ft_itoa_base_hex(unsigned int n, t_flags *flags, int len, char *s)
{
	char	*base_to;

	base_to = flags->base_to;
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
		while (flags->size_precision > 0)
		{
			s[len] = '0';
			len--;
			flags->size_precision--;
		}
	}
	if (flags->prefix && n != 0 && len >= 1 && !flags->zero)
		len = adding_prefix(flags, s, len);
	if (flags->zero && flags->point)
	{
		len = adding_prefix(flags, s, len);
	}
	len = adding_precision_buffer(flags, s, len, n);
}

int	adding_precision_buffer(t_flags *flags, char *s, int len, unsigned int n)
{
	int	i;

	if (flags->zero && !flags->less && !flags->point)
	{
		while (flags->size_padding > 0)
		{
			if (flags->prefix && len == 1)
				break ;
			s[len] = '0';
			--len;
			--flags->size_padding;
		}
		if (flags->prefix && n != 0 && len >= 1)
			len = adding_prefix(flags, s, len);
	}
	i = 0;
	while (flags->size_padding > 0)
	{
		if (s[i] != '0')
			s[i++] = ' ';
		--flags->size_padding;
	}
	return (len);
}
int	adding_prefix(t_flags *flags, char *s, int len)
{
	if (ft_strncmp(flags->base_to, LOWER_BASE, 16) == 0)
		s[len] = 'x';
	else
		s[len] = 'X';
	--len;
	s[len] = '0';
	return (len);
}
