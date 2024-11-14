/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:00:59 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/14 21:17:20 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdarg.h>

int		ft_printf(const char *, ...);

int	ft_putchar(int c);
int	ft_putnbr(int nb);
int	ft_putstr(const char *str);
// int ft_unsigned_putnbr(int nb);
int	ft_putnbr_base(long n, unsigned int len_base, int count);
int	ft_putnbr_base_uppercase(long n, unsigned int len_base, int count);
int	check_format(va_list params, char  format);

#endif
