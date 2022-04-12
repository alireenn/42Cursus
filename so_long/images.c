/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:11:10 by anovelli          #+#    #+#             */
/*   Updated: 2022/04/12 12:07:25 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_image(t_map *map)
{
	int	a;
	int	b;

	map->sfondo = mlx_xpm_file_to_image(map->win.mlx, \
			"images/sfondo.xpm", &a, &b);
	map->p.coll1 = mlx_xpm_file_to_image(map->win.mlx, \
			"images/coll1.xpm", &a, &b);
	map->p.coll2 = mlx_xpm_file_to_image(map->win.mlx, \
			"images/coll2.xpm", &a, &b);
	map->p.exit1 = mlx_xpm_file_to_image(map->win.mlx, \
			"images/exitopen.xpm", &a, &b);
	map->p.exit2 = mlx_xpm_file_to_image(map->win.mlx, \
			"images/exitclose.xpm", &a, &b);
	map->p.me1 = mlx_xpm_file_to_image(map->win.mlx, \
			"images/me.xpm", &a, &b);
	map->p.enemy1 = mlx_xpm_file_to_image(map->win.mlx, \
			"images/mecattiva1.xpm", &a, &b);
	map->p.enemy2 = mlx_xpm_file_to_image(map->win.mlx, \
			"images/mecattiva2.xpm", &a, &b);
	wall_to_screen(map);
}

void	wall_to_screen(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < (map->row + 1))
	{
		j = 0;
		while (map->mat[i][j] != '\0')
		{
			if (map->mat[i][j] == '1')
				mlx_put_image_to_window(map->win.mlx, \
					map->win.win, map->sfondo, j * 64, i * 64);
			j++;
		}
		i++;
	}
	coin_to_screen(map);
}

void	coin_to_screen(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < (map->row + 1))
	{
		j = 0;
		while (map->mat[i][j] != '\0')
		{
			if (map->mat[i][j] == 'C')
				mlx_put_image_to_window(map->win.mlx, \
					map->win.win, map->p.coll1, j * 64, i * 64);
			j++;
		}
		i++;
	}
	exit_to_screen(map);
}

void	exit_to_screen(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < (map->row + 1))
	{
		j = 0;
		while (map->mat[i][j] != '\0')
		{
			if (map->mat[i][j] == 'E')
				mlx_put_image_to_window(map->win.mlx, \
					map->win.win, map->p.exit1, j * 64, i * 64);
			j++;
		}
		i++;
	}
}
