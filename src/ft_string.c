/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:30:45 by sujo              #+#    #+#             */
/*   Updated: 2021/06/08 16:56:40 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_atoi(char *str, int *result)
{
	long	tmp;
	int		positive;

	tmp = 0;
	positive = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			positive = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		tmp *= 10;
		tmp += (*str - '0') * positive;
		str++;
	}
	if (*str != '\0' || tmp > 2147483647 || tmp < -2147483648)
		return (0);
	*result = tmp;
	return (1);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t idx;

	if (!dest || !src)
		return (0);
	idx = 0;
	if (size != 0)
	{
		while (idx < size - 1 && *src)
		{
			*dest = *src;
			dest++;
			src++;
			idx++;
		}
		*dest = '\0';
	}
	while (*src++)
		idx++;
	return (idx);
}

size_t	ft_strlen(const char *s)
{
	size_t size;

	size = 0;
	while (*s++)
		size++;
	return (size);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}
