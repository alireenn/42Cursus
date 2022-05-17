/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:09:05 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/17 17:56:56 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int av, char **ac)
{
	t_stack	stack;

	if (av < 2)
		write(2, "Error: too few parameters.\n", 27);
	// if (av > 2)
	// 	if (check(ac) == false)
	// 		write(2, "Error\n", 6);
	stack.a_size = count_numbers(ac);
	array_fill(ac, &stack);
	choose_alg(&stack);
	for (int i = 0; i < stack.a_size; i++)
		printf("%d ", stack.a[i]);
}
