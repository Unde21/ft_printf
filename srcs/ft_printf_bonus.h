/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammy <sammy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:30:56 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/19 15:02:15 by sammy            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>

# define LOWER_BASE "0123456789abcdef"
# define UPPER_BASE "0123456789ABCDEF"

int		ft_printf(const char *format, ...);

int		print_char(int c);
int		print_str(char *str);
int		format_is_valid(const char *format);
int		print_addr(unsigned long ptr, int count, int index);
int		print_nbr(int n, int check_form, int count);
int		valid_format(char format);
int		print_hexa(unsigned int n, const char *base, int count);
int		check_format(va_list *params, char format);

int		check_flg_format(va_list *params, char *format);
int		parse_flags(char *format);
void	change_struct_flags(char format);
int		pos_next_format(va_list *params, char *format);
void	reset_struct_false(void);
void	print_x(va_list *params, char format);

int		handle_point(int count, t_flags *flags);
int		handle_sharp(int count, unsigned int n, t_flags *flags);
int		size_field(int count, t_flags *flags);

typedef struct s_flags
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
}		t_flags;
#endif
