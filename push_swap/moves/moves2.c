/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:31:07 by anovelli          #+#    #+#             */
/*   Updated: 2022/06/09 17:33:21 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *a, int to_print)
{
	int	temp;

	temp = a->array[0];
	move_up(a);
	a->array[a->len - 1] = temp;
	if (to_print)
		write(1, "ra\n", 3);
}

void	rb(t_stack *b, int to_print)
{
	int	temp;

	if (b->len > 1)
	{
		temp = b->array[0];
		move_up(b);
		b->array[b->len - 1] = temp;
		if (to_print)
			write(1, "rb\n", 3);
	}
}

void	pa(t_stack *a, t_stack *b)
{
	int	temp;

	if (b->len != 0)
	{
		temp = b->array[0];
		move_up(b);
		move_down(a);
		a->array[0] = temp;
		b->len--;
		a->len++;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	int	temp;

	if (a->len != 0)
	{
		temp = a->array[0];
		move_up(a);
		move_down(b);
		b->array[0] = temp;
		a->len--;
		b->len++;
		write(1, "pb\n", 3);
	}
}
