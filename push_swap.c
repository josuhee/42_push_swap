/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:26:10 by sujo              #+#    #+#             */
/*   Updated: 2021/06/13 12:19:36 by sujo             ###   ########.fr       */
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

void			push_a_or_b(t_info *info, void (*push)(t_info *), int cnt)
{
	int idx;

	idx = 0;
	while (idx < cnt)
	{
		push(info);
		idx++;
	}
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

//1st version
static void		go_ascending(t_info *info, int max)
{
	if (check_sort_a(info))
		return ;
	if (info->a[info->a_top] > info->a[info->a_top - 1])
			sa(info, 1);
	else
		ra(info, 1);
	if (info->a[info->a_top] == max)
	{
		ra(info, 1);
		if (check_sort_a(info))
			return ;
	}
	go_ascending(info, max);
}

//2nd version
static void		go_ascending2(t_info *info, int flag)
{
	if (info->pivot == info->a[info->a_top])
	{
		if (flag == 0)
		{
			flag = 1;
			ra(info, 1);
		}
		else
			return ;
	}
	if (check_sort_a(info) && info->b_top == -1)
		return ;
	if (info->pivot <= info->a[info->a_top])
	{
		/*
		if (info->a[info->a_top] > info->a[info->a_top - 1])
			sa(info, 1);
		else
			ra(info, 1);
		*/
		ra(info, 1);
	}
	else
		pb(info);
	go_ascending2(info, flag);
}

static void		func(t_info *info)
{
	int a;
	int b;

	a = check_sort_a(info);
	b = check_sort_b(info);
	if (a && b)
		return ;
	if (info->a[info->a_top] == info->max || info->b[info->b_top] == info->min)
	{
		if ((info->a[info->a_top] == info->max) && (info->b[info->b_top] == info->min))
			rr(info);
		else if (info->a[info->a_top] == info->max)
			ra(info, 1);
		else if (info->b[info->b_top] == info->min)
			rb(info, 1);
		func(info);
		return ;
	}
	a = info->a[info->a_top] > info->a[info->a_top - 1] ? 1 : 0;
	b = info->b[info->b_top] < info->b[info->b_top - 1] ? 1 : 0;
	if ((!a && !check_sort_a(info))|| (!b && !check_sort_b(info)))
	{
		if ((!a && !check_sort_a(info) && (!b && !check_sort_b(info))))
			rr(info);
		else if (!a && !check_sort_a(info))
			ra(info, 1);
		else if (!b && !check_sort_b(info))
			rb(info, 1);
		func(info);
		return ;
	}
	if (a && b)
		ss(info);
	else if (a)
		sa(info, 1);
	else
		sb(info, 1);
	func(info);
}

static int circle_num(t_info *info)
{
	int flag;
	int idx;

	idx = info->a_top;
	flag = 0;
	while (idx > 0)
	{
		if (info->a[idx] > info->a[idx - 1])
		{
			flag = 1;
			idx--;
			break ;
		}
		idx--;
	}
	if (flag)
	{
		while (idx > 0)
		{
			if (info->a[idx] > info->a[idx - 1])
				return (0);
			idx--;
		}
	}
	return (1);
}

static int check_under_num(t_info *info)
{
	int idx;

	idx = 0;
	while (idx <= info->a_top)
	{
		if (info->pivot > info->a[idx])
			return (1);
		idx++;
	}
	return (0);
}

static void		push_b(t_info *info, int size, int cnt)
{
	if (cnt == size)
		return ;
	if (info->a[info->a_top] < info->ret[info->size - size])
	{
		pb(info);
		push_b(info, size, cnt + 1);
	}
	else
	{
		ra(info, 1);
		push_b(info, size, cnt);
	}
}

static void		push_a(t_info *info, int size, int cnt)
{
	if (cnt == size)
		return ;
	pa(info);
	if (info->a[info->a_top] > info->a[info->a_top - 1])
		sa(info, 1);
	push_a(info, size, cnt + 1);
}

//3rd version
static void		go_ascending3(t_info *info, int size)
{
	if (check_sort_a(info))
		return ;
	if (size > 0)
	{
		info->loc = size;
		printf("%d\n", size);
		push_b(info, size, 0);
		go_ascending3(info, size / 2);
	}
}

static void		func_3(t_info *info, int size)
{
	if (size < info->loc)
		return ;
	func_3(info, size / 2);
	if (size < 3)
		push_a(info, size, 0);

	if (!check_sort_a(info))
	{
		//go sort
	}
}

void			push_swap(int argc, char *argv[])
{
	t_info	info;
	int		i;

	i = 0;
	setting_num(&info, argv, argc);
	/*1st version(~ 12000)*/
	//go_ascending(&info, info.a_max);
	/*2nd version(3400 ~ 4500)*/
	/*
	info.pivot=get_middle(&info);
	go_ascending2(&info, 0);
	func(&info);
	push_a_or_b(&info, pa, info.b_top + 1);
	*/
	/*3rd version*/
	info.pivot=get_middle(&info);
	go_ascending3(&info, info.size / 2);
	init_a_stack(&info);
	print_stack(info);
	//func_3(&info, info.size / 2);
}
