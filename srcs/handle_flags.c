/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammy <sammy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:41:24 by sammy             #+#    #+#             */
/*   Updated: 2024/11/20 08:02:10 by sammy            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf_bonus.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int	handle_point(int count, t_flags *flags)
{
	if (flags->point && flags->arg2 > count)
	{
		//printf("1bisflags arg1 : %d, arg2 : %d, count : %d\n", flags->arg1, flags->arg2, count);
		flags->arg2 -= count;
		//printf("1flags arg1 : %d, arg2 : %d, count : %d\n", flags->arg1, flags->arg2, count);
		return (flags->arg2);
	}
	return (count);
}

int	handle_sharp(int count, unsigned int n, t_flags *flags)
{
	if (flags->sharp && n != 0)
		count += 2;
	//printf("2flags arg1 : %d, arg2 : %d, count : %d\n", flags->arg1, flags->arg2, count);
	return (count);
}

int	size_field(int count, t_flags *flags)
{
	if (flags->arg1 > count)
	{
		//printf("3flags arg1 : %d, arg2 : %d, count : %d\n", flags->arg1, flags->arg2, count);
		//flags->arg1 -= (flags->arg2 + count);
		if (flags->arg2 <= 0 && flags->point)
			flags->arg2 = flags->arg1;
		printf("6flags arg1 : %d, arg2 : %d, count : %d\n", flags->arg1, flags->arg2, count);
		return (flags->arg1);
	}
	return (count);
}
