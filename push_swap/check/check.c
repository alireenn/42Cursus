/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:05:15 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/24 13:00:23 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	is_ok(char ac)
{
	if ((ac >= '0' && ac <= '9') || ac == '+' || ac == '-' || ac == ' ')
		return (true);
	return (false);
}

bool	is_number(char ac)
{
	if ((ac >= '0' && ac <= '9') || ac == '+' || ac == '-')
		return (true);
	return (false);
}


bool	is_input_valid(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') &&
			(argv[i][j] != ' ' && argv[i][j] != '-' && argv[i][j] != '+'))
				return (false);
			if (j != 0 && ((argv[i][j] == '-' || argv[i][j] == '+')
				&& ((argv[i][j - 1] >= '0' && argv[i][j - 1] <= '9')
				|| (argv[i][j - 1] == '-' || argv[i][j - 1] == '+'))))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	is_string(char **ac)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (ac[i])
	{
		if (!ac[i][j])
			return (false);
		while (ac[i][j])
		{
			if (!is_ok(ac[i][j]) ||
			(ac[i][j] == ' ' && !is_number(ac[i][j + 1])))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check(char **ac)
{
	if (is_string(ac))
		return (true);
	if (is_input_valid(ac))
		return (true);
	return (false);
}
