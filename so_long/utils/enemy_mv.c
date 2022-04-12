/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_mv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:55:27 by anovelli          #+#    #+#             */
/*   Updated: 2022/04/12 14:54:53 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	enemy_set_image(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < (map->row + 1))
	{
		j = 0;
		while (map->mat[i][j] != '\0')
		{
			if (map->mat[i][j] == 'N' && map->enemy_mv == 0)
				mlx_put_image_to_window(map->win.mlx, \
					map->win.win, map->p.enemy1, j * 64, i * 64);
			else if (map->mat[i][j] == 'N' && map->enemy_mv == 1)
				mlx_put_image_to_window(map->win.mlx, \
					map->win.win, map->p.enemy2, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

int	enemy_delay(t_map *map, int time)
{
	while (map->delay < time)
	{
		map->delay++;
		return (0);
	}
	map->delay = 0;
	return (1);
}

void	enemy_loop(t_map *m)
{
	if (!enemy_delay(m, 3500))
		return ;
	if (m->enemy_mv == 1)
	{
		enemy_set_image(m);
		m->enemy_mv = 0;
	}
	else
	{
		enemy_set_image(m);
		m->enemy_mv = 1;
	}
}

int	animation(t_map *map)
{
	enemy_loop(map);
	return (0);
}
