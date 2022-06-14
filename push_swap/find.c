/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:33:15 by anovelli          #+#    #+#             */
/*   Updated: 2022/06/08 16:50:56 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_place(t_stack *b, int val)
{
	int	i;

	i = 0;
	while (i < b->len)
	{
		if (val > b->array[i] && b->array[i + 1] > val)
			return (i + 1);
		i++;
	}
	return (-1);
}

void	find_min(t_stack *a)
{
	int	i;

	i = 0;
	a->min = a->max;
	while (i < a->len)
	{
		if (a->array[i] < a->min)
			a->min = a->array[i];
		i++;
	}
}

int	find_ind(t_stack *a, int val)
{
	int	i;

	i = 0;
	while (i < a->len)
	{
		if (a->array[i] == val)
			return (i);
		i++;
	}
	return (0);
}

int	find_min_arr(int *arr, int len)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while (i < len)
	{
		if (arr[i] < arr[ret])
			ret = i;
		i++;
	}
	return (ret);
}

void	find_place_and_insert(t_stack *a, t_stack *b, int moves)
{
	int	i;

	i = 0;
	find_max_min(a);
	if (b->array[moves] < a->max && b->array[moves] > a->min && a->len != 0)
	{
		choose_bet(a, b, &moves, &i);
		move_b(&moves, b);
	}
	else if (b->array[moves] < a->min && a->len != 0)
	{
		choose_min(a, b, &moves);
		move_b(&moves, b);
	}
	else if (b->array[moves] > a->max && a->len != 0)
	{
		choose_max(a, b, &moves);
		move_b(&moves, b);
	}
	pa(a, b);
}
