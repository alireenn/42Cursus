/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:10:14 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/11 11:01:52 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_stacks *stack_a)
{
	t_node	*temp;
	t_node	*temp2;

	temp = stack_a->a;
	temp2 = stack_a->a->next;
	stack_a->a = temp2;
	temp->next = temp2->next;
	temp2->next = temp;
	write(1, "sa\n", 3);
}

void	ft_sb(t_stacks *stack_b)
{
	t_node	*temp;
	t_node	*temp2;

	temp = stack_b->b;
	temp2 = stack_b->b->next;
	stack_b->b = temp2;
	temp->next = temp2->next;
	temp2->next = temp;
	write(1, "sb\n", 3);
}

void	ft_ss(t_stacks *stacks)
{
	ft_sa(stacks);
	ft_sb(stacks);
}

void	ft_pa(t_stacks *stacks)
{
	t_node	*new;

	if (stacks->b != NULL)
	{
		new = malloc(sizeof(t_node));
		new = stacks->b;
		new->next = stacks->a;
	}
}

void	ft_pb(t_stacks *stacks)
{
	t_node	*new;

	if (stacks->a != NULL)
	{
		new = malloc(sizeof(t_node));
		new = stacks->a;
		new->next = stacks->b;
	}
}
