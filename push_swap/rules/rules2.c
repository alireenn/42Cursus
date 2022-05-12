/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:03:15 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/12 16:07:17 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_stacks	*stacks)
{
	t_node	*first;
	t_node	*last;

	first = stacks->a;
	last = stacks->a;
	while (last->next != NULL)
		last = last->next;
	stacks->a = last;
	stacks->a->next = first;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stacks	*stacks)
{
	t_node	*first;
	t_node	*last;

	first = stacks->b;
	last = stacks->b;
	while (last->next != NULL)
		last = last->next;
	stacks->b = last;
	stacks->b->next = first;
	write(1, "rrb\n", 4);
}

void	ft_ra(t_stacks *stacks)
{
	t_node	*first;

	first = stacks->a;
	while (stacks->a->next != NULL)
	{
		stacks->a = stacks->a->next;
	}
	stacks->a->next = first;
	write(1, "ra\n", 3);
}

void	ft_rb(t_stacks *stacks)
{
	t_node	*first;

	first = stacks->b;
	while (stacks->b->next != NULL)
	{
		stacks->b = stacks->b->next;
	}
	stacks->b->next = first;
	write(1, "rb\n", 3);
}

void	ft_rrr(t_stacks *stacks)
{
	ft_rra(stacks);
	ft_rrb(stacks);
	write(1, "rrr\n", 4);
}
