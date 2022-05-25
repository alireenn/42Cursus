/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_soreta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:31:48 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/25 14:09:28 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = __INT_MAX__ ;
	while (i < stack->a_size)
	{
		if (stack->a[i] < min)
			min = stack->a[i];
		i++;
	}
	return (min);
}

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
	for (int e = 0; e < stack->a_size; e++)
		printf("%d\n", stack->lis[e]);
	printf("ciao %d\n", stack->lis_num_max);
}

 void	big_sort(t_stack *stack)
 {
	// int	i;
	// int	j;
	// int	count;

	ft_lis(stack);

}
