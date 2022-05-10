/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:10:14 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/10 17:58:46 by anovelli         ###   ########.fr       */
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
	temp2->next = temp; //qua
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
	temp2->next = temp; //qua
	write(1, "sb\n", 3);
}


