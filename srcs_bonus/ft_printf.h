/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:30:56 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/30 19:54:48 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>

# define LOWER_BASE "0123456789abcdef"
# define UPPER_BASE "0123456789ABCDEF"

typedef struct s_flags
{
	bool	space;
	bool	zero;
	bool	sign;
	bool	less;
	bool	prefix;
	bool	point;
	bool	is_precision;
	int		count;
	int		padding;
	int		precision;
	int		size_precision;
	int		size_padding;
	char	*base_to;
}			t_flags;

void		rev_space_nb(char *s, size_t len);
void		rev_space_and_char(char *str);
void		reset_struct(t_flags *flags);
void		print_x(va_list *params, t_flags *flags);
void		print_upper_x(va_list *params, t_flags *flags);
void		print_unb(va_list *params, t_flags *flags);
void		print_s(va_list *params, t_flags *flags);
void		print_p(va_list *params, t_flags *flags);
void		print_nb(va_list *params, t_flags *flags);
void		print_c(va_list *params, t_flags *flags);
void		manage_flags_s(t_flags *flags, char *s, char *str);
void		convert_hex(t_flags *flags, unsigned int n, int len);
void		convert_addr(t_flags *flags, unsigned long n, int len);
void		change_struct_flags(char format, t_flags *flags);
void		addr_null(char *s, int len, t_flags *flags);
void		adding_precision_buffer(t_flags *flags, char *s, int len,
				unsigned int n);
void		adding_padding_u_nb(t_flags *flags, char *s);
void		adding_padding_nb(t_flags *flags, char *s, int len, int n);
void		adding_all_flag_buffer(t_flags *flags, char *s, int len,
				unsigned int n);
void		adding_padding_s(t_flags *flags, char *s, char *str, int i);

int			print_str(char *str);
int			print_nbr(int n, int check_form, int count);
int			skip_zero(char *format);
int			print_hexa(unsigned int n, const char *base, int count);
int			print_char(int c);
int			print_addr(unsigned long ptr, int count, int index);
int			pos_next_format(char *format);
int			parse_format(va_list *params, char *format, t_flags *flags);
int			parse_flags(char *format, t_flags *flags);
int			ft_printf(const char *format, ...)__attribute__((format(printf, 1, 2)));
int			format_is_valid(const char *format);
int			count_hex_digits(unsigned long n);
int			count_digits_u_nb(unsigned int n);
int			count_digits_nb(int n);
int			check_format(va_list *params, char format);
int			check_flg_format(va_list *params, char *format, t_flags *flags);
int			buffersize_u_nb(unsigned int n, t_flags *flags);
int			buffersize_s(char *str, t_flags *flags);
int			buffersize_nb(int n, t_flags *flags);
int			buffersize_hex(unsigned int n, t_flags *flags);
int			buffersize_c(t_flags *flags);
int			buffersize_addr(unsigned long n, t_flags *flags);
int			adding_prefix(t_flags *flags, char *s, int len, int check);
int			adding_precision(t_flags *flags, int len, char *s);
int			calculate_field_nb(t_flags *flags, int buffer_size, int nb_digits,
				int n);
int			calc_field_unb(t_flags *flags, int buffer_size, int n_digit,
				unsigned int n);
int			calculate_size_precision_s(t_flags *flags, int buffer_size);
int			calculate_field_s(t_flags *flags, int buffer_size);
int			calculate_field_hex(t_flags *flags, int buffer_size,
				unsigned int n);

char		*unsigned_itoa(unsigned int n, int len, char *s, t_flags *flags);
char		*manage_flags_u_nb(t_flags *flags, char *s, int len,
				unsigned int n);
char		*manage_flags_nb(t_flags *flags, char *s, int len, int n);
char		*manage_flags_c(t_flags *flags, char *s, int len, int c);
char		*manage_flags_addr(t_flags *flags, char *s, int len,
				unsigned long n);
char		*int_toa(int n, int len, char *s, t_flags *flags);
char		*ft_itoa_base_hex(unsigned long n, t_flags *flags, int len,
				char *s);

bool		valid_format(char format);
bool		is_flags(t_flags *flags);

#endif
