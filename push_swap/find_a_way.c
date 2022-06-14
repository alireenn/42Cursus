/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_a_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 14:33:05 by anovelli          #+#    #+#             */
/*   Updated: 2022/06/08 16:50:56 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_n(int len, t_best_elem *n, int *arr)
{
	int	i;

	i = 0;
	if (n == NULL)
		write(1, "?\n", 2);
	while (i < len)
	{
		n[i].val = arr[i];
		i++;
	}
}

void	create_p(int len, t_best_elem *n, t_best_elem *p)
{
	int	i;

	i = len;
	while (i)
	{
		p = n + i;
		while (p++ < n + len)
		{
			if (p->val > n[i].val && p->len >= n[i].len)
			{
				n[i].next = p;
				n[i].len = p->len + 1;
			}
		}
		i--;
	}
	p = n;
	while (i < len)
	{
		if (n[i].len > p->len)
			p = n + 1;
		i++;
	}
}

void	allocate_lists(t_best_elem **n, t_best_elem **p, int len)
{
	*n = ft_calloc(len, sizeof(t_best_elem));
	if (!*n)
		err("Malloc error");
	*p = ft_calloc(len, sizeof(t_best_elem));
	if (!*p)
		err("Malloc error");
}

void	get_lis(int *array, int len, t_stack *a)
{
	int			i;
	t_best_elem	*p;
	t_best_elem	*n;

	p = NULL;
	n = NULL;
	allocate_lists(&n, &p, len);
	create_n(len, n, array);
	create_p(len, n, p);
	i = 0;
	a->best = ft_calloc(a->len, (sizeof(int)));
	if (!a->best)
		err("Malloc error\n");
	a->best[i++] = p->val;
	while (p->next)
	{
		a->best[i++] = p->val;
		p = p->next;
	}
	a->best[i++] = p->val;
	a->best_len = i;
	free(n);
	free(p);
}
