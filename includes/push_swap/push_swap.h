/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:27:19 by sujo              #+#    #+#             */
/*   Updated: 2021/06/16 18:28:40 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_info
{
	int			*a;
	int			*b;
	int			a_top;
	int			b_top;
	int			size;
}				t_info;

typedef struct	s_cnt
{
	int			ra;
	int			rb;
	int			pb;
	int			pa;
}				t_cnt;

typedef struct	s_pivot
{
	int			p1;
	int			p2;
}				t_pivot;

void			push_swap(int argc, char *argv[]);
void			a_to_b(t_info *info, int size);
void			b_to_a(t_info *info, int size);

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
void			rrr(t_info *info);

char			**ft_split(char const *s, char c);
char			**go_free_split(char **str);
void			ft_putstr(char *s);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
int				ft_atoi(char *str, int *result);

void			setting_num(t_info *info, char *argv[], int argc);

void			go_error();

void			ft_sort(int arr[], int size);
int				*copy_arr(t_info *info, int size, int flag);
t_pivot			get_pivot(t_info *info, int size, int flag);
void			small_sort_a(t_info *info, int size);
void			small_sort_b(t_info *info, int size);

void			three_arg(t_info *info);
void			four_arg(t_info *info);
void			five_arg(t_info *info);
void			b_to_a_util(t_info *info, t_cnt *cnt, t_pivot point, int size);
void			a_to_b_util(t_info *info, t_cnt *cnt, t_pivot point, int size);

#endif
