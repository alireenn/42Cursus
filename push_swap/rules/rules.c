/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:10:14 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/10 09:18:54 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stacks *stack_a)
{
	printf("ciao1");
	t_node	*temp;

	temp = stack_a->a;
	temp->next = (stack_a->a->next)->next;
	stack_a->a = stack_a->a->next;
	stack_a->a->next = temp;

	temp = stack_a->a;
	while (stack_a)
	{
		stack_a->a->head = temp;
		stack_a->a = stack_a->a->next;
	}
}


