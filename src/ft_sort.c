/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 23:06:40 by sujo              #+#    #+#             */
/*   Updated: 2021/06/16 18:34:55 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_sort(int arr[], int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int				*copy_arr(t_info *info, int size, int flag)
{
	int *arr;
	int idx;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		exit(1);
	idx = -1;
	if (flag == 1)
	{
		while (++idx < size)
			arr[idx] = info->a[info->a_top - idx];
	}
	else
	{
		while (++idx < size)
			arr[idx] = info->b[info->b_top - idx];
	}
	return (arr);
}

t_pivot			get_pivot(t_info *info, int size, int flag)
{
	t_pivot		point;
	int			*arr;
	int			term;

	arr = copy_arr(info, size, flag);
	ft_sort(arr, size);
	term = size / 3;
	if (size % 3 == 2)
		term++;
	if (flag == 1)
	{
		point.p1 = arr[size - term];
		point.p2 = arr[size - term * 2];
	}
	else
	{
		point.p1 = arr[term * 2 - 1];
		point.p2 = arr[term - 1];
	}
	free(arr);
	return (point);
}

void			small_sort_a(t_info *info, int size)
{
	if (size == 2 || size == 3)
	{
		if (info->a[info->a_top] > info->a[info->a_top - 1])
			sa(info, 1);
		if (size == 3)
		{
			if (info->a[info->a_top - 1] > info->a[info->a_top - 2])
			{
				ra(info, 1);
				sa(info, 1);
				rra(info, 1);
				if (info->a[info->a_top] > info->a[info->a_top - 1])
					sa(info, 1);
			}
		}
	}
	if (size == 4)
		four_arg(info);
}

void			small_sort_b(t_info *info, int size)
{
	if (size >= 1 && size <= 3)
		pa(info);
	if (size == 2 || size == 3)
	{
		pa(info);
		if (info->a[info->a_top] > info->a[info->a_top - 1])
			sa(info, 1);
		if (size == 3)
		{
			pa(info);
			if (info->a[info->a_top] > info->a[info->a_top - 1])
				sa(info, 1);
			if (info->a[info->a_top - 1] > info->a[info->a_top - 2])
			{
				ra(info, 1);
				sa(info, 1);
				rra(info, 1);
				if (info->a[info->a_top] > info->a[info->a_top - 1])
					sa(info, 1);
			}
		}
	}
}
