/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:49:22 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/17 16:13:55 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

bool	is_int(long long int nb)
{
	if (nb < ((__INT_MAX__ * -1) - 1) || nb > __INT_MAX__)
		return (false);
	return (true);
}

int	atoi_helper(char *str)
{
	int	sign;

	sign = 1;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	return (sign);
}

long long int	ft_atoi(const char *str)
{
	long long int	sign;
	long long int	result;
	int				count;

	count = 0;
	while (is_in_string(*(char *) str, "\t\n\v\f\r "))
		str++;
	sign = atoi_helper((char *) str);
	while (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (__LONG_MAX__);
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		if ((count > 10 && sign != -1) || (count > 11 && sign == -1))
			return (__LONG_MAX__);
		if (result * 10 < 0)
			return (-1);
		result *= 10;
		result += *str - '0';
		str++;
		count++;
	}
	return (result * sign);
}

int	count_numbers(char **argv)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (argv[i])
	{
		if (is_in_string(' ', argv[i]))
		{
			count += get_word(argv[i], ' ');
			i++;
			continue ;
		}
		i++;
		count++;
	}
	return (count);
}

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
