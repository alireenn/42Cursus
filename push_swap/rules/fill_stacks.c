/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:16:04 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/17 17:04:28 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	fill_helper(t_stack *stack, int k, char *str)
{
	int				j;
	int				count;
	char			**split;
	long long int	temp;

	split = ft_split(str, ' ');
	stack->str_nbrs++;
	j = 0;
	count = get_word(str, ' ');
	while (j < count)
	{
		temp = ft_atoi(split[j]);
		if (is_int(temp))
		{
			stack->a[k] = ft_atoi(split[j]);
			k++;
		}
		else
			stack->is_correct = false;
		j++;
	}
	free_matrix(split);
	return (k - 1);
}

void	array_fill(char **argv, t_stack *stack)
{
	int				k;
	int				i;
	long long int	temp;

	stack->a = (int *) malloc(sizeof(int) * stack->a_size);
	stack->b = (int *) malloc(sizeof(int) * stack->a_size);
	k = 0;
	i = 1;
	while (argv[i])
	{
		if (is_in_string(' ', argv[i]))
			k = fill_helper(stack, k, argv[i]);
		else
		{
			temp = ft_atoi(argv[i]);
			if (is_int(temp))
				stack->a[k] = (int) ft_atoi(argv[i]);
			else
				stack->is_correct = false;
		}
		k++;
		i++;
	}
}
