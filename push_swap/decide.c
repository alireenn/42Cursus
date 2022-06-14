/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:53:04 by anovelli          #+#    #+#             */
/*   Updated: 2022/06/14 10:09:26 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	decide_middle(t_stack *a, t_stack *b, int *temp, int i)
{
	temp[i] = find_place(a, b->array[i]);
	if (temp[i] <= a->len / 2 && find_ind(b, b->array[i]) <= b->len / 2)
	{
		if (temp[i] > find_ind(b, b->array[i]))
			temp[i] = temp[i] + 1;
		else
			temp[i] = find_ind(b, b->array[i]) + 1;
	}
	else if (temp[i] > a->len / 2 && find_ind(b, b->array[i]) <= b->len / 2)
		temp[i] = (a->len - temp[i]) + find_ind(b, b->array[i]);
	else if (temp[i] <= a->len / 2 && find_ind(b, b->array[i]) > b->len / 2)
		temp[i] = temp[i] + (b->len - find_ind(b, b->array[i]));
	else if (temp[i] > a->len / 2 && find_ind(b, b->array[i]) > b->len / 2)
	{
		if (temp[i] < find_ind(b, b->array[i])
			|| a->len < (a->len + b->len) / 2)
			temp[i] = b->len - find_ind(b, b->array[i]) + 1 + temp[i];
		else
			temp[i] = a->len - temp[i] + 1;
	}
}

void	decide_min(t_stack *a, t_stack *b, int *temp, int ind)
{
	int	i;
	int	i2;

	i = find_ind(a, a->min);
	i2 = find_ind(b, b->array[ind]);
	if (i > a->len / 2)
		i = a->len - i;
	if (i2 > b->len / 2)
		i2 = b->len - i2;
	if (i > i2)
		temp[ind] = i;
	else
		temp[ind] = i2;
}

void	decide_max(t_stack *a, t_stack *b, int *temp, int ind)
{
	int	i;
	int	i2;

	i = find_ind(a, a->max);
	i2 = find_ind(b, b->array[ind]);
	if (i > a->len / 2)
		i = a->len - i;
	if (i2 > b->len / 2)
		i2 = b->len - i2;
	if (i > i2)
		temp[ind] = i;
	else
		temp[ind] = i2;
}

int	decide(t_stack *a, t_stack *b)
{
	int	temp[510];
	int	i;
	int	len;

	i = 0;
	find_max_min(a);
	find_max_min(b);
	if (b->len <= 510)
		len = b->len;
	else
		len = 500;
	while (i < len)
	{
		if (b->array[i] < a->max && b->array[i] > a->min)
			decide_middle(a, b, temp, i);
		else if (b->array[i] < a->min)
			decide_min(a, b, temp, i);
		else if (b->array[i] > a->max)
			decide_max(a, b, temp, i);
		i++;
	}
	return (find_min_arr(temp, len));
}
