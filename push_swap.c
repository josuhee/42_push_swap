/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:26:10 by sujo              #+#    #+#             */
/*   Updated: 2021/06/07 19:16:26 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_atoi(char *str, int *result)
{
	long	tmp;
	int		positive;

	tmp = 0;
	positive = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			positive = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		tmp *= 10;
		tmp += (*str - '0') * positive;
		str++;
	}
	if (*str != '\0' || tmp > 2147483647 || tmp < -2147483648)
		return (0);
	*result = tmp;
	return (1);
}

static int		check_duplicate(int *arr, int size, int num)
{
	int idx;

	idx = 0;
	while (idx < size)
	{
		if (arr[idx] == num)
			return (0);
		idx++;
	}
	return (1);
}

static void		go_error(t_info *info)
{
	free(info->a);
	free(info->b);
	write(1, "Error\n", 6);
	exit(1);
}

static void		stack_init(t_info *info, char *argv[], int argc)
{
	int idx;
	int num;

	info->a = (int *)malloc(sizeof(int) * (argc - 1));
	info->a_top = argc - 2;
	info->b = (int *)malloc(sizeof(int) * (argc - 1));
	info->b_top = -1;
	idx = 0;
	while (idx < argc - 1)
	{
		if (ft_atoi(argv[argc - 1 - idx], &num)
			&& check_duplicate(info->a, idx, num))
			info->a[idx] = num;
		else
			go_error(info);
		idx++;
	}
}

//제출 시 지우기 + stdio
void	print_stack(t_info info)
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
	ra(&info, 1);
	print_stack(info);
	rra(&info, 1);
	print_stack(info);
}
