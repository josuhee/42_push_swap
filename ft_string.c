/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:30:45 by sujo              #+#    #+#             */
/*   Updated: 2021/06/07 22:07:27 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
