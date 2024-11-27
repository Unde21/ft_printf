/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:36:14 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/27 02:10:17 by samaouch         ###   ########lyon.fr   */
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
