/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_and_chu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:44:12 by anovelli          #+#    #+#             */
/*   Updated: 2022/04/14 13:07:31 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_char(char c, t_map *map)
{
	if (c == 'E')
		map->exit++;
	else if (c == 'P')
		map->player++;
	else if (c == 'C')
		map->coll++;
}

int	is_in_string(char c, char *str)
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
			if (!is_in_string(map->mat[row][col], "10CEPN\n"))
				return (0);
			check_char(map->mat[row][col], map);
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
	while (map->mat[row])
	{
		col = 0;
		while (map->mat[row][col])
		{
			if ((row == 0 || row == map->row) && map->mat[row][col] != '1')
				return (0);
			if ((col == 0 || col == map->col - 1) && map->mat[row][col] != '1')
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

// 1 & ultima riga == 1

void	check_all(t_map *map)
{
	if (!check_map(map))
		oh_errors("La mappa contiene elementi non esistenti.\n", map, 1);
	if (!check_borders(map))
		oh_errors("La Mappa non è chiusa.\n", map, 1);
	if (map->coll < 1 || map->exit < 1 || map->player != 1)
		oh_errors("La mappa non è valida.\n", map, 1);
}
