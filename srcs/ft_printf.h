/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:00:59 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/16 13:34:54 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *format, ...);

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putaddr(long n, int count, int index);
int	ft_putnbr_base(int n, int check, int count);
int	ft_puthexa(unsigned int n, int check_base, int count);
int	check_format(va_list params, char format);

#endif
