/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:41:47 by sujo              #+#    #+#             */
/*   Updated: 2021/06/16 15:13:27 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_g(const char *s)
{
	size_t size;

	size = 0;
	while (*s++)
		size++;
	return (size);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	idx;

	idx = 0;
	result = (char *)malloc(ft_strlen_g(s) + 1);
	if (!result)
		return (0);
	while (s[idx] != '\0')
	{
		result[idx] = s[idx];
		idx++;
	}
	result[idx] = '\0';
	return (result);
}

char	*ft_str_copy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*result;
	char	*ptr;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen_g(s1);
	len2 = ft_strlen_g(s2);
	if (len1 + len2 == 0)
		return (ft_strdup(""));
	result = (char *)malloc(len1 + len2 + 1);
	if (!result)
		return (0);
	ptr = result;
	ptr = ft_str_copy(result, (char *)s1);
	ptr = ft_str_copy(ptr, (char *)s2);
	free(s1);
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	idx;
	size_t	str_len;

	if (!s)
		return (0);
	str_len = ft_strlen_g(s);
	if (str_len < start)
		return (ft_strdup(""));
	if (str_len < start + len)
		len = str_len - start;
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	idx = 0;
	while (idx < len && s[idx + start] != '\0')
	{
		result[idx] = s[idx + start];
		idx++;
	}
	result[idx] = '\0';
	return (result);
}
