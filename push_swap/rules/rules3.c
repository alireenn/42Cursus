/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:01:12 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/17 17:51:52 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rrab(t_stack *stack, bool can_write)
{
	ft_rrb(stack, false);
	ft_rra(stack, false);
	if (can_write)
		ft_putstr("rrr\n", 1);
}

void	ft_rab(t_stack *stack, bool can_write)
{
	ft_ra(stack, false);
	ft_rb(stack, false);
	if (can_write)
		ft_putstr("rr\n", 1);
}

void	ft_sab(t_stack *stack, bool can_write)
{
	ft_sa(stack, false);
	ft_sb(stack, false);
	if (can_write)
		ft_putstr("ss\n", 1);
}
