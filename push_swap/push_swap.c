/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:09:05 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/10 17:41:52 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int av, char **ac)
{
	t_stacks	*stack_a = NULL;
	t_stacks *temp;	
	stack_a = malloc(sizeof(t_stacks) * av); temp = stack_a;
	stack_a->isok = 1;
	if (!stack_a)
		write(2, "Error: Malloc.\n", 27);
	if (av < 2)
		write(2, "Error: too few parameters.\n", 27);
	if (av > 2)
		if (check(ac) == false)
			write(2, "Error\n", 6);
	fill_stack(ac, stack_a);

	if (stack_a->isok == 0)
		write(2, "Error\n", 6);
	ft_sa(stack_a);



	
	while(temp->a->next)
	{
		printf("%d\n", stack_a->a->n);
		temp->a = temp->a->next;
	}
}
