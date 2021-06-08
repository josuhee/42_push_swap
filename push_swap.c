/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:26:10 by sujo              #+#    #+#             */
/*   Updated: 2021/06/08 16:27:56 by sujo             ###   ########.fr       */
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

void			push_swap(int argc, char *argv[])
{
	t_info	info;
	int		i;

	i = 0;
	setting_num(&info, argv, argc);
	if (info.a_top / 2 > 0)
		push_a_or_b(&info, pb, (info.a_top + 1) / 2);
	print_stack(info);
}
