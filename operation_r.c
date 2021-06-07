/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:20:34 by sujo              #+#    #+#             */
/*   Updated: 2021/06/07 18:58:54 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info *info, int flag)
{
	int tmp;
	int idx;

	idx = info->a_top;
	tmp = info->a[info->a_top];
	while (idx > 0)
	{
		info->a[idx] = info->a[idx - 1];
		idx--;
	}
	info->a[0] = tmp;
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_info *info, int flag)
{
	int tmp;
	int idx;

	idx = info->b_top;
	tmp = info->b[info->b_top];
	while (idx > 0)
	{
		info->b[idx] = info->b[idx - 1];
		idx--;
	}
	info->b[0] = tmp;
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_info *info)
{
	ra(info, 0);
	ra(info, 0);
	write(1, "rr\n", 3);
}
