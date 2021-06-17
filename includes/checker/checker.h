/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 13:46:12 by sujo              #+#    #+#             */
/*   Updated: 2021/06/16 20:33:49 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_info
{
	int			*a;
	int			*b;
	int			a_top;
	int			b_top;
	int			size;
}				t_info;

void			checker(int argc, char *argv[]);

/*
** operation
*/
void			sa(t_info *info);
void			sb(t_info *info);
void			ss(t_info *info);
void			pa(t_info *info);
void			pb(t_info *info);

void			ra(t_info *info);
void			rb(t_info *info);
void			rr(t_info *info);

void			rra(t_info *info);
void			rrb(t_info *info);
void			rrr(t_info *info);

/*
** parsing
*/
char			**ft_split(char const *s, char c);
char			**go_free_split(char **str);
void			ft_putstr(char *s);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
int				ft_atoi(char *str, int *result);
int				ft_strcmp(char *s1, char *s2);
void			setting_num(t_info *info, char *argv[], int argc);

void			go_error();

#endif
