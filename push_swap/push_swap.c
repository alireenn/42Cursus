/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:09:05 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/09 16:21:55 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int av, char **ac)
{
	t_stacks	*stack_a;

	stack_a = NULL;
	if (av <= 2)
		write(2, "Error: too few parameters.\n", 27);
	if (av > 2)
		if (check(ac) == false)
			write(2, "Error\n", 6);
	fill_stack(ac);
	if (stack_a->isok == 0)
		write(2, "Error\n", 6);
	sa(stack_a);
}
