/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:59:29 by sujo              #+#    #+#             */
/*   Updated: 2021/06/16 14:04:37 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_info *info)
{
	int tmp;
	int idx;

	idx = 0;
	tmp = info->a[0];
	while (idx < info->a_top)
	{
		info->a[idx] = info->a[idx + 1];
		idx++;
	}
	info->a[info->a_top] = tmp;
}

void	rrb(t_info *info)
{
	int tmp;
	int idx;

	idx = 0;
	tmp = info->b[0];
	while (idx < info->b_top)
	{
		info->b[idx] = info->b[idx + 1];
		idx++;
	}
	info->b[info->b_top] = tmp;
}

void	rrr(t_info *info)
{
	rra(info);
	rrb(info);
}
