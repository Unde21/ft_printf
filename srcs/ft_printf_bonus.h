/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:30:56 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/19 04:32:03 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>

# define LOWER_BASE "0123456789abcdef"
# define UPPER_BASE "0123456789ABCDEF"

int	ft_printf(const char *format, ...);

int	print_char(int c);
int	print_str(char *str);
int	format_is_valid(const char *format);
int	print_addr(unsigned long ptr, int count, int index);
int	print_nbr(int n, int check_form, int count);
int	print_hexa(unsigned int n, const char *base, int count);
int	check_format(va_list *params, char format);




int		check_flags(char *format);
void	change_struct_flags(char *format);
void	reset_struct_false(void);

typedef struct	s_list
{
	bool	space;
	bool	zero;
	bool	add;
	bool	less;
	bool	sharp;
	bool	point;
	size_t	nb;
	int		count;
	int		arg1;
	int		arg2;
}		t_list;
#endif
