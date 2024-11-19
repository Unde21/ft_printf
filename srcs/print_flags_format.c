/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 03:52:40 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/19 04:59:23 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf_bonus.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>


void	print_x(va_list *params, char format)
{
	t_list	flags;
	int		count;
	char	*buffer;

	count = 0;
	if (flags.less == false && flags.point == true)
	{
		
	}
	if (flags.sharp == true )
	{
		flags.count += write(1, "0x", 2);
		buffer = save_hexa(va_arg(*params, unsigned int), LOWER_BASE, count);
	}
	

	//printf buffer / free;
}
