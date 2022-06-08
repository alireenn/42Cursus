/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_soreta2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:58:34 by anovelli          #+#    #+#             */
/*   Updated: 2022/06/07 14:55:09 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	find_best_in_a(t_stack *stack, int b_pos)
{
	int	i;
	
	i = 0;
	while (i != stack->a_size)
	{
		if (stack->b[b_pos] > stack->a[i] && stack->b[b_pos] < stack->a[i + 1])
			return (i + 1);
		i++;
	}
	return (i + 1);
}

int	find_best(t_stack *stack, int b_pos)
{
	int	i;
	int	best;

	i = 0;
	best = b_pos  + 1 + find_best_in_a(stack, b_pos);
	return (best);
}

void	ft_lis4(t_stack *stack)
{
	int	*best;
	int	i;

	best = malloc(sizeof(int) * stack->b_size);
	i = 0;
	while (i <= stack->b_size)
	{
		best[i] = find_best(stack, i);
		i++;
	}
		for (int m = 0; m < stack->a_size; m++)
			printf("BEST	: %d\n", best[m]);
}
