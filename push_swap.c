/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:26:10 by sujo              #+#    #+#             */
/*   Updated: 2021/06/14 00:09:57 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//제출 시 지우기 + stdio
void			print_stack(t_info info)
{
	printf("A : ");
	for (int i=0;i<=info.a_top;i++)
		printf("%d ", info.a[i]);
	printf("\n");
	printf("B : ");
	for (int i=0;i<=info.b_top;i++)
		printf("%d ", info.b[i]);
	printf("\n");
}

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

static int		check_sort_b(t_info *info)
{
	int i;

	i = 0;
	while (i < info->b_top)
	{
		if (info->b[i] > info->b[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void		a_to_b(t_info *info, int size)
{
	t_cnt cnt;
	t_pivot point;
	int idx;

	cnt.ra = 0;
	cnt.pb = 0;
	cnt.rb = 0;
	if (size <= 3)
	{
		small_sort(info, size, 1);
		return ;
	}
	//적절한 pivot 2개 고르기
	point = get_pivot(info, size, 1);
	idx = 0;
	while (idx < size)
	{
		if (info->a[info->a_top] >= point.p1)
		{
			ra(info, 1);
			cnt.ra += 1;
		}
		else
		{
			pb(info);
			cnt.pb += 1;
			if (info->b[info->b_top] >= point.p2)
			{
				rb(info, 1);
				cnt.rb += 1;
			}
		}
		idx++;
	}
	idx = 0;
	while (idx < cnt.ra && idx < cnt.rb)
	{
		idx++;
		rrr(info);
	}
	if (idx < cnt.ra)
		while (idx++ < cnt.ra)
			rra(info, 1);
	else
		while (idx++ < cnt.rb)
			rrb(info, 1);
	a_to_b(info, cnt.ra); //[3]
	b_to_a(info, cnt.rb); //[2]
	b_to_a(info, cnt.pb - cnt.rb); //[1]
}

void			b_to_a(t_info *info, int size)
{
	t_cnt cnt;
	t_pivot point;
	int idx;

	cnt.ra = 0;
	cnt.pa = 0;
	cnt.rb = 0;

	if (size <= 3)
	{
		small_sort(info, size, 0);
		return ;
	}
	//적절한 pivot 선택
	point = get_pivot(info, size, 0);
	idx = 0;
	while (idx < size)
	{
		if (info->b[info->b_top] <= point.p2)
		{
			rb(info, 1);
			cnt.rb += 1;
		}
		else
		{
			pa(info);
			cnt.pa += 1;
			if (info->a[info->a_top] <= point.p1)
			{
				ra(info, 1);
				cnt.ra += 1;
			}
		}
		idx++;
	}
	a_to_b(info, cnt.pa - cnt.ra); //[3]
	idx = 0;
	while (idx < cnt.ra && idx < cnt.rb)
	{
		idx++;
		rrr(info);
	}
	if (idx < cnt.ra)
		while (idx++ < cnt.ra)
			rra(info, 1);
	else
		while (idx++ < cnt.rb)
			rrb(info, 1);
	a_to_b(info, cnt.rb); //[2]
	b_to_a(info, cnt.ra); //[1]
}

void			push_swap(int argc, char *argv[])
{
	t_info	info;

	setting_num(&info, argv, argc);
	a_to_b(&info, info.size);
}
