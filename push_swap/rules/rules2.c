/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:03:15 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/11 12:20:26 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//ra (rotate a): Shift up all elements of stack a by 1.
//The first element becomes the last one.

void	ft_ra(t_stacks	*stacks)
{
	t_stacks	*first;
	t_stacks	*last;

	//temp = ft_lstnew(0);
	first= stacks->a;
	last = stacks->a;
	printf("ciao\n");
	while (last->a->next != NULL)
		first->a = first->a->next;
		last = 
	stacks->a->next = temp;
	//stacks->a->n = 10;
	//stacks->a->next->next = NULL;
	temp->next = NULL;
}