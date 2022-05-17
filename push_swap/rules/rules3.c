/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:01:12 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/17 16:05:21 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_ab(t_stack *stack, bool can_write)
{
	reverse_rotate_b(stack, false);
	reverse_rotate_a(stack, false);
	if (can_write)
		ft_putstr("rrr\n", 1);
}

void	rotate_ab(t_stack *stack, bool can_write)
{
	rotate_a(stack, false);
	rotate_b(stack, false);
	if (can_write)
		ft_putstr("rr\n", 1);
}

void	swap_ab(t_stack *stack, bool can_write)
{
	swap_b(stack, false);
	swap_a(stack, false);
	if (can_write)
		ft_putstr("ss\n", 1);
}
