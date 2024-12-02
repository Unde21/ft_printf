/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:00:59 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/30 20:44:24 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *format, ...) __attribute__((format(printf, 1, 2)));
int	print_char(int c);
int	print_str(char *str);
int	format_is_valid(const char *format);
int	print_addr(unsigned long ptr, int count, int index);
int	print_nbr(int n, int check_form, int count);
int	print_hexa(unsigned int n, const char *base, int count);
int	check_format(va_list *params, char format);

#endif
