/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:09:05 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/10 09:22:06 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int av, char **ac)
{
	t_stacks	*stack_a;

	stack_a = malloc(sizeof(t_stacks));
	stack_a->isok = 1;
	if (!stack_a)
		write(2, "Error: Malloc.\n", 27);
	if (av <= 2)
		write(2, "Error: too few parameters.\n", 27);
	if (av > 2)
		if (check(ac) == false)
			write(2, "Error\n", 6);
	fill_stack(ac, stack_a);
	if (stack_a->isok == 0)
		write(2, "Error\n", 6);
	sa(stack_a);
}
