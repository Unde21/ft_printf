/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flags_u_nb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:34:02 by sammy             #+#    #+#             */
/*   Updated: 2024/11/27 19:48:37 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*manage_flags_u_nb(t_flags *flags, char *s, int len, unsigned int n)
{
	int	tmp;
	
	if (n == 0)
		len -= count_digits_u_nb(n) - 1;
	else
		len -= count_digits_u_nb(n);
	tmp = len;
	if (flags->point)
	{
		while (flags->size_precision > 0)
		{
			s[len--] = '0';
			--flags->size_precision;
		}
	}
	if (flags->zero && !flags->point && !flags->less)
	{
		while (flags->size_padding > 0)
		{
			s[len] = '0';
			--len;
			--flags->size_padding;
		}
	}
	adding_padding_u_nb(flags, s);
	if (flags->less && n != 0)
		rev_space_and_char(s);
	else if (flags->less && n == 0)
		rev_space_nb(s, tmp);
	return (s);
}

void	adding_padding_u_nb(t_flags *flags, char *s)
{
	int	i;

	i = 0;
	while (flags->size_padding > 0)
	{
		s[i] = ' ';
		++i;
		--flags->size_padding;
	}
}
