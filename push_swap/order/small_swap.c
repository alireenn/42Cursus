/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:06:50 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/19 16:31:34 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void	decrescent_algorithm(t_stack *stack)
{
	while (stack->a_size > 3)
	{
		ft_rra(stack, true);
		ft_pb(stack, true);
	}
	ft_ra(stack, true);
	ft_sa(stack, true);
	while (stack->b_size > 0)
		ft_pa(stack, true);
}

void	sort_three(t_stack *stack)
{
	if (stack->a[0] < stack->a[2] && stack->a[2] < stack->a[1])
	{
		ft_ra(stack, true);
		ft_ra(stack, true);
		ft_sa(stack, true);
	}
	else if (stack->a[1] < stack->a[0] && stack->a[0] < stack->a[2])
		ft_sa(stack, true);
	else if (stack->a[1] < stack->a[2] && stack->a[2] < stack->a[0])
		ft_ra(stack, true);
	else if (stack->a[2] < stack->a[1] && stack->a[1] < stack->a[0])
		decrescent_algorithm(stack);
	else if (stack->a[2] < stack->a[0] && stack->a[0] < stack->a[1])
		ft_rra(stack, true);
}

int	find_min_pos(t_stack *stack)
{
	int	pos;
	int	i;

	i = 1;
	pos = 0;
	while (i < stack->a_size)
	{
		if (stack->a[i] < stack->a[pos])
			pos = i;
		i++;
	}
	return (pos);
}

void	sort_five(t_stack *stack)
{
	int	i;
	
	while (stack->a_size > 3)
	{
		i = find_min_pos(stack);
		if (i < 3)
		{
			while (i-- > 0)
				ft_ra(stack, 1);
		}
		else
		{
			while (stack->a_size - i > 0)
			{
				ft_rra(stack, 1);
				i++;
			}
		}
		ft_pb(stack, 1);
	}
	sort_three(stack);
	ft_pa(stack, 1);
	ft_pa(stack, 1);
}

void	choose_alg(t_stack *stack)
{
	if (stack->a_size == 2)
	{
		if (stack->a[0] > stack->a[1])
			ft_sa(stack, true);
	}
	else if (stack->a_size == 3)
		sort_three(stack);
	else if (stack->a_size == 5)
		sort_five(stack);
	else
		big_sort(stack);
}
