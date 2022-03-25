/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_and_chu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:44:12 by anovelli          #+#    #+#             */
/*   Updated: 2022/03/25 18:13:16 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_in_strings(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	check_map(t_map *map)
{
	int	col;
	int	row;

	row = 0;
	while (map->mat[row])
	{	
		col = 0;
		while (map->mat[row][col])
		{	
			if (!is_in_strings(map->mat[row][col], "10CEPN\n"))
				return (0);
			col++;
		}
		if (row == 0)
			map->col = col;
		if (col != map->col)
			return (0);
		row++;
	}
	map->row = row - 1;
	return (1);
}

int	check_borders(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (map->mat[row])
	{
		while (map->mat[row][col])
		{
			if ((row == 0 || row == map->row) && map->mat[row] != '1')
				return (0);
			if ((col == 0 || col == map->col) && map->mat[col][row] != '1')
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}
