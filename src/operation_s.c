/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:42:04 by sujo              #+#    #+#             */
/*   Updated: 2021/06/07 16:17:25 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *info, int flag)
{
	int tmp;

	if (info->a_top >= 1)
	{
		tmp = info->a[info->a_top];
		info->a[info->a_top] = info->a[info->a_top - 1];
		info->a[info->a_top - 1] = tmp;
	}
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_info *info, int flag)
{
	int tmp;

	if (info->b_top >= 1)
	{
		tmp = info->b[info->b_top];
		info->b[info->b_top] = info->b[info->b_top - 1];
		info->b[info->b_top - 1] = tmp;
	}
	if (flag)
		write(1, "sb\n", 3);
}

void	ss(t_info *info)
{
	sa(info, 0);
	sb(info, 0);
	write(1, "ss\n", 3);
}

void	pa(t_info *info)
{
	if (info->b_top >= 0)
	{
		info->a_top += 1;
		info->a[info->a_top] = info->b[info->b_top];
		info->b_top -= 1;
		write(1, "pa\n", 3);
	}
}

void	pb(t_info *info)
{
	if (info->a_top >= 0)
	{
		info->b_top += 1;
		info->b[info->b_top] = info->a[info->a_top];
		info->a_top -= 1;
		write(1, "pb\n", 3);
	}
}
