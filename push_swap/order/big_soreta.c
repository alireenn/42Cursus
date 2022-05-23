/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_soreta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:31:48 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/23 14:34:43 by anovelli         ###   ########.fr       */
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

 void	big_sort(t_stack *stack)
 {
	int	i;
	int	j;
	// int	min;
	j = 0;
	i = 0;
	// min = stack->a[i];
	// while (i <= stack->a_size)
	// {
	// 	min = find_min(stack);
	// 	i++;
	// }
	
}
