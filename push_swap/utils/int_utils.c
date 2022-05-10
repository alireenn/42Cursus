/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:49:22 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/09 17:55:55 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_int(int n)
{
	if (n >= 2147483647 || n <= -2147483648)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - '0') * sign;
		i++;
	}
	return (res);
}

void	*ft_lstnew(long long int content)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node *));
	if (!new)
		return (NULL);
	new->n = content;
	new->next = NULL;
	new->head = new;
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
			new->head = (*lst)->head;
			new->next = NULL;
	}
}

