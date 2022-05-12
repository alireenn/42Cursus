/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:16:04 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/12 15:36:28 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_space(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_space(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

int	fill_helper(char *str, int index, t_stacks *stack_a)
{
	int		i;
	char	**split;
	int		count;
	int		temp;

	i = 0;
	split = ft_split(str, ' ');
	count = count_space(str);
	while (i < count)
	{
		temp = ft_atoi(&str[i]);
		if (is_int(temp))
			stack_a->a->n = temp;
		else
		{
			write(2, "Error\n", 6);
			stack_a->isok = 0;
		}
		i++;
		stack_a->a = stack_a->a->next;
		index++;
	}
	return (index);
}

void	fill_stack(int av, char **ac, t_stacks *stack_a)
{
	int				i;
	int				j;
	long long int	temp;
	t_node			*templist;

	i = 1;
	j = 0;
	temp = ft_atoi(ac[i]);
	stack_a->a = ft_lstnew(temp);
	templist = stack_a->a;
	while (ac[i] && stack_a->a)
	{
		if (find_space(ac[i], ' '))
			j = fill_helper(ac[i], j, stack_a);
		else
		{
			temp = ft_atoi(ac[i]);
			if (is_int((int)temp))
			{
				if (i < av - 1)
					ft_lstadd(&(stack_a->a));
				if (stack_a->a)
				stack_a->a->n = (int)temp;
			}
			j++;
		}
		stack_a->a = stack_a->a->next;
		i++;
	}
	stack_a->a = templist;
}
