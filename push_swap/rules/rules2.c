/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:03:15 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/30 15:34:25 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sb(t_stack *stack, bool can_write)
{
	int	tmp;

	if (stack->b_size >= 2)
	{
		tmp = stack->b[1];
		stack->b[1] = stack->b[0];
		stack->b[0] = tmp;
	}
	if (can_write)
		ft_putstr("sb\n", 1);
}

void	ft_rb(t_stack *stack, bool can_write)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->b[0];
	while (i < stack->b_size)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->b_size - 1] = tmp;
	if (can_write)
		ft_putstr("rb\n", 1);
}

void	ft_rrb(t_stack *stack, bool can_write)
{
	int	tmp;
	int	i;

	i = stack->b_size - 1;
	tmp = stack->b[stack->b_size - 1];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = tmp;
	if (can_write)
		ft_putstr("rrb\n", 1);
}

void	ft_pb_helper(t_stack *stack, int *tmp)
{
	int	i;

	i = 0;
	while (i < stack->b_size - 1)
	{
		stack->b[i + 1] = tmp[i];
		i++;
	}
	i = 0;
	while (i < stack->a_size - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
}

void	ft_pb(t_stack *stack, bool can_write)
{
	int	*tmp;
	int	i;

	i = 0;
	if (!(stack->a_size))
		return ;
	tmp = malloc(stack->b_size * sizeof(int));
	while (i < stack->b_size)
	{
		tmp[i] = stack->b[i];
		i++;
	}
	stack->b[0] = stack->a[0];
	stack->b_size++;
	ft_pb_helper(stack, tmp);
	free(tmp);
	stack->a_size--;
	if (can_write)
		ft_putstr("pb\n", 1);
}
