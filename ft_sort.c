/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 23:06:40 by sujo              #+#    #+#             */
/*   Updated: 2021/06/13 09:45:16 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		*copy_arr(t_info *info)
{
	int *arr;
	int idx;

	arr = (int *)malloc(sizeof(int) * info->size);
	if (!arr)
		exit(1);
	idx = -1;
	while (++idx < info->size)
		arr[idx] = info->a[idx];
	return (arr);
}

static void		ft_sort(int arr[], int size)
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

int				get_middle(t_info *info)
{
	int result;

	info->ret = copy_arr(info);
	ft_sort(info->ret, info->size);
	info->max = info->ret[info->size - 1];
	info->min = info->ret[0];
	result = info->ret[info->size / 2];
	return (result);
}
