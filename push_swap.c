/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:26:10 by sujo              #+#    #+#             */
/*   Updated: 2021/06/07 22:14:58 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		stack_init(t_info *info, char *argv[], int argc)
{
	int idx;
	int num;

	setting_num(info, argv, argc);
}

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
	printf("\n\n");
}

void			push_swap(int argc, char *argv[])
{
	t_info	info;

	stack_init(&info, argv, argc);
	print_stack(info);
}
