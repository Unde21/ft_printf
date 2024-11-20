/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sammy <sammy@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 03:52:40 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/20 07:49:28 by sammy            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf_bonus.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

void	print_x(va_list *params, t_flags *flags)
{
	unsigned int	arg;
	size_t			total_length;

	flags->base_to = LOWER_BASE;
	arg = va_arg(*params, unsigned int);
	total_length = buffersize_hex(arg, flags);
	convert_hex(flags, arg, total_length);
}

int	buffersize_hex(unsigned int n, t_flags *flags)
{
	int	final_size;
	int	arg_is_valid;
	
	arg_is_valid = flags->arg2;
	final_size = 0;
	if (flags->arg2 == -1)
		flags->arg2 = 0;
	if (flags->arg1 == -1)
		flags->arg1 = 0;
	if (n == 0 && flags->point && flags->arg2 == 0)
		return (0);
	final_size = count_hex_digits(n);
		printf("1flags arg1 : %d, arg2 : %d, count : %d\n", flags->arg1, flags->arg2, final_size);
	final_size = handle_point(final_size, flags);
		printf("2flags arg1 : %d, arg2 : %d, final_size : %d\n", flags->arg1, flags->arg2, final_size);
	final_size = handle_sharp(final_size, n, flags);
		printf("3flags arg1 : %d, arg2 : %d, final_size : %d\n", flags->arg1, flags->arg2, final_size);
	final_size = size_field(final_size, flags);
		printf("4flags arg1 : %d, arg2 : %d, final_size : %d\n", flags->arg1, flags->arg2, final_size);
	if (arg_is_valid == -1 && flags->point && flags->sharp)
	{
		final_size += 2;
		flags->arg2 -= 2;
	}
	return (final_size);
}

int	count_hex_digits(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	else
	{
		while (n > 0)
		{
			n /= 16;
			++count;
		}
	}
	return (count);
}

void	convert_hex(t_flags *flags, unsigned int n, size_t len)
{
	char *buffer;
	
	buffer = calloc(sizeof(char), (len));
	if (!buffer)
		return ;
	printf("SIZE OF BUFFER %zu", len);
	buffer = ft_itoa_base(n, flags, len - 1, buffer);
	filling_buffer(flags, buffer, len - 1, n);
	if (flags->less)
		rev_space_and_num(buffer);
	flags->count += print_str(buffer);
	// size_t	i = 0;
	// while (i <= len)
	// {
	// 	printf("buffer[%zu] = '%c'\n", i, buffer[i]);
	// 	++i;
	// }
	// free(buffer);
}
void	filling_buffer(t_flags *flags, char *s, size_t len, unsigned int n)
{
	size_t	i;
	
	len -= count_hex_digits(n);       // ici - 1 ou + 1
	int len_n = count_hex_digits(n);
	printf("\n\n\niciflags arg1 : %d, arg2 : %d, final_size : %zu\n", flags->arg1, flags->arg2, len);
	printf("len : %zu", len);
	if (flags->point && flags->arg2 > len_n)
	{
		int test_l = 1 + flags->arg2 - len_n;
		while (test_l-- >= 0)
		{
			s[len--] = '0';
		}
	}
	// if (flags->sharp && flags->point)
	// {
	// 	s[len] = '0';
	// 	--len;
	// 	s[len] = '0';
	// 	--len;
	// }
	if (flags->sharp && n != 0 && len >= 1)
	{
		//printf("len : %zu", len);
		if (ft_strncmp(flags->base_to, LOWER_BASE, 16) == 0)
			s[len] = 'x';
		else
			s[len] = 'X';
		//printf("len : %zu", len);
		--len;
		s[len] = '0';
		printf("len : %zu", len);
	}
	if (flags->zero && !flags->less && !flags->point)
	{
		while (flags->arg1 >= 0)
		{
			if (flags->sharp && len == 2)
				break;
			s[len] = '0';
			--len;
			--flags->arg1;
		}
		if (flags->sharp && n != 0 && len >= 1)
		{
			if (ft_strncmp(flags->base_to, LOWER_BASE, 16) == 0)
				s[len] = 'x';
			else
				s[len] = 'X';
			--len;
			s[len] = '0';
			printf("len : %zu", len);
		}
	}
	i = 0;
	while (flags->arg1 > 0 && i <= len)
	{
		if (s[i] != '0' && s[i] != 'x')
			s[i++] = ' ';
		--flags->arg1;		
	}
}
char	*ft_itoa_base(unsigned int n, t_flags *flags, size_t len, char *s)
{
	char	*base_to;

	base_to = flags->base_to;
	while (n > 0)
	{
		s[len--] = base_to[n % 16];
		n  /= 16;
	}
	//s[len] = base_to[n % 16];
	return (s);
}