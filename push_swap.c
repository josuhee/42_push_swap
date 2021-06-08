/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:26:10 by sujo              #+#    #+#             */
/*   Updated: 2021/06/08 21:26:55 by sujo             ###   ########.fr       */
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

void static		set_pivot(t_info *info)
{
	int idx;

	idx = info->a_top;
	while (idx > 0)
	{
		if (info->a[idx] > info->a[idx - 1])
		{
			printf("pivot : %d\n", info->a[idx]);
		}
		idx--;
	}
}


void			push_swap(int argc, char *argv[])
{
	t_info	info;
	int		i;

	i = 0;
	setting_num(&info, argv, argc);
	set_pivot(&info);
	push_a_or_b(&info, pa, info.b_top + 1);
	print_stack(info);
}
