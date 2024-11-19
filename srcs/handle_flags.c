/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammy <sammy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:41:24 by sammy             #+#    #+#             */
/*   Updated: 2024/11/19 14:53:06 by sammy            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf_bonus.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int	handle_point(int count, t_flags *flags)
{
	if (flags.point && flags.arg2 > count)
		return (flags.arg2);
	return (count);
}

int	handle_sharp(int count, unsigned int n, t_flags *flags)
{
	if (flags.sharp && n != 0)
		count += 2;
	return (count);
}

int	size_field(int count, t_flags *flags)
{
	if (flags.arg1 > count)
		return (flags.arg1);
	return (count);
}
