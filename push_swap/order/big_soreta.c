/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_soreta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:31:48 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/30 12:59:45 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lis(t_stack *stack)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	stack->lis_num_max = 1;
	stack->lis = (int *) malloc(sizeof(int) * stack->a_size);
	while (++i != stack->a_size)
		stack->lis[i] = 1;
	while (j != stack->a_size)
	{
		i = j;
		while (i != stack->a_size)
		{
			if (stack->a[j] < stack->a[i] && stack->lis[j] == stack->lis[i])
			{
				stack->lis[i] += 1;
				if (stack->lis[i] > stack->lis_num_max)
					stack->lis_num_max = stack->lis[i];
			}
			i++;
		}
		j++;
	}	
}

void	ft_lis2(t_stack *stack)
{
	int	find;
	int	i;

	i = 0;
	find = 1;
	while (stack->lis[i])
	{
		if (stack->lis[i] == find)
		{
			stack->lis[i] = 1;
			find++;
		}
		else
			stack->lis[i] = 0;
		i++;
	}
}

int	ft_lis3(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < stack->a_size)
	{
		if (stack->lis[i] == 0)
		{
			stack->b[j] = stack->a[i];
			stack->a[i] = 0;
			j++;
		}
		i++;
	}
	return (j);
}

void	big_sort(t_stack *stack)
{
	int	b_last_index;

	ft_lis(stack);
	ft_lis2(stack);
		for (int b = 0; b < stack->a_size; b++)
				printf("dopo: %d\n", stack->lis[b]);
	b_last_index = ft_lis3(stack);
		for (int m = 0; m < stack->a_size; m++)
			printf("a: %d			b: %d\n", stack->a[m], stack->b[m]);
	ft_lis4(stack, b_last_index);
 }
