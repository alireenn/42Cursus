/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:06:50 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/17 16:14:57 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void	decrescent_algorithm(t_stack *stack)
{
	while (stack->a_size > 3)
	{
		reverse_rotate_a(stack, true);
		push_b(stack, true);
	}
	rotate_a(stack, true);
	swap_a(stack, true);
	while (stack->b_size > 0)
		push_a(stack, true);
}

void	sort_three(t_stack *stack)
{
	if (stack->a[0] < stack->a[2] && stack->a[2] < stack->a[1])
	{
		rotate_a(stack, true);
		rotate_a(stack, true);
		swap_a(stack, true);
	}
	else if (stack->a[1] < stack->a[0] && stack->a[0] < stack->a[2])
		swap_a(stack, true);
	else if (stack->a[1] < stack->a[2] && stack->a[2] < stack->a[0])
		rotate_a(stack, true);
	else if (stack->a[2] < stack->a[1] && stack->a[1] < stack->a[0])
		decrescent_algorithm(stack);
	else if (stack->a[2] < stack->a[0] && stack->a[0] < stack->a[1])
		reverse_rotate_a(stack, true);
}
