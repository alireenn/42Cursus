/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:30:56 by anovelli          #+#    #+#             */
/*   Updated: 2022/06/14 10:09:50 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *a, int to_print)
{
	int	temp;

	if (a->len > 1)
	{
		temp = a->array[0];
		a->array[0] = a->array[1];
		a->array[1] = temp;
		if (to_print)
			write(1, "sa\n", 3);
	}
}

void	sb(t_stack *b, int to_print)
{
	int	temp;

	if (b->len > 1)
	{
		temp = b->array[0];
		b->array[0] = b->array[1];
		b->array[1] = temp;
		if (to_print)
			write(1, "sb\n", 3);
	}
}

void	rra(t_stack *a, int to_print)
{
	int	temp;

	temp = a->array[a->len - 1];
	move_down(a);
	a->array[0] = temp;
	if (to_print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, int to_print)
{
	int	temp;

	temp = b->array[b->len - 1];
	move_down(b);
	b->array[0] = temp;
	if (to_print)
		write(1, "rrb\n", 4);
}
