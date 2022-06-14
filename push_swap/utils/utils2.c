/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:50:27 by anovelli          #+#    #+#             */
/*   Updated: 2022/06/09 17:33:38 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	change_ind(int flag, int *moves, int len_b)
{
	if (!flag)
		(*moves)--;
	else if (flag)
	{
		(*moves)++;
		if (*moves == len_b)
			*moves = 0;
	}
}

int	ft_strlen_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	control_arg(int argc, char ***argv2, char **argv, int *i)
{
	if (argc == 2 && ft_strlen(argv[1]) > 1)
	{
		*argv2 = ft_split(argv[1], 32);
		argc = ft_strlen_matrix(*argv2);
		*i = 0;
	}
	return (argc);
}
