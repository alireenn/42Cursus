/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_soreta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:31:48 by anovelli          #+#    #+#             */
/*   Updated: 2022/06/01 13:02:42 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lis(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	stack->lis_num_max = 0;
	stack->lis = malloc(stack->a_size * sizeof(int));
	while (i < stack->a_size)
		stack->lis[i++] = 1;
	while (j < stack->a_size)
	{
		i = j;
		while (i < stack->a_size)
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

	i = stack->a_size;
	find = stack->lis_num_max;
	printf("find :%d \n", find);
	while (i >= 0)
	{
		if (stack->lis[i] == find)
		{
			stack->lis[i] = 1;
			find--;
		}
		else
			stack->lis[i] = 0;
		i--;
	}
}

void	ft_lis3(t_stack *stack)
{
	int	i;
	int	temp_a_size;

	temp_a_size = stack->a_size;
	i = 0;
	while(i <= temp_a_size - 1)
	{
		if (stack->lis[i] == 1)
			ft_ra(stack, true);
		else
			ft_pb(stack, true);
		i++;
	}
}

void	big_sort(t_stack *stack)
{
	ft_lis(stack);
	for (int m = 0; m < stack->a_size; m++)
			printf("lis: %d\n", stack->lis[m]);
	ft_lis2(stack);
			for (int m = 0; m < stack->a_size; m++)
			printf("lis2: %d\n", stack->lis[m]);
	ft_lis3(stack);
		for (int m = 0; m < stack->a_size; m++)
			printf("a: %d\n", stack->a[m]);
					for (int m = 0; m < stack->b_size; m++)
			printf("		b: %d\n", stack->b[m]);
	// ft_lis4(stack);
 }
