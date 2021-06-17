/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:42:04 by sujo              #+#    #+#             */
/*   Updated: 2021/06/16 14:04:42 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_info *info)
{
	int tmp;

	if (info->a_top >= 1)
	{
		tmp = info->a[info->a_top];
		info->a[info->a_top] = info->a[info->a_top - 1];
		info->a[info->a_top - 1] = tmp;
	}
}

void	sb(t_info *info)
{
	int tmp;

	if (info->b_top >= 1)
	{
		tmp = info->b[info->b_top];
		info->b[info->b_top] = info->b[info->b_top - 1];
		info->b[info->b_top - 1] = tmp;
	}
}

void	ss(t_info *info)
{
	sa(info);
	sb(info);
}

void	pa(t_info *info)
{
	if (info->b_top >= 0)
	{
		info->a_top += 1;
		info->a[info->a_top] = info->b[info->b_top];
		info->b_top -= 1;
	}
}

void	pb(t_info *info)
{
	if (info->a_top >= 0)
	{
		info->b_top += 1;
		info->b[info->b_top] = info->a[info->a_top];
		info->a_top -= 1;
	}
}
