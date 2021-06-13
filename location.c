/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 10:22:13 by sujo              #+#    #+#             */
/*   Updated: 2021/06/13 10:33:34 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_a_stack(t_info *info)
{
	if (info->a_top != -1)
	{
		if (info->a[info->a_top] > info ->a[info->a_top - 1])
			sa(info, 1);
		if (info->a_top == 2)
		{
			if (info->a[0] < info->a[1])
				rra(info, 1);
			if (info->a[info->a_top] > info ->a[info->a_top - 1])
			sa(info, 1);
		}
	}
}
