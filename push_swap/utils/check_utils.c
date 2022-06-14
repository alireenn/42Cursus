/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:51:14 by anovelli          #+#    #+#             */
/*   Updated: 2022/06/14 10:10:04 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

int	check_char(char *argv)
{
	int	i;

	i = 0;
	if (argv == 0 || argv[i] == 0)
		return (0);
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]) && argv[i] != '-')
			return (0);
		i++;
	}
	return (1);
}
