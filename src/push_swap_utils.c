/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 04:21:02 by sujo              #+#    #+#             */
/*   Updated: 2021/06/16 18:33:28 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_arg(t_info *info)
{
	if (info->a[2] > info->a[1])
		sa(info, 1);
	if (info->a[0] < info->a[1])
	{
		rra(info, 1);
		if (info->a[1] < info->a[2])
			sa(info, 1);
	}
}

void	four_arg(t_info *info)
{
	if (info->a[info->a_top] > info->a[info->a_top - 1])
		sa(info, 1);
	pb(info);
	if (info->a[info->a_top] > info->a[info->a_top - 1])
		sa(info, 1);
	pb(info);
	if (info->a[info->a_top] > info->a[info->a_top - 1]
		&& info->b[info->b_top] < info->b[info->b_top - 1])
		ss(info);
	else if (info->a[info->a_top] > info->a[info->a_top - 1])
		sa(info, 1);
	else if (info->b[info->b_top] < info->b[info->b_top - 1])
		sb(info, 1);
	pa(info);
	if (info->a[info->a_top] > info->a[info->a_top - 1])
		sa(info, 1);
	pa(info);
	if (info->a[info->a_top] > info->a[info->a_top - 1])
		sa(info, 1);
}

void	five_arg(t_info *info)
{
	int *arr;
	int idx;

	idx = -1;
	arr = copy_arr(info, 5, 1);
	ft_sort(arr, 5);
	while (++idx < 5)
	{
		if (arr[1] >= info->a[info->a_top])
			pb(info);
		else
			ra(info, 1);
	}
	three_arg(info);
	if (info->b[0] > info->b[1])
		sb(info, 1);
	pa(info);
	pa(info);
	free(arr);
}

void	b_to_a_util(t_info *info, t_cnt *cnt, t_pivot point, int size)
{
	int idx;

	idx = 0;
	while (idx < size)
	{
		if (info->b[info->b_top] <= point.p2)
		{
			rb(info, 1);
			cnt->rb += 1;
		}
		else
		{
			pa(info);
			cnt->pa += 1;
			if (info->a[info->a_top] <= point.p1)
			{
				ra(info, 1);
				cnt->ra += 1;
			}
		}
		idx++;
	}
}

void	a_to_b_util(t_info *info, t_cnt *cnt, t_pivot point, int size)
{
	int idx;

	idx = 0;
	while (idx < size)
	{
		if (info->a[info->a_top] >= point.p1)
		{
			ra(info, 1);
			cnt->ra += 1;
		}
		else
		{
			pb(info);
			cnt->pb += 1;
			if (info->b[info->b_top] >= point.p2)
			{
				rb(info, 1);
				cnt->rb += 1;
			}
		}
		idx++;
	}
}
