/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:20:34 by sujo              #+#    #+#             */
/*   Updated: 2021/06/16 19:29:25 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_info *info)
{
	int tmp;
	int idx;

	idx = info->a_top;
	if (idx != -1)
	{
		tmp = info->a[info->a_top];
		while (idx > 0)
		{
			info->a[idx] = info->a[idx - 1];
			idx--;
		}
		info->a[0] = tmp;
	}
}

void	rb(t_info *info)
{
	int tmp;
	int idx;

	idx = info->b_top;
	if (idx != -1)
	{
		tmp = info->b[info->b_top];
		while (idx > 0)
		{
			info->b[idx] = info->b[idx - 1];
			idx--;
		}
		info->b[0] = tmp;
	}
}

void	rr(t_info *info)
{
	ra(info);
	rb(info);
}
