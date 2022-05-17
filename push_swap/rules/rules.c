/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:10:14 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/17 17:35:16 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_stack *stack, bool can_write)
{
	int	tmp;

	if (stack->a_size >= 2)
	{
		tmp = stack->a[1];
		stack->a[1] = stack->a[0];
		stack->a[0] = tmp;
	}
	if (can_write)
		ft_putstr("sa\n", 1);
}

void	ft_ra(t_stack *stack, bool can_write)
{
	int		tmp;
	int		i;

	i = 0;
	tmp = stack->a[0];
	while (i < stack->a_size - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->a_size - 1] = tmp;
	if (can_write)
		ft_putstr("ra\n", 1);
}

void	ft_rra(t_stack *stack, bool can_write)
{
	int	tmp;
	int	i;

	i = stack->a_size - 1;
	tmp = stack->a[stack->a_size - 1];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
	if (can_write)
		ft_putstr("rra\n", 1);
}

void	ft_pa_helper(t_stack *stack, int *tmp)
{
	int	i;

	i = 0;
	while (i < stack->a_size - 1)
	{
		stack->a[i + 1] = tmp[i];
		i++;
	}
	i = 0;
	while (i < stack->b_size - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
}

void	ft_pa(t_stack *stack, bool can_write)
{
	int	*tmp;
	int	i;

	if (!(stack->b_size))
		return ;
	i = 0;
	tmp = malloc(stack->a_size * sizeof(int));
	while (i < stack->a_size)
	{
		tmp[i] = stack->a[i];
		i++;
	}
	stack->a[0] = stack->b[0];
	stack->a_size++;
	ft_pa_helper(stack, tmp);
	free (tmp);
	stack->b_size--;
	if (can_write)
		ft_putstr("pa\n", 1);
}
