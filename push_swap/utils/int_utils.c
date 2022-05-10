/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:49:22 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/10 17:28:07 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_int(int n)
{
	if (n >= 2147483647 || n <= -2147483648)
		return (0);
	return (1);
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

void	*ft_lstnew(long long int content)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node *));
	if (!new)
		return (NULL);
	new->n = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd(t_node **lst)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node *));
	if (lst)
	{
		if (*lst)
			(*lst)->next = new;
			new->next = NULL;
	}
}

