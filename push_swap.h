/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:27:19 by sujo              #+#    #+#             */
/*   Updated: 2021/06/07 19:16:15 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_info
{
	int			*a;
	int			*b;
	int			a_top;
	int			b_top;
}				t_info;

void			push_swap(int argc, char *argv[]);

void			sa(t_info *info, int flag);
void			sb(t_info *info, int flag);
void			ss(t_info *info);
void			pa(t_info *info);
void			pb(t_info *info);

void			ra(t_info *info, int flag);
void			rb(t_info *info, int flag);
void			rr(t_info *info);

void			rra(t_info *info, int flag);
void			rrb(t_info *info, int flag);
void			rrr(t_info *info, int flag);

#endif
