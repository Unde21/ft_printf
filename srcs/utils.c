/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 04:36:14 by samaouch          #+#    #+#             */
/*   Updated: 2024/11/19 04:36:16 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>

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
