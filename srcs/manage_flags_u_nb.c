/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flags_u_nb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammy <sammy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:34:02 by sammy             #+#    #+#             */
/*   Updated: 2024/11/25 13:47:56 by sammy            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*manage_flags_u_nb(t_flags *flags, char *s, int len, unsigned int n)
{
	len -= count_digits_u_nb(n);
	if (flags->point)
	{
		while (flags->size_precision > 0)
		{
			s[len] = '0';
			--len;
			--flags->size_precision;
		}
	}
	if (flags->zero && !flags->point)
	{
		while (flags->size_padding > 0)
		{
			s[len] = '0';
			--len;
			--flags->size_padding;
		}
	}
	adding_padding_u_nb(flags, s);
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
