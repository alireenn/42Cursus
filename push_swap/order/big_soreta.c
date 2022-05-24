/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_soreta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:31:48 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/24 16:33:14 by anovelli         ###   ########.fr       */
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

int	ft_lis(t_stack *stack)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	stack->lis = malloc(sizeof(stack->a_size));
	while (i < stack->a_size)
	{
		stack->lis[i] = 1;
		i++;
		printf("%d\n", stack->lis[i]);
	}
	return (1);
}

 void	big_sort(t_stack *stack)
 {
	// int	i;
	// int	j;
	// int	count;

	ft_lis(stack);
	printf ("%d\n", stack->lis_num_max);
	// int	min;
	// count = 0;
	// j = 0;
	// i = 0;
	// while (j < stack->a_size)
	// {
		
	// }
}
