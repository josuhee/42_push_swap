/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:26:10 by sujo              #+#    #+#             */
/*   Updated: 2021/06/09 16:57:12 by sujo             ###   ########.fr       */
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

static int		check_ascending(t_info *info)
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

//1st version
static void		go_ascending(t_info *info, int max)
{
	if (check_ascending(info))
		return ;
	if (info->a[info->a_top] > info->a[info->a_top - 1])
			sa(info, 1);
	else
		ra(info, 1);
	if (info->a[info->a_top] == max)
	{
		ra(info, 1);
		if (check_ascending(info))
			return ;
	}
	go_ascending(info, max);
}


void			push_swap(int argc, char *argv[])
{
	t_info	info;
	int		i;
	int		max;

	i = 0;
	setting_num(&info, argv, argc);
	max = info.a[0];
	while (++i <= info.a_top)
		max = max > info.a[i] ? max : info.a[i];
	//1st version
	go_ascending(&info, max);
}
