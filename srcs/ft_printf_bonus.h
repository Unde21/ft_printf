/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammy <sammy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:30:56 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/20 15:21:20 by sammy            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>


#include <stdio.h>

# define LOWER_BASE "0123456789abcdef"
# define UPPER_BASE "0123456789ABCDEF"

// function libft 
int	ft_strncmp(const char *s1, const char *s2, size_t n);

int		ft_printf(const char *format, ...);
int		print_char(int c);
int		print_str(char *str);
int		format_is_valid(const char *format);
int		print_addr(unsigned long ptr, int count, int index);
int		print_nbr(int n, int check_form, int count);
bool	valid_format(char format);
int		print_hexa(unsigned int n, const char *base, int count);
int		check_format(va_list *params, char format);
int		count_hex_digits(unsigned int n);
int		pos_next_format(char *format);

void	rev_space_and_num(char *str);
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
	char	*base_to;
}		t_flags;



void	change_struct_flags(char format, t_flags *flags);
int		buffersize_hex(unsigned int n, t_flags *flags);
void	convert_hex(t_flags *flags, unsigned int n, size_t len);
char	*ft_itoa_base(unsigned int n, t_flags *flags, size_t len, char *s);
int		parse_format(va_list params, char *format, t_flags *flags);
int		parse_flags(char *format, t_flags *flags);
void	reset_struct(t_flags *flags);
void	print_x(va_list *params, t_flags *flags);
int		check_flg_format(va_list *params, char *format, t_flags *flags);
int		handle_point(int count, t_flags *flags);
int		handle_sharp(int count, unsigned int n, t_flags *flags);
int		size_field(int count, t_flags *flags);
void	filling_buffer(t_flags *flags, char *s, size_t len, unsigned int n);

#endif
