/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flags_nb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 03:33:17 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/30 15:04:02 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*manage_flags_nb(t_flags *flags, char *s, int len, int n)
{
	int	tmp;

	if (n == 0)
		len -= count_digits_nb(n) - 1;
	else
		len -= count_digits_nb(n);
	tmp = len;
	len = adding_precision(flags, len, s);
	if (flags->sign && !flags->zero && n > 0)
		len = adding_prefix(flags, s, len, 0);
	else if (flags->sign && !flags->zero && n == 0 && len >= 1)
		len = adding_prefix(flags, s, len - 1, 0);
	else if (flags->sign && !flags->zero && n == 0)
		len = adding_prefix(flags, s, len, 0);
	if (flags->zero && flags->point && flags->sign)
		len = adding_prefix(flags, s, len, 0);
	adding_padding_nb(flags, s, len, n);
	if (flags->space && !flags->sign && n >= 0)
		s[0] = ' ';
	if (flags->less && n == 0)
		rev_space_nb(s, tmp);
	else if (flags->less)
		rev_space_and_char(s);
	return (s);
}

void	adding_padding_nb(t_flags *flags, char *s, int len, int n)
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
		if (flags->prefix)
			len = adding_prefix(flags, s, len, 0);
	}
	i = 0;
	if (n < 0)
		s[len + 1] = '-';
	while (flags->size_padding > 0 && s[i] != '-')
	{
		s[i] = ' ';
		++i;
		--flags->size_padding;
	}
}

void	rev_space_nb(char *s, size_t len)
{
	size_t	i;
	char	swap;
	size_t	j;

	swap = '0';
	i = 0;
	j = 0;
	while (s[j] == ' ')
		j++;
	while (j <= len && s[i] == ' ')
	{
		swap = s[i];
		s[i] = s[j];
		s[j] = swap;
		++i;
		++j;
	}
}

int	adding_precision(t_flags *flags, int len, char *s)
{
	if (flags->point)
	{
		while (flags->size_precision > 0)
		{
			s[len--] = '0';
			--flags->size_precision;
		}
	}
	return (len);
}
