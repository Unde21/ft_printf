/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammy <sammy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 01:30:56 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/25 13:13:54 by sammy            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>

# define LOWER_BASE "0123456789abcdef"
# define UPPER_BASE "0123456789ABCDEF"

// function libft
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);

int			ft_printf(const char *format, ...);
int			print_char(int c);
int			print_str(char *str);
int			format_is_valid(const char *format);
int			print_addr(unsigned long ptr, int count, int index);
int			print_nbr(int n, int check_form, int count);
bool		valid_format(char format);
int			print_hexa(unsigned int n, const char *base, int count);
int			check_format(va_list *params, char format);
int			count_hex_digits(unsigned long n);
int			pos_next_format(char *format);

void		rev_space_and_char(char *str);
typedef struct s_flags
{
	bool	space;
	bool	zero;
	bool	sign;
	bool	less;
	bool	prefix;
	bool	point;
	size_t	nb;
	int		count;
	int		padding;
	int		precision;
	int		size_precision;
	int		size_padding;
	char	*base_to;
}			t_flags;

// format 'x' and 'X'
int			adding_prefix(t_flags *flags, char *s, int len, int check);
void		adding_precision_buffer(t_flags *flags, char *s, int len,
				unsigned int n);
void		adding_all_flag_buffer(t_flags *flags, char *s, int len,
				unsigned int n);
void		print_X(va_list *params, t_flags *flags);
void		print_x(va_list *params, t_flags *flags);
char		*ft_itoa_base_hex(unsigned int n, t_flags *flags, int len, char *s);
int			buffersize_hex(unsigned int n, t_flags *flags);
void		convert_hex(t_flags *flags, unsigned int n, int len);

// format 'c'
int			buffersize_c(t_flags *flags);
char		*manage_flags_c(t_flags *flags, char *s, int len, int c);
void		print_c(va_list *params, t_flags *flags);

//  format 'p'
void		print_p(va_list *params, t_flags *flags);
int			buffersize_addr(unsigned long n, t_flags *flags);
void		convert_addr(t_flags *flags, unsigned long n, int len);
char		*manage_flags_addr(t_flags *flags, char *s, int len,
				unsigned long n);

// format 's'
char		*manage_flags_s(t_flags *flags, char *s, char *str);
int			buffersize_s(char *str, t_flags *flags);
void		print_s(va_list *params, t_flags *flags);

// format 'i' and 'd'
void		adding_precision_nb(t_flags *flags, char *s, int len, int n);
char		*manage_flags_nb(t_flags *flags, char *s, int len, int n);
int			buffersize_nb(int n, t_flags *flags);
int			count_digits_nb(int n);
void		print_nb(va_list *params, t_flags *flags);
char		*itoa(int n, int len, char *s);

/* format u */
char	*unsigned_itoa(int n, int len, char *s);
int	count_digits_u_nb(unsigned int n);
int	buffersize_u_nb(unsigned int n, t_flags *flags);
void	print_unb(va_list *params, t_flags *flags);
char	*manage_flags_u_nb(t_flags *flags, char *s, int len, unsigned int n);
void	adding_padding_u_nb(t_flags *flags, char *s);

void		change_struct_flags(char format, t_flags *flags);
int			parse_format(va_list *params, char *format, t_flags *flags);
int			parse_flags(char *format, t_flags *flags);
void		reset_struct(t_flags *flags);
int			check_flg_format(va_list *params, char *format, t_flags *flags);

#endif
