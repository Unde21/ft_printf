/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:36:14 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/30 15:09:38 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <stdint.h>
#include "ft_printf.h"

void	rev_space_and_char(char *str)
{
	size_t	i;
	char	swap;
	size_t	j;

	swap = '0';
	i = 0;
	j = 0;
	while (str[j] == ' ')
		j++;
	while (str[j] && str[i] == ' ')
	{
		swap = str[i];
		str[i] = str[j];
		str[j] = swap;
		++i;
		++j;
	}
}

int	skip_zero(char *format)
{
	size_t	index;

	index = 1;
	while (*format + index == '0')
		++index;
	return (index);
}
