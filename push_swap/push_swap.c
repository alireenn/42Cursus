/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:09:05 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/12 16:06:59 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int av, char **ac)
{
	t_stacks	*stack_a;
	t_stacks	*temp;	

	stack_a = malloc(sizeof(t_stacks) * av);
	stack_a->isok = 1;
	if (!stack_a)
		write(2, "Error: Malloc.\n", 27);
	if (av < 2)
		write(2, "Error: too few parameters.\n", 27);
	if (av > 2)
		if (check(ac) == false)
			write(2, "Error\n", 6);
	fill_stack(av, ac, stack_a);
	if (stack_a->isok == 0)
		write(2, "Error\n", 6);
	// ft_sa(stack_a);
	// ft_ss(stack_a);		//SE LI FACCIO INSIEME VA IN SEGFAOULT
	// ft_ra(stack_a);
	temp = stack_a;

	printf("1 - %d\n", temp->a->n);
	printf("2 - %d\n", temp->a->next->n);
	printf("3 - %d\n", temp->a->next->next->n);
	printf("4 - %d\n", temp->a->next->next->next->n);
}
