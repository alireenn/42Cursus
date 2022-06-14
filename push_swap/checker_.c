/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:16:47 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/25 16:54:26 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_sa(t_stack *a)
{
	int	tmp;

	if (a->len > 1)
	{
		tmp = a->array[0];
		a->array[0] = a->array[1];
		a->array[1] = tmp;
	}
}

void	checker_sb(t_stack *b)
{
	int	tmp;

	if (b->len > 1)
	{
		tmp = b->array[0];
		b->array[0] = b->array[1];
		b->array[1] = tmp;
	}
}

void	checker_ss(t_stack *a, t_stack *b)
{
	checker_sa(a);
	checker_sb(b);
}

void	checker_pa(t_stack *a, t_stack *b)
{
	int	tmp;

	if (b->len != 0)
	{
		tmp = b->array[0];
		move_up(b);
		move_down(a);
		a->array[0] = tmp;
		b->len--;
		a->len++;
	}
}

void	checker_pb(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->len != 0)
	{
		tmp = a->array[0];
		move_up(a);
		move_down(b);
		b->array[0] = tmp;
		a->len--;
		b->len++;
	}
}
