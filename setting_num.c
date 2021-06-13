/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 21:33:26 by sujo              #+#    #+#             */
/*   Updated: 2021/06/12 23:15:11 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	info->size = size;
	if (!info->a || !info->b)
		exit(1);
}

void			swap_stack(t_info *info)
{
	int left;
	int right;
	int tmp;

	left = 0;
	right = info->a_top;
	while (left < right)
	{
		tmp = info->a[left];
		info->a[left] = info->a[right];
		info->a[right] = tmp;
		left++;
		right--;
	}
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
	swap_stack(info);
}
