/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:52:55 by anovelli          #+#    #+#             */
/*   Updated: 2022/06/14 12:41:05 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

static void	check_int_and_fill(int argc, char **argv, t_stack *a, int flag)
{
	int		i;
	long	temp;
	int		digit;

	i = 0;
	while (i < argc - flag)
	{
		digit = check_char(argv[i + flag]);
		if (!digit)
			err("Error\n");
		if ((int)ft_strlen(argv[i + flag]) > 11)
			err("Error\n");
		temp = ft_atol(argv[i + flag]);
		if (temp >= 2147483648 || temp < -2147483648)
			err("Error\n");
		a->array[i++] = (int)temp;
	}
	a->len = argc - flag;
}

void	check_dup(t_stack *a)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	j = 0;
	ret = 0;
	while (i < a->len)
	{
		while (j < a->len)
		{
			if (a->array[j] == a->array[i])
				ret++;
			if (ret > 1)
				err("ErrorDUP\n");
			j++;
		}
		ret = 0;
		i++;
		j = i;
	}
}

void	find_max_min(t_stack *a)
{
	int	i;

	i = 0;
	a->min = a->array[i];
	a->max = a->array[i];
	while (i < a->len)
	{
		if (a->array[i] < a->min)
			a->min = a->array[i];
		if (a->array[i] > a->max)
			a->max = a->array[i];
		i++;
	}
}

void	checks(int argc, char **argv, t_stack *a, int flag)
{
	check_int_and_fill(argc, argv, a, flag);
	check_dup(a);
	find_max_min(a);
}
