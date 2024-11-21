/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:36:14 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/21 23:33:43 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <stdint.h>
#include "../libft/libft.h"

static int	is_overflow(unsigned long n, const char *str, size_t i, int s);

int	ft_atoi(const char *nptr)
{
	unsigned long	n;
	int				s;
	size_t			i;

	i = 0;
	n = 0;
	s = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = -s;
		++i;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (is_overflow(n, nptr, i, s) == -1)
			return (-1);
		else if (is_overflow(n, nptr, i, s) == 0)
			return (0);
		n = n * 10 + (nptr[i] - '0');
		++i;
	}
	return (n * s);
}

static int	is_overflow(unsigned long n, const char *str, size_t i, int s)
{
	if (n > LONG_MAX / 10)
	{
		if (s > 0)
			return (-1);
		else if (s < 0)
			return (0);
	}
	else if ((long)n * 10 > LONG_MAX - (str[i] - '0'))
		return (0);
	return (1);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	*ft_memset(void *s, int c, size_t n)
{
	uint8_t	*str;
	size_t	i;

	i = 0;
	str = (uint8_t *)s;
	while (n > 0)
	{
		str[i] = c;
		--n;
		++i;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	ft_memset(str, '\0', n);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}


void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*calloc;
	size_t	total_size;

	if (!nmemb || !size)
		total_size = 0;
	else
	{
		if (nmemb > SIZE_MAX / size)
			return (NULL);
		total_size = size * nmemb;
	}
	calloc = malloc(total_size);
	if (!calloc)
		return (NULL);
	ft_bzero(calloc, total_size);
	return (calloc);
}

void	rev_space_and_char(char *str)
{
	size_t	i;
	char	swap;
	size_t	j;

	swap = '0';
	i = 0;
	j = 0;
	while (str[j] == ' ')
		j++;
	while (str[j] && str[i] == ' ')
	{
		swap = str[i];
		str[i] = str[j];
		str[j] = swap;
		++i;
		++j;
	}
}
