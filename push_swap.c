/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:26:10 by sujo              #+#    #+#             */
/*   Updated: 2021/06/14 04:58:29 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_sort_a(t_info *info)
{
	int i;

	i = 0;
	while (i < info->a_top)
	{
		if (info->a[i] < info->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int		check_sort_b(t_info *info, int size)
{
	int i;

	i = info->b_top;
	while (i > size)
	{
		if (info->b[i] < info->b[i - 1])
			return (0);
		i--;
	}
	return (1);
}

void		a_to_b(t_info *info, int size)
{
	t_cnt		cnt;
	t_pivot		point;
	int			idx;

	cnt = (t_cnt){0, 0, 0, 0};
	if (size <= 3)
	{
		small_sort_a(info, size);
		return ;
	}
	point = get_pivot(info, size, 1);
	a_to_b_util(info, &cnt, point, size);
	idx = -1;
	while (++idx < cnt.ra)
		rrr(info);
	a_to_b(info, cnt.ra); //[3]
	b_to_a(info, cnt.rb); //[2]
	b_to_a(info, cnt.pb - cnt.rb); //[1]
}

void			b_to_a(t_info *info, int size)
{
	t_cnt		cnt;
	t_pivot		point;
	int			idx;

	cnt = (t_cnt){0, 0, 0, 0};
	if (size <= 3)
	{
		small_sort_b(info, size);
		return ;
	}
	point = get_pivot(info, size, 0);
	b_to_a_util(info, &cnt, point, size);
	a_to_b(info, cnt.pa - cnt.ra); //[3]
	idx = -1;
	while (++idx < cnt.ra)
		rrr(info);
	a_to_b(info, cnt.rb); //[2]
	b_to_a(info, cnt.ra); //[1]
}

void			push_swap(int argc, char *argv[])
{
	t_info	info;

	setting_num(&info, argv, argc);
	if (!check_sort_a(&info))
	{
		if (info.a_top == 2)
			three_arg(&info);
		else
			a_to_b(&info, info.size);
	}
}
