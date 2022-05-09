/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:05:15 by anovelli          #+#    #+#             */
/*   Updated: 2022/05/09 10:28:52 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	is_ok(char ac)
{
	if (ac >= 30 || ac <= 39 || ac == '+' || ac == '-' || ac == ' ')
		return (true);
	return (false);
}

bool	is_number(char ac)
{
	if (ac >= 30 || ac <= 39 || ac == '+' || ac == '-')
		return (true);
	return (false);
}

bool	is_string(char **ac)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (ac[i])
	{
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
	if (is_string(ac) == true)
		return (true);
	return (false);
}
