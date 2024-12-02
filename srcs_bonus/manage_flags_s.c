/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flags_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:18:35 by samaouch          #+#    #+#             */
/*   Updated: 2024/12/02 12:53:51 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_flags_s(t_flags *flags, char *s, char *str)
{
	size_t	i;
	int		len_str;

	len_str = (int)ft_strlen(str);
	i = 0;
	if (flags->less)
	{
		if (flags->size_precision == 0 || flags->size_precision > len_str
			|| !flags->point)
			flags->precision = len_str;
		ft_strlcpy(&s[i], str, flags->precision + 1);
		len_str = ft_strlen(s);
		while (flags->size_padding > 0)
		{
			s[len_str + i++] = ' ';
			--flags->size_padding;
		}
	}
	else
	{
		adding_padding_s(flags, s, str, i);
	}
}

void	adding_padding_s(t_flags *flags, char *s, char *str, int i)
{
	int	len_str;

	len_str = (int)ft_strlen(str);
	while (flags->size_padding > 0)
	{
		s[i++] = ' ';
		--flags->size_padding;
	}
	if (flags->precision == 0 && flags->point)
		return ;
	if (flags->size_precision == 0 || flags->size_precision > len_str
		|| !flags->point)
		flags->precision = len_str;
	ft_strlcpy(&s[i], str, flags->precision + 1);
}
