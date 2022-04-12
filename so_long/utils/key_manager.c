/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovelli <anovelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:58:23 by anovelli          #+#    #+#             */
/*   Updated: 2022/04/12 15:03:03 by anovelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	command(int key, t_map *map)
{
	if (key == ESC)
	{
		mlx_destroy_window(map->win.mlx, map->win.win);
		free_matrix(map->mat);
	}
	return (0);
}
