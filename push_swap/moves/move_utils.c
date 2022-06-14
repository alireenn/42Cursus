/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:23:19 by anovelli          #+#    #+#             */
/*   Updated: 2022/06/14 10:09:38 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_up(t_stack *a)
{
	int	i;

	i = 0;
	if (a->len > 0)
	{
		while (i < a->len - 1)
		{
			a->array[i] = a->array[i + 1];
			i++;
		}
	}
}

void	move_down(t_stack *a)
{
	int	i;

	if (a->len > 0)
	{
		i = a->len;
		while (i)
		{
				a->array[i] = a->array[i - 1];
				i--;
		}
		a->array[1] = a->array[0];
	}
}

void	move_b(int *ind, t_stack *b)
{
	while (*ind)
	{
		while (*ind > b->len / 2 && *ind)
		{
			rrb(b, 1);
			change_ind(1, ind, b->len);
		}
		while (*ind <= b->len / 2 && *ind != 0)
		{
			rb(b, 1);
			change_ind(0, ind, b->len);
		}
	}
}
