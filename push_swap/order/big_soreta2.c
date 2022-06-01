/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_soreta2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:58:34 by anovelli          #+#    #+#             */
/*   Updated: 2022/06/01 16:19:37 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

int	find_best_in_a(t_stack *stack, int b_pos)
{
	int	i;
	int	*a_pos;
	int	aa;

	aa = 0;
	a_pos = malloc(sizeof(int) * stack->a_size);
	i = 0;
	while (b_pos != stack->b_size)
	{
		i = 0;
		while (i != stack->a_size)
		{
			if (stack->b[b_pos] < stack->a[i] && stack->b[b_pos] > stack->a[i + 1])
				{
					a_pos[aa] = i;
					aa++;
				}
			i++;
		}
		b_pos++;
	}
	free (a_pos);
	return (*a_pos);
}

int	*find_best(t_stack *stack)
{
	int	i;
	int	j;
	int	*best;

	best = malloc(sizeof(int) * stack->b_size);
	j = 0;
	i = 0;
	while (i <= stack->b_size)
	{
		best[j] = i + find_best_in_a(stack, j);
		j++;
		i++;
	}
	free(best);
	return (best);
}

void	ft_lis4(t_stack *stack)
{
	int	*best;

	best = find_best(stack);
		for (int m = 0; m < stack->a_size; m++)
			printf("BEST	: %d\n", best[m]);
}
