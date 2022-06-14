/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimartin <gimartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:17:10 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/28 15:48:56 by gimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	final_response(t_stack *a, t_stack *b)
{
	int	i;
	int	last;

	i = 0;
	last = a->array[i++];
	while (i < a->len)
	{
		if (a->array[i] > last)
			last = a->array[i++];
		else
			return (0);
	}
	if (b->len != 0)
		return (0);
	return (1);
}

void	make_move(char *str, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(str, "rrr\n", 4))
		checker_rrr(a, b);
	else if (!ft_strncmp(str, "rrb\n", 4))
		checker_rrb(b);
	else if (!ft_strncmp(str, "rra\n", 4))
		checker_rra(a);
	else if (!ft_strncmp(str, "rr\n", 3))
		checker_rr(a, b);
	else if (!ft_strncmp(str, "rb\n", 3))
		checker_rb(b);
	else if (!ft_strncmp(str, "ra\n", 3))
		checker_ra(a);
	else if (!ft_strncmp(str, "pb\n", 3))
		checker_pb(a, b);
	else if (!ft_strncmp(str, "pa\n", 3))
		checker_pa(a, b);
	else if (!ft_strncmp(str, "ss\n", 3))
		checker_ss(a, b);
	else if (!ft_strncmp(str, "sb\n", 3))
		checker_sb(b);
	else if (!ft_strncmp(str, "sa\n", 3))
		checker_sa(a);
	else
		err("Error");
}

void	transform(t_stack *a, t_stack *b)
{
	char	*str;

	str = get_next_line(0);
	if (str)
	{
		while (str)
		{
			find_max_min(a);
			find_max_min(b);
			make_move(str, a, b);
			free(str);
			str = get_next_line(0);
		}
	}
	free(str);
}

int	initialize(int argc, char **argv, int i)
{
	t_stack	a;
	t_stack	b;
	int		ret;

	allocate(&a, &b, argc);
	checks(argc, argv, &a, i);
	transform(&a, &b);
	ret = final_response(&a, &b);
	return (ret);
}

int	main(int argc, char **argv)
{
	int		ret;
	char	**argv2;
	int		i;

	i = 1;
	argv2 = argv;
	argc = control_arg(argc, &argv2, argv, &i);
	if (argc > 1)
	{
		ret = initialize(argc, argv, i);
		if (ret)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	return (0);
}
