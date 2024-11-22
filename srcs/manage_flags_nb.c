/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flags_nb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 03:33:17 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/22 05:12:02 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*manage_flags_nb(t_flags *flags, char *s, int len, int n)
{
	len -= count_digits_nb(n);
	if (flags->point)
	{
		while (flags->size_precision > 0)
		{
			s[len] = '0';
			--len;
			--flags->size_precision;
		}
	}
	if (flags->sign && !flags->zero && n >= 0)
		len = adding_prefix(flags, s, len, 0);
	if (flags->zero && flags->point && flags->sign)
		len = adding_prefix(flags, s, len, 0);
	adding_precision_nb(flags, s, len, n);
	if (flags->space && !flags->sign)
		s[0] = ' ';
	if (flags->less)
		rev_space_and_char(s);
	return (s);
}

void	adding_precision_nb(t_flags *flags, char *s, int len, int n)
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
			len = adding_prefix(flags, s, len, 0);
	}
	i = 0;
	if (n < 0 && len > 0)
		s[--len] = '-';
	else if (n < 0 && len == 0)
		s[0] = '-';
	while (flags->size_padding > 0 && s[i] != '-')
	{
		s[i] = ' ';
		++i;
		--flags->size_padding;
	}
}
