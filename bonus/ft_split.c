/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:29:14 by sujo              #+#    #+#             */
/*   Updated: 2021/06/16 14:04:11 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		str_size(const char *str, char c)
{
	size_t	size;
	int		flag;

	size = 0;
	flag = 1;
	while (*str)
	{
		if (flag && *str != c)
		{
			size++;
			flag = 0;
		}
		if (*str == c)
			flag = 1;
		str++;
	}
	return (size);
}

static char		*get_str_split(char const *s, char c)
{
	char		*result;
	const char	*ptr;
	size_t		length;

	ptr = s;
	length = 0;
	while (*ptr && *ptr++ != c)
		length++;
	result = (char *)malloc(length + 1);
	if (!result)
		return (0);
	ft_strlcpy(result, s, length + 1);
	return (result);
}

char			**go_free_split(char **str)
{
	size_t idx;

	idx = 0;
	while (str[idx])
		free(str[idx++]);
	free(str);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	int		idx;

	if (!s)
		return (0);
	result = (char **)malloc(sizeof(char*) * (str_size(s, c) + 1));
	if (!result)
		exit(1);
	idx = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			result[idx] = get_str_split(s, c);
			if (!result[idx++])
				return (go_free_split(result));
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	result[idx] = 0;
	return (result);
}
