/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:49:22 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/17 17:01:45 by anovelli         ###   ########.fr       */
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


