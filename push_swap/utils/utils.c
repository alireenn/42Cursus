/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:49:52 by anovelli          #+#    #+#             */
/*   Updated: 2022/06/14 10:10:14 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	err(char *str)
{
	ft_putstr_fd(str, 1);
	exit(-1);
}

int	ft_abs(int c)
{
	if (c < 0)
		return (-c);
	return (c);
}

long	ft_atol(const char *str)
{
	long	num;
	int		cont;
	long	sig;

	num = 0;
	cont = 0;
	sig = 1;
	while (str[cont] == ' ' || (str[cont] > 8 && str[cont] < 14))
		cont++;
	if (str[cont] == '-' || str[cont] == '+')
	{
		if (str[cont] == '-')
			sig *= -1;
		cont++;
	}
	if (!(str[cont] >= '0' && str[cont] <= '9'))
		return (0);
	while (str[cont] > 47 && str[cont] < 58)
	{
		num = (num * 10) + (str[cont] - 48);
		cont++;
	}
	return (num * sig);
}

void	allocate(t_stack *a, t_stack *b, int argc)
{
	a->array = ft_calloc(argc, sizeof(int));
	if (!a->array)
		err("Malloc Error\n");
	a->len = argc - 1;
	b->array = ft_calloc(argc, sizeof(int));
	if (!b->array)
		err("Malloc Error\n");
	b->len = 0;
}

int	ordered(t_stack *a)
{
	long	ret;
	int		i;

	i = 0;
	while (i < a->len)
	{
		if (i > 0 && a->array[i] < ret)
			return (0);
		ret = a->array[i++];
	}
	return (1);
}
