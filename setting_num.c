/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 21:33:26 by sujo              #+#    #+#             */
/*   Updated: 2021/06/07 23:10:05 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_atoi(char *str, int *result)
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

static int		check_duplicate(int *arr, int size, int num)
{
	int idx;

	idx = 0;
	while (idx < size)
	{
		if (arr[idx] == num)
			return (0);
		idx++;
	}
	return (1);
}

static int		num_size(const char *str, char c)
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
	if (!size)
		go_error();
	return (size);
}

static void		info_init(t_info *info, int size)
{
	info->a = (int *)malloc(sizeof(int) * size);
	info->a_top = -1;
	info->b = (int *)malloc(sizeof(int) * size);
	info->b_top = -1;
}

void			setting_num(t_info *info, char *argv[], int argc)
{
	int		size;
	int		idx;
	int		tmp_idx;
	char	**tmp;

	size = 0;
	idx = 1;
	while (idx < argc)
		size += num_size(argv[idx++], ' ');
	info_init(info, size);
	idx = 1;
	while (idx < argc)
	{
		tmp_idx = 0;
		tmp = ft_split(argv[idx++], ' ');
		while (tmp[tmp_idx])
		{
			info->a_top += 1;
			if (!ft_atoi(tmp[tmp_idx++], &info->a[info->a_top]) ||
				!check_duplicate(info->a, info->a_top, info->a[info->a_top]))
				go_error();
		}
		go_free_split(tmp);
	}
}
