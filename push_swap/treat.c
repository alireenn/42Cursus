/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:49:44 by anovelli          #+#    #+#             */
/*   Updated: 2022/06/08 16:51:06 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_bet_sup(t_stack *a, int temp, int *i, int flag)
{
	if (!flag)
	{
		while (*i < a->len - temp)
		{
			rra(a, 1);
			(*i)++;
		}
	}
	else
	{
		while (*i < temp)
		{
			ra(a, 1);
			(*i)++;
		}
	}
}

void	choose_bet(t_stack *a, t_stack *b, int *moves, int *i)
{
	int	temp;

	temp = find_place(a, b->array[*moves]);
	if (temp > a->len / 2)
	{
		while (*i < a->len - temp && *moves > b->len / 2 && *moves)
		{
			rrr(a, b);
			change_ind(1, moves, b->len);
			(*i)++;
		}
		choose_bet_sup(a, temp, i, 0);
	}
	else
	{
		while (*i < temp && *moves < b->len / 2 && *moves)
		{
			rr(a, b);
			change_ind(0, moves, b->len);
			(*i)++;
		}
		choose_bet_sup(a, temp, i, 1);
	}
}

void	choose_min(t_stack *a, t_stack *b, int *ind)
{
	if (find_ind(a, a->min) > a->len / 2)
	{
		while (find_ind(a, a->min) && *ind > b->len / 2 && *ind)
		{
			rrr(a, b);
			change_ind(1, ind, b->len);
		}
		while (find_ind(a, a->min))
			rra(a, 1);
	}
	else
	{
		while (find_ind(a, a->min) && *ind < b->len / 2 && *ind)
		{
			rr(a, b);
			change_ind(0, ind, b->len);
		}
		while (find_ind(a, a->min))
			ra(a, 1);
	}
}

void	choose_max(t_stack *a, t_stack *b, int *ind)
{
	if (find_ind(a, a->max) > a->len / 2)
	{
		while (find_ind(a, a->max) && *ind > b->len / 2 && *ind)
		{
			rrr(a, b);
			change_ind(1, ind, b->len);
		}
		while (find_ind(a, a->max))
			rra(a, 1);
		if (!find_ind(a, a->max))
			ra(a, 1);
	}
	else
	{
		while (find_ind(a, a->max) && *ind < b->len / 2 && *ind)
		{
			rr(a, b);
			change_ind(0, ind, b->len);
		}
		while (find_ind(a, a->max))
			ra(a, 1);
		if (!find_ind(a, a->max) && a->len > 1)
			ra(a, 1);
	}
}
