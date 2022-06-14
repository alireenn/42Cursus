/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:44:39 by anovelli          #+#    #+#             */
/*   Updated: 2022/06/08 16:50:57 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	usage(t_stack *a, t_stack *b)
{
	if (a->len == 2 && !ordered(a))
		sa(a, 1);
	if (!ordered(a) && a->len < 4)
		sort_3(a);
	else if (!ordered(a) && a->len < 6)
		sort_5(a, b);
	else if (!ordered(a))
	{
		sort(a, b);
		free(a->best);
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;
	char	**argv2;

	i = 1;
	argv2 = argv;
	argc = control_arg(argc, &argv2, argv, &i);
	if (argc > 1)
	{
		allocate(&a, &b, argc);
		checks(argc, argv2, &a, i);
		usage(&a, &b);
		free(a.array);
		free(b.array);
	}
	return (0);
}
